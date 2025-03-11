#include "../../include/LinkedList/Node.h"
#include "../../include/LinkedList/SingleLinkedList.h"
#include <iostream>

namespace LinkedList {
	Node* SingleLinkedList::createNode()
	{
		return new Node();
	}

	SingleLinkedList::SingleLinkedList()
	{
		head_node = nullptr;
	}

	SingleLinkedList::~SingleLinkedList() = default;

	void SingleLinkedList::initialize(float width, float height, sf::Vector2i position, Direction direction)
	{
		node_width = width;
		node_height = height;
		default_position = position;
		default_direction = direction;
	}

	void SingleLinkedList::render()
	{
		//head_node->body_part.render();
		Node* cur_node = head_node;

		while (cur_node != nullptr) {     // Traverse through the linked list and render each node's body part
			cur_node->body_part.render();
			cur_node = cur_node->next;
		}
	}

	void SingleLinkedList::updateNodeDirection(Direction direction_to_set)
	{
		Node* cur_node = head_node;

		while (cur_node != nullptr)
		{
			Direction previous_direction = cur_node->body_part.getDirection();
			cur_node->body_part.setDirection(direction_to_set);
			direction_to_set = previous_direction;
			cur_node = cur_node->next;
		}
	}

	void SingleLinkedList::updateNodePosition()
	{
		Node* cur_node = head_node;
		while (cur_node != nullptr)
		{
			cur_node->body_part.setPosition(cur_node->body_part.getNextPosition());
			cur_node->body_part.updatePosition();
			cur_node = cur_node->next;
		}
	}

	void SingleLinkedList::initializeNode(Node* new_node, Node* reference_node, Operation operation)
	{

	}

	sf::Vector2i SingleLinkedList::getNewNodePosition(Node* reference_node,Operation operation)
	{
		//// Extract direction and position for new node calculation
		//Direction reference_direction = reference_node->body_part.getDirection();
		//sf::Vector2i reference_position = reference_node->body_part.getPosition();

		switch (operation)
		{
		case LinkedList::Operation::HEAD:
			return reference_node->body_part.getNextPosition();
			break;
		case LinkedList::Operation::MID:

			break;
		case LinkedList::Operation::TAIL:
			return reference_node->body_part.getPrevPosition();
			break;
		default:
			break;
		}

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

	void SingleLinkedList::insertNodeAtTail() {
		Node* new_node = createNode();
		Node* cur_node = head_node;

		if (cur_node == nullptr) {       // If the list is empty, set the new node as the head
			head_node = new_node;
			new_node->body_part.initialize(node_width, node_height, default_position, default_direction);
			return;
		}

		while (cur_node->next != nullptr) {
			cur_node = cur_node->next;
		}

		cur_node->next = new_node;
		new_node->body_part.initialize(node_width, node_height, getNewNodePosition(cur_node,Operation::TAIL), cur_node->body_part.getDirection());
	}

	bool SingleLinkedList::processNodeCollision()
	{
		if (head_node == nullptr) return false;

		sf::Vector2i predicted_position = head_node->body_part.getPosition();

		Node* cur_node = head_node->next;
		while (cur_node != nullptr)
		{
			if (cur_node->body_part.getPosition() == predicted_position) return true;
			cur_node = cur_node->next;
		}

		return false;
	}

	void SingleLinkedList::removeNodeAtHead()
	{
		Node* cur_node = head_node;
		head_node = head_node->next;

		cur_node->next = nullptr;
		delete (cur_node);
	}

	void SingleLinkedList::removeAllNodes()
	{
		if (head_node == nullptr) return;

		while (head_node != nullptr)
		{
			removeNodeAtHead();
		}
	}

	std::vector<sf::Vector2i> SingleLinkedList::getNodesPositionList()
	{
		std::vector<sf::Vector2i> nodes_position_list;

		Node* cur_node = head_node;

		while (cur_node != nullptr)
		{
			nodes_position_list.push_back(cur_node->body_part.getPosition());
			cur_node = cur_node->next;
		}

		return nodes_position_list;
	}

	Node* SingleLinkedList::getHeadNode()
	{
		if (head_node != nullptr)
			return head_node;
		else
			return nullptr;
	}


	void SingleLinkedList::destroy()
	{

	}
}