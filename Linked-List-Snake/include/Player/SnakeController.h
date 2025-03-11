#pragma once
#include "Direction.h"
#include <SFML/Graphics.hpp>
#include "LinkedList/SingleLinkedList.h"
#include "Food/FoodType.h"

namespace Player {
	using namespace Food;
	using namespace LinkedList;
	enum class SnakeState
	{
		ALIVE,
		DEAD,
	};
	enum class InputState
	{
		WAITING,
		PROCESSING
	};
	class SnakeController {
	private:
		void destroy();

		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();

		void processBodyCollision();
		void processElementsCollision();
		void processFoodCollision();

		void OnFoodCollected(FoodType food_type);

		void handleRestart();
		void reset();

		const int initial_snake_length = 10;
		SnakeState current_snake_state;

		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;
		Direction current_snake_direction = default_direction;
		const float movement_frame_duration = 0.1f;
		float elapsed_duration = 0.0f;
		const float restart_duration = 2.f;
		float restart_counter = 0.f;

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
		InputState current_input_state;

		std::vector<sf::Vector2i> getCurrentSnakePositionList();
	};
}