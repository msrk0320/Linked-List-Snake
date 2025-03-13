#pragma once
#include <SFML/Graphics.hpp>
#include "LinkedList/Node.h"
#include <vector>


using namespace sf;
using namespace std;
using namespace Player;

namespace LinkedList
{
	enum class Operation
	{
		HEAD,
		MID,
		TAIL,
	};
	class SingleLinkedList
	{
	private:
		Node* head_node;

		float node_width;
		float node_height;

		Vector2i default_position;
		Direction default_direction;

		int linked_list_size;

		Node* createNode();

	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, Vector2i position, Direction direction);
		void render();

		void initializeNode(Node* new_node,Node* reference_node,Operation operation);

		Vector2i getNewNodePosition(Node* reference,Operation operation);
		void updateNodeDirection(Direction direction_to_set);
		void updateNodePosition();
		bool processNodeCollision();

		void insertNodeAtTail();
		void insertNodeAtHead();
		void insertNodeAtIndex(int index);
		void insertNodeAtMiddle();
		void insertNodeAt(int index);

		void shiftNodeAfterInsertion(Node* new_node,Node* current_node,Node* previous_node);
		void shiftNodesAfterRemoval(Node* cur_node);


		int findMiddleIndex();

		void removeAllHeadNode();
		void removeNodeAtHead();
		void removeNodeAtIndex(int index);
		void removeNodeAt(int index);
		void removeNodeAtMiddle();
		void removeNodeAtTail();
		Node* findNodeAtIndex(int index);
		void removeHalfNodes();

		Direction reverse();
		void reverseNodeDirection();

		Direction getReverseDirection(Direction reference_direction);


		vector<Vector2i> getNodePositionList();
		Node* getHead();


	};
}