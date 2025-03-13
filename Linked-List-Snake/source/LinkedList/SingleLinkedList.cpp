#include "../../include/LinkedList/SingleLinkedList.h"

namespace LinkedList
{
    
    SingleLinkedList::SingleLinkedList()
    {
        head_node = nullptr;
    }

    SingleLinkedList::~SingleLinkedList() = default;

    void SingleLinkedList::initialize(float width, float height, Vector2i position, Direction direction)
    {
        node_width = width;
        node_height = height;
        default_position = position;
        default_direction = direction;
        linked_list_size = 0;
    }
    void SingleLinkedList::render()
    {
        Node* current_node = head_node;

        while (current_node->next != nullptr)
        {
            current_node->body_part.render();
            current_node = current_node->next;
        }
    }

    void SingleLinkedList::initializeNode(Node* new_node, Node* reference_node, Operation operation)
    {
        if (reference_node == nullptr)
        {
            new_node->body_part.initialize(node_width, node_height, default_position, default_direction);
            return;
        }

        Vector2i new_position = getNewNodePosition(reference_node, operation);

        new_node->body_part.initialize(node_width,node_height,new_position,reference_node->body_part.getDirection());
    }

    Node* SingleLinkedList::createNode()
    {
        return new Node();
    }

    Vector2i SingleLinkedList::getNewNodePosition(Node* reference,Operation operation)
    {
       /* Direction reference_direction = reference->body_part.getDirection();
        Vector2i reference_position = reference->body_part.getPosition();

        switch (reference_direction)
        {
        case Direction::UP:
            return Vector2i(reference_position.x,reference_position.y+1);

        case Direction::DOWN:
            return Vector2i(reference_position.x,reference_position.y-1);

        case Direction::LEFT:
            return Vector2i(reference_position.x+1,reference_position.y);

        case Direction::RIGHT:
            return Vector2i(reference_position.x-1,reference_position.y);

        
        }*/


        switch (operation)
        {
        case LinkedList::Operation::HEAD:
           return reference->body_part.getNextPosition();
          
        case LinkedList::Operation::TAIL:
            return reference->body_part.getPreviousPosition();
        }
        return default_position;
    }

    void SingleLinkedList::insertNodeAtTail()
    {
        linked_list_size++;
        Node* new_node = createNode();
        Node* current_node = head_node;

        if (current_node == nullptr)
        {
            head_node = new_node;
            initializeNode(new_node, current_node, Operation::TAIL);
            return;
        }

        while (current_node->next != nullptr)
        {
            current_node = current_node->next;
        }

        initializeNode(new_node, current_node, Operation::TAIL);
        current_node->next = new_node;
    }

    void SingleLinkedList::insertNodeAtHead()
    {
        linked_list_size++;
        Node* new_node = createNode();
        Node* reference_node = head_node;

        if (reference_node == nullptr)
        {
           initializeNode(new_node,reference_node,Operation::HEAD);
            head_node = new_node;
            return;
        }

        initializeNode(new_node, reference_node, Operation::HEAD);
        new_node->next = head_node;
        head_node = new_node;
    }

    void SingleLinkedList::insertNodeAtIndex(int index)
    {
        if (index < 0 || index>=linked_list_size) return;

        if(index==0)
        {
            insertNodeAtHead();
            return;
        }

       /* Node* new_node = createNode();
        Node* current_node = head_node;

        while (current_node !=  nullptr && index>0)
        {
            current_node = current_node->next;
            index--;
        }

        new_node->next = current_node->next;
        current_node->next = new_node;
        initialize(node_width, node_height, current_node->body_part.getPreviousPosition(), current_node->body_part.getDirection());
        linked_list_size++;*/

        int current_index = 0;
        Node* new_node = createNode();
        Node* current_node = head_node;
        Node* previous_node = nullptr;

        while (current_node != nullptr && current_index < index)
        {
            previous_node = current_node;
            current_node = current_node->next;
            current_index++;
        }

        previous_node->next = new_node;
        new_node->next = current_node;
        initializeNode(new_node,previous_node,Operation::TAIL);

        shiftNodeAfterInsertion(new_node, current_node, previous_node);
        linked_list_size++;
    }

    void SingleLinkedList::insertNodeAtMiddle()
    {
        Node* new_node = createNode();
        Node* current_node = head_node;

        if (current_node == nullptr)
        {
            insertNodeAtHead();
            return;
        }

        int middle_index = findMiddleIndex();
        insertNodeAtIndex(middle_index);
    }

    void SingleLinkedList::insertNodeAt(int index)
    {
        if (index < 0 && index >= linked_list_size)
        {
            return;
        }

        insertNodeAtIndex(index);
    }

    void SingleLinkedList::shiftNodeAfterInsertion(Node* new_node, Node* current_node, Node* previous_node)
    {
        Node* next_node = current_node;
        current_node = new_node;

        while (current_node!=nullptr && next_node!=nullptr)
        {
            current_node->body_part.setPosition(next_node->body_part.getPosition());
            current_node->body_part.setDirection(next_node->body_part.getDirection());

            previous_node->next = current_node;
            current_node->next = next_node;
            next_node->next = next_node->next;
        }

        initializeNode(current_node,previous_node,Operation::TAIL);
    }

    void SingleLinkedList::shiftNodesAfterRemoval(Node* cur_node)
    {
        if (cur_node == nullptr)
            return;
        Node* previous_node = cur_node;
        cur_node = cur_node->next;

        Vector2i previous_position;
        Direction previous_direction;

        while (cur_node != nullptr)
        {
            previous_position = previous_node->body_part.getPosition();
            previous_direction = previous_node->body_part.getDirection();

            cur_node->body_part.setPosition(previous_position);
            cur_node->body_part.setDirection(previous_direction);

            previous_node = cur_node;
            cur_node = cur_node->next;
        }
    }

