#include "../../include/Element/ElementService.h"
#include <iostream>
using namespace std;

namespace Element
{
	void ElementService::destroy()
	{
	}
	ElementService::ElementService() = default;
	ElementService::~ElementService() = default;
	
	void ElementService::initialize()
	{
	}
	void ElementService::update()
	{
		for (int i = 0; i < obstale_list.size(); i++)
		{
			obstale_list[i]->update();
		}
	}
	void ElementService::render()
	{
		for (int i = 0; i < obstale_list.size(); i++)
		{
			obstale_list[i]->render();
		}
	}
	void ElementService::spawnObstacle(Vector2i position, float width, float height)
	{
		Obstacle* obstacle = new Obstacle();
		obstacle->initialize(position, width, height);
		obstale_list.push_back(obstacle);
	}
	const void ElementService::spawnElement(vector<ElementData>& element_data_list, float width, float height)
	{
		for (int i = 0; i < element_data_list.size(); i++)
		{
			switch (element_data_list[i].element_type)
			{
			case ElementType::OBSTACLE:
				spawnObstacle(element_data_list[i].grid_position,width,height);
				break;
			}
		}
	}
	vector<Vector2i> ElementService::getElementPositionList()
	{
		vector<Vector2i> element_position_list;

		for (int i = 0; i < obstale_list.size(); i++)
		{
			element_position_list.push_back(obstale_list[i]->getObstaclePosition());
		}
		return element_position_list;
	}

	bool ElementService::processElementCollision(Node* head_node)
	{
		for (int i = 0; i < obstale_list.size(); i++)
		{


			if (head_node->body_part.getPosition() == obstale_list[i]->getObstaclePosition())
			{
				/*cout << "head position : (" << head_node->body_part.getNextPosition().x <<
					"," << head_node->body_part.getNextPosition().y << ") Obstacle : ("
					<< obstale_list[i]->getObstaclePosition().x << "," <<
					obstale_list[i]->getObstaclePosition().y << ")" << endl;*/
				return true;
			}
		}
		return false;
	}
	
}