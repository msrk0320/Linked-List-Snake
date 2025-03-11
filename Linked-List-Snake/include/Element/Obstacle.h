#pragma once
#include<SFML/Graphics.hpp>
#include "UI/UIService.h"

namespace Element {
	using namespace sf;

	class Obstacle {
	private:
		UI::UIElement::ImageView* obstacle_image;
		sf::Vector2i grid_position;

		void initializeObstacleImage();
		sf::Vector2f getObstacleImagePosition();

		float cell_width;
		float cell_height;

	public:
		Obstacle();
		~Obstacle();

		void initialize(sf::Vector2i grid_pos, float width, float height);
		void update();
		void render();
		sf::Vector2i getObstaclePosition();
	};
}