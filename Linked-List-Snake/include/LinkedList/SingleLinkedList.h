#pragma once
#include "LinkedList/Node.h"

namespace LinkedList {
	class SingleLinkedList {

	private:
		Node* head_node;

		float node_width;
		float node_height;
		sf::Vector2i default_position;
		Direction default_direction;

		Node* createNode();
		void destroy();

	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, sf::Vector2i position, Direction direction);
		void render();

		void updateNodeDirection(Direction direction_to_set);

		void updateNodePosition();

		sf::Vector2i getNewNodePosition(Node* reference_node);

		void insertNodeAtTail();

		//void createHeadNode();
	};
}