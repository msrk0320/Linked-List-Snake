#pragma once
#include "LinkedList/Node.h"
#include <vector>
#include <SFML/System/Vector2.hpp>

namespace LinkedList {

	enum class Operation {
		HEAD,
		MID,
		TAIL,
	};

	class SingleLinkedList {
	private:
		Node* head_node;

		float node_width;
		float node_height;

		sf::Vector2i default_position;

		Direction default_direction;

		int linked_list_size;

		Node* createNode();

		void destroy();
		void shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);
		void shiftNodesAfterRemoval(Node* cur_node);

	public:
		SingleLinkedList();
		~SingleLinkedList();

		// Initialization methods
		void initialize(float width, float height, sf::Vector2i position, Direction direction);
		void initializeNode(Node* new_node, Node* reference_node, Operation operation);

		// Rendering methods
		void render();

		// Update methods
		void updateNodeDirection(Direction direction_to_set);
		void updateNodePosition();

		Direction reverse();
		Direction getReverseDirection(Direction reference_direction);

		void reverseNodeDirections();

		// Insertion methods
		void insertNodeAtHead();
		void insertNodeAtIndex(int index);
		void insertNodeAtMiddle();
		void insertNodeAt(int index);
		void insertNodeAtTail();

		// Removal methods
		void removeNodeAtHead();
		void removeNodeAtIndex(int index);
		void removeNodeAt(int index);
		void removeNodeAtMiddle();
		void removeNodeAtTail();
		void removeHalfNodes();
		void removeAllNodes();

		// Utility methods
		int findMiddleNode();
		bool processNodeCollision();

		std::vector<sf::Vector2i> getNodesPositionList();
		sf::Vector2i getNewNodePosition(Node* reference_node, Operation operation);

		Node* getHeadNode();
		Node* findNodeAtIndex(int index);
	};
}