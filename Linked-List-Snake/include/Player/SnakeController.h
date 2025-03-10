#pragma once
#include "Direction.h"
#include <SFML/Graphics.hpp>
#include "LinkedList/SingleLinkedList.h"

namespace Player {
using namespace LinkedList;
	enum class SnakeState
	{
		ALIVE,
		DEAD,
	};
	class SnakeController {
	private:
		void destroy();

		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void handleRestart();
		void reset();

		const int initial_snake_length = 10;
		SnakeState current_snake_state;

		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;
		Direction current_snake_direction;
		const float movement_frame_duration = 0.1f;
		float elapsed_duration = 0.0f;

		SingleLinkedList* single_linked_list;
		void createLinkedList();

	public:
		SnakeController();
		~SnakeController();

		void initizalize();
		void update();
		void delayedUpdate();
		void render();

		void spawnSnake();
		void respawnSnake();
		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();
	};
}