    void SingleLinkedList::removeNodeAtIndex(int index)
    {
        int current_index = 0;
        Node* current_node = head_node;
        Node* previous_node = nullptr;

        while (current_node != nullptr && current_index <= index)
        {
            previous_node = current_node;
            current_node = current_node->next;
            current_index++;
        }
        
        previous_node->next = current_node->next;
        shiftNodesAfterRemoval(current_node);
        delete(current_node);
        linked_list_size--;
    }

    void SingleLinkedList::removeNodeAt(int index)
    {
        if (index < 0 && index >= linked_list_size)
        {
            return;
        }
        removeNodeAtIndex(index);
    }

    void SingleLinkedList::removeNodeAtMiddle()
    {
        if (head_node == nullptr)
        {
            return;
        }

        int index = findMiddleIndex();

        removeNodeAtIndex(index);
    }

    void SingleLinkedList::removeNodeAtTail()
    {
        if (head_node == nullptr)
        {
            return;
        }
            linked_list_size--;

        if (head_node->next == nullptr)
        {
            removeNodeAtHead();
            return;
        }

        Node* previous_node = nullptr;
        Node* currentNode = head_node;

        while (currentNode != nullptr)
        {
            previous_node = currentNode;
            currentNode = currentNode->next;
        }

        previous_node->next = nullptr;
        currentNode->next = nullptr;
        delete(currentNode);

    }

    Node* SingleLinkedList::findNodeAtIndex(int index)
    {
        int current_index = 0;
        Node* current_node = head_node;

        if (current_node == nullptr) return nullptr;

        while (current_node != nullptr && current_index < index)
        {
            current_node = current_node->next;
            current_index++;
        }
        return current_node;
    }

    void SingleLinkedList::removeHalfNodes()
    {
        if (linked_list_size <= 1) return;
        int half_length = linked_list_size / 2;
        int new_tail_index = half_length - 1;

        Node* previous_node = findNodeAtIndex(new_tail_index);
        Node* current_node = previous_node->next;
        previous_node->next = nullptr;

        while (current_node != nullptr)
        {
            Node* node_to_delete = current_node;
            current_node = current_node->next;

            node_to_delete->next = nullptr;
            delete(node_to_delete);
            linked_list_size--;
        }
    }

    Direction SingleLinkedList::reverse()
    {
        Node* current_node = head_node;
        Node* previous_node = nullptr;
        Node* next_node = nullptr;

        while (current_node != nullptr)
        {
            next_node = current_node->next;
            current_node->next = previous_node;
            reverseNodeDirection();
            previous_node = current_node;
            current_node = next_node;
        }

        head_node = previous_node;
        reverseNodeDirection();

        return head_node->body_part.getDirection();
    }

    void SingleLinkedList::reverseNodeDirection()
    {
        Node* current_node = head_node;

        while (current_node!=nullptr)
        {
            Direction previous_direction = current_node->body_part.getPreviousDirection();
            current_node->body_part.setDirection(getReverseDirection(previous_direction));
            current_node = current_node->next;
        }
    }

    Direction SingleLinkedList::getReverseDirection(Direction reference_direction)
    {
        switch (reference_direction)
        {
        case Direction::UP:
            return Direction::DOWN;

        case Direction::DOWN:
            return Direction::UP;

        case Direction::LEFT:
            return Direction::RIGHT;

        case Direction::RIGHT:
            return Direction::LEFT;
        }
    }

    int SingleLinkedList::findMiddleIndex()
    {
        int current_index = 0;

        Node* slow_node = head_node;
        Node* fast_Node = head_node;

        while (fast_Node != nullptr && fast_Node->next != nullptr)
        {
            slow_node = slow_node->next;
            fast_Node = fast_Node->next->next;
            current_index++;
        }

        return current_index;
    }

    void SingleLinkedList::updateNodeDirection(Direction direction_to_set)
    {
        Node* current_node = head_node;

        while (current_node != nullptr)
        {
            Direction previous_direction = current_node->body_part.getDirection();

            current_node->body_part.setDirection(direction_to_set);
            direction_to_set = previous_direction;
            current_node = current_node->next;

        }
    }

    void SingleLinkedList::updateNodePosition()
    {
        Node* current_node = head_node;

        while (current_node!=nullptr)
        {

            current_node->body_part.setPosition(current_node->body_part.getNextPosition());//to be added
            current_node->body_part.updatePosition();
            current_node = current_node->next;
        }
    }

    bool SingleLinkedList::processNodeCollision()
    {

        if (head_node == nullptr) return false;

        Vector2i predicted_position = head_node->body_part.getNextPosition();

        Node* current_node = head_node->next;

        while (current_node != nullptr)
        {
            if (current_node->body_part.getNextPosition() == predicted_position)
            {
                return true;
            }
            current_node = current_node->next;
        }

        return false;
    }


    void SingleLinkedList::removeAllHeadNode()
    {
        if (head_node == nullptr) return;

        while (head_node!=nullptr)
        {
            removeNodeAtHead();
        }
        
    }

    void SingleLinkedList::removeNodeAtHead()
    {
        Node* current_node = head_node;
        head_node = head_node->next;
        current_node->next = nullptr;
        delete(current_node);
        linked_list_size--;
    }

    vector<Vector2i> SingleLinkedList::getNodePositionList()
    {
        vector<Vector2i> node_Positons_list;

        Node* current_node = head_node;

        while (current_node != nullptr)
        {
            node_Positons_list.push_back(current_node->body_part.getPosition());
            current_node = current_node->next;
        }


        return node_Positons_list;
    }

    Node* SingleLinkedList::getHead()
    {
        return head_node;
    }



}
