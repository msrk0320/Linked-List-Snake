#pragma once
#include "Direction.h"
#include "UI/UIService.h"
#include <SFML/Graphics.hpp>

using namespace UI;
namespace Player {
	class Data {
	protected:
		UI::UIElement::ImageView* bodypart_image;

		sf::Vector2i grid_position;
		Direction direction;

		float bodypart_width;
		float bodypart_height;
	};
}