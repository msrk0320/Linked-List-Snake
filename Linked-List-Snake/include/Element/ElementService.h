#pragma once
#include <vector>
#include "../../include/Element/Obstacle.h";
#include "../../include/Element/ElementData.h";
#include "../../include/LinkedList/SingleLinkedList.h"

using namespace std;
using namespace LinkedList;

namespace Element
{
	class ElementService
	{
	private:
		vector<Obstacle*> obstale_list;

		void destroy();

	public :
		ElementService();
		~ElementService();

		void initialize();
		void update();
		void render();

		void spawnObstacle(Vector2i position, float width, float heoght);

		const void spawnElement(vector <ElementData>& element_data_list, float width, float heoght);

		vector<Vector2i> getElementPositionList();
		bool processElementCollision(Node* head);
	};
}