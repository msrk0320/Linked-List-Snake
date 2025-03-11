#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "LinkedList/SingleLinkedList.h"

using namespace LinkedList;
namespace Element {
	class Obstacle;
	struct ElementData;
	class ElementService {
	public:
		ElementService();
		~ElementService();

		void initialize();
		void update();
		void render();

		const void spawnElements(std::vector<ElementData>& element_data_list, float cell_width, float cell_height);

		std::vector <sf::Vector2i> getElementsPositionList();

		bool processElementsCollision(Node* head_node);
	private:
		std::vector<Obstacle*> obstacle_list;
		void spawnObstacle(sf::Vector2i position, float cell_width, float cell_height);
	};
}