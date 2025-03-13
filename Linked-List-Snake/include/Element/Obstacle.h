#pragma once
#include <SFML/Graphics.hpp>
#include "../../include/UI/UIElement/ImageView.h"

using namespace sf;
using namespace UI::UIElement;

namespace Element
{

	class Obstacle
	{
	private:
		ImageView* obstacle_image;
		Vector2i grid_position;
		float cell_width;
		float cell_height;

		void initializeObstacleImage();
		Vector2f getObstacleScreenPosition();
		void destroy();

	public:
		Obstacle();
		~Obstacle();

		void initialize(Vector2i position, float width, float height);
		void update();
		void render();

		Vector2i getObstaclePosition();
	};
}