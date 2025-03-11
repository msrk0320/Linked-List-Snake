#pragma once
#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "UI/UIService.h"

namespace Player {
	class BodyPart {
	protected:
		UI::UIElement::ImageView* bodypart_image;

		sf::Vector2i grid_position;
		Direction direction;

		float bodypart_width;
		float bodypart_height;

	public:
		BodyPart();
		~BodyPart();

		void initialize(float width, float height, sf::Vector2i pos, Direction dir);
		void update();
		void render();

		void createBodyPartImage();
		void initializeBodyPartImage();
		void setDirection(Direction direction);

		void updatePosition();
		sf::Vector2i getNextPosition();
		sf::Vector2i getPrevPosition();
		void setPosition(sf::Vector2i position);

		sf::Vector2i getNextPositionUp();
		sf::Vector2i getNextPositionDown();
		sf::Vector2i getNextPositionRight();
		sf::Vector2i getNextPositionLeft();

		sf::Vector2f getBodyPartScreenPosition();
		float getRotationAngle();
		Direction getDirection();
		sf::Vector2i getPosition();

	private:
		void destroy();
	};
}