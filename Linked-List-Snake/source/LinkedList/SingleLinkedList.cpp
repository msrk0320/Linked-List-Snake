#include "../../include/LinkedList/Node.h"
#include "../../include/LinkedList/SingleLinkedList.h"
#include <iostream>

namespace LinkedList {

	// Private methods
	Node* SingleLinkedList::createNode() {
		return new Node();
	}

	void SingleLinkedList::destroy() {
		// Implementation for destroy if needed
	}

	void SingleLinkedList::shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node) {
		Node* next_node = cur_node;
		cur_node = new_node;

		while (cur_node != nullptr && next_node != nullptr) {
			cur_node->body_part.setPosition(next_node->body_part.getPosition());
			cur_node->body_part.setDirection(next_node->body_part.getDirection());

			prev_node = cur_node;
			cur_node = next_node;
			next_node = next_node->next;
		}

		initializeNode(cur_node, prev_node, Operation::TAIL);
	}

	void SingleLinkedList::shiftNodesAfterRemoval(Node* cur_node) {
		Node* prev_node = cur_node;
		cur_node = cur_node->next;

		while (cur_node != nullptr && prev_node != nullptr) {
			cur_node->body_part.setPosition(prev_node->body_part.getPosition());
			cur_node->body_part.setDirection(prev_node->body_part.getDirection());

			cur_node = prev_node;
			prev_node = prev_node->next;
		}
	}

	// Constructor and Destructor
	SingleLinkedList::SingleLinkedList() {
		head_node = nullptr;
	}

	SingleLinkedList::~SingleLinkedList() = default;

	// Initialization methods
	void SingleLinkedList::initialize(float width, float height, sf::Vector2i position, Direction direction) {
		node_width = width;
		node_height = height;
		default_position = position;
		default_direction = direction;
		linked_list_size = 0;
	}

	void SingleLinkedList::initializeNode(Node* new_node, Node* reference_node, Operation operation) {
		if (reference_node == nullptr) {
			new_node->body_part.initialize(node_width, node_height, default_position, default_direction);
			return;
		}

		sf::Vector2i position = getNewNodePosition(reference_node, operation);
		new_node->body_part.initialize(node_width, node_height, position, reference_node->body_part.getDirection());
	}

	// Rendering methods
	void SingleLinkedList::render() {
		Node* cur_node = head_node;

		while (cur_node != nullptr) {
			cur_node->body_part.render();
			cur_node = cur_node->next;
		}
	}

	// Update methods
	void SingleLinkedList::updateNodeDirection(Direction direction_to_set) {
		Node* cur_node = head_node;

		while (cur_node != nullptr) {
			Direction previous_direction = cur_node->body_part.getDirection();
			cur_node->body_part.setDirection(direction_to_set);
			direction_to_set = previous_direction;
			cur_node = cur_node->next;
		}
	}

	void SingleLinkedList::updateNodePosition() {
		Node* cur_node = head_node;
		while (cur_node != nullptr) {
			cur_node->body_part.setPosition(cur_node->body_part.getNextPosition());
			cur_node->body_part.updatePosition();
			cur_node = cur_node->next;
		}
	}

	Direction SingleLinkedList::reverse()
	{
		Node* cur_node = head_node;
		Node* prev_node = nullptr;
		Node* next_node = nullptr;

		while (cur_node != nullptr)
		{
			next_node = cur_node->next;
			cur_node->next = prev_node;

			prev_node = cur_node;
			cur_node = next_node;
		}

		head_node = prev_node;
		reverseNodeDirections();
		return head_node->body_part.getDirection();
	}



	Direction SingleLinkedList::getReverseDirection(Direction reference_direction)
	{
		switch (reference_direction)
		{
		case Direction::UP:
			return Direction::DOWN;
			break;
		case Direction::DOWN:
			return Direction::UP;
			break;
		case Direction::LEFT:
			return Direction::RIGHT;
			break;
		case Direction::RIGHT:
			return Direction::LEFT;
			break;
		}
	}

	void SingleLinkedList::reverseNodeDirections()
	{
		Node* curr_node = head_node;

		while (curr_node != nullptr)
		{
			curr_node->body_part.setDirection(getReverseDirection(curr_node->body_part.getPreviousDirection()));
			curr_node = curr_node->next;
		}
	}

	// Insertion methods
	void SingleLinkedList::insertNodeAtHead() {
		linked_list_size++;
		Node* new_node = createNode();

		if (head_node == nullptr) {
			head_node = new_node;
			initializeNode(new_node, nullptr, Operation::HEAD);
			return;
		}

		initializeNode(new_node, head_node, Operation::HEAD);
		new_node->next = head_node;
		head_node = new_node;
	}

	void SingleLinkedList::insertNodeAtIndex(int index) {
		if (index < 0 || index >= linked_list_size) return;

		if (index == 0) {
			insertNodeAtHead();
			return;
		}

		Node* new_node = createNode();
		int current_index = 0;
		Node* cur_node = head_node;
		Node* prev_node = nullptr;

		while (cur_node != nullptr && current_index < index) {
			prev_node = cur_node;
			cur_node = cur_node->next;
			current_index++;
		}

		prev_node->next = new_node;
		new_node->next = cur_node;
		//initializeNode(new_node, prev_node, Operation::TAIL);
		linked_list_size++;
		shiftNodesAfterInsertion(new_node, cur_node, prev_node);
	}

	void SingleLinkedList::insertNodeAtMiddle() {
		if (head_node == nullptr) {
			insertNodeAtHead();
			return;
		}

		int midIndex = findMiddleNode();
		insertNodeAtIndex(midIndex);
	}

	void SingleLinkedList::insertNodeAt(int index) {
		if (index<0 &&index >= linked_list_size) return;

		insertNodeAtIndex(index);
	}

	void SingleLinkedList::insertNodeAtTail() {
		linked_list_size++;
		Node* new_node = createNode();
		Node* cur_node = head_node;

		if (cur_node == nullptr) {
			head_node = new_node;
			initializeNode(new_node, cur_node, Operation::TAIL);
			return;
		}

		while (cur_node->next != nullptr) {
			cur_node = cur_node->next;
		}

		initializeNode(new_node, cur_node, Operation::TAIL);
		cur_node->next = new_node;
	}

	// Removal methods
	void SingleLinkedList::removeNodeAtHead() {
		Node* cur_node = head_node;
		head_node = head_node->next;

		cur_node->next = nullptr;
		delete cur_node;

		linked_list_size--;
	}

	void SingleLinkedList::removeNodeAtIndex(int index) {
		int currentIndex = 0;
		Node* cur_node = head_node;
		Node* prev_node = nullptr;

		while (cur_node != nullptr && currentIndex <= index) {
			prev_node = cur_node;
			cur_node = cur_node->next;
			currentIndex++;
		}

		if (cur_node != nullptr)
			prev_node->next = cur_node->next;
		shiftNodesAfterRemoval(cur_node);
		linked_list_size--;
		delete cur_node;
	}

	void SingleLinkedList::removeNodeAt(int index) {
		if (index<0 && index >/*=*/ linked_list_size) return;

		removeNodeAtIndex(index);
	}

	void SingleLinkedList::removeNodeAtMiddle() {
		if (linked_list_size == 0) return;

		int midIndex = findMiddleNode();
		removeNodeAtIndex(midIndex);
	}

	void SingleLinkedList::removeNodeAtTail() {
		if (head_node == nullptr) return;

		if (linked_list_size == 1) {
			removeNodeAtHead();
			return;
		}
		Node* cur_node = head_node;
		while (cur_node->next->next != nullptr) {
			cur_node = cur_node->next;
		}
		linked_list_size--;
		cur_node->next = nullptr;
		delete cur_node->next;
	}

	void SingleLinkedList::removeHalfNodes() {
		if (head_node == nullptr)
			return;

		int midIndex = findMiddleNode();
		Node* prev_node = findNodeAtIndex(midIndex);
		Node* cur_node = prev_node->next;

		while (cur_node != nullptr) {
			Node* node_to_delete = cur_node;
			cur_node = cur_node->next;

			delete node_to_delete;
			linked_list_size--;
		}

		prev_node->next = nullptr;
	}

	void SingleLinkedList::removeAllNodes() {
		if (head_node == nullptr) return;

		while (head_node != nullptr) {
			removeNodeAtHead();
		}
	}

	// Utility methods
	int SingleLinkedList::findMiddleNode() {
		Node* slow = head_node;
		Node* fast = head_node;
		int midIndex = 0;

		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			midIndex++;
		}

		return midIndex;
	}

	bool SingleLinkedList::processNodeCollision() {
		if (head_node == nullptr) return false;

		sf::Vector2i predicted_position = head_node->body_part.getPosition();
		Node* cur_node = head_node->next;

		while (cur_node != nullptr) {
			if (cur_node->body_part.getPosition() == predicted_position) return true;
			cur_node = cur_node->next;
		}

		return false;
	}

	std::vector<sf::Vector2i> SingleLinkedList::getNodesPositionList() {
		std::vector<sf::Vector2i> nodes_position_list;
		Node* cur_node = head_node;

		while (cur_node != nullptr) {
			nodes_position_list.push_back(cur_node->body_part.getPosition());
			cur_node = cur_node->next;
		}

		return nodes_position_list;
	}

	sf::Vector2i SingleLinkedList::getNewNodePosition(Node* reference_node, Operation operation) {
		switch (operation) {
		case LinkedList::Operation::HEAD:
			return reference_node->body_part.getNextPosition();
		case LinkedList::Operation::MID:
			// Implementation for MID if needed
			break;
		case LinkedList::Operation::TAIL:
			return reference_node->body_part.getPrevPosition();
		default:
			break;
		}
		return default_position; // Default return if no case matches
		
		
		// Extract direction and position for new node calculation
		//Direction reference_direction = reference_node->body_part.getDirection();
		//sf::Vector2i reference_position = reference_node->body_part.getPosition();

		//// Calculate new position based on reference node's direction
		//switch (reference_direction)
		//{
		//case Direction::UP:
		//	return sf::Vector2i(reference_position.x, reference_position.y - 1);     //Decreases the y-coordinate by 1 (moves up)
		//	break;
		//case Direction::DOWN:
		//	return sf::Vector2i(reference_position.x, reference_position.y + 1);     //Increases the y-coordinate by 1 (moves down)
		//	break;
		//case Direction::LEFT:
		//	return sf::Vector2i(reference_position.x + 1, reference_position.y);    //Increases the x-coordinate by 1 (moves left).
		//	break;
		//case Direction::RIGHT:
		//	return sf::Vector2i(reference_position.x - 1, reference_position.y);  //Decreases the x-coordinate by 1 (moves right).
		//	break;
		//}

		//return default_position;
	}

	Node* SingleLinkedList::getHeadNode() {
		return head_node;
	}

	Node* SingleLinkedList::findNodeAtIndex(int index) {
		Node* cur_node = head_node;
		int currentIndex = 0;

		while (currentIndex <= index) {
			cur_node = cur_node->next;
			currentIndex++;
		}

		return cur_node;
	}
}
