#pragma once
#include <SFML/Graphics.hpp>
#include "Player/Direction.h"
#include "Food/FoodType.h"
#include "LinkedList/SingleLinkedList.h"
#include <vector>

using namespace std;
using namespace LinkedList;
using namespace sf;
using namespace Food;

namespace Player
{
	enum class SnakeState
	{
		ALIVE,
		DEAD
	};

	enum class InputState
	{
		WAITING,
		PROCESSING
	};
	

	class SnakeController
	{
	private:

		const Vector2i default_position = Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;
		Direction current_direction;
		float movement_frame_duration = 0.1f;
		float elapsed_duration = 0.f;

		const float restart_timer = 2.0f;
		float timer;


		const int initial_snake_length = 10;
		SnakeState current_snake_state;
		InputState current_input_state;

		SingleLinkedList* single_linked_list;

		void processSnakeBehaviour();
		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void handleRestart();

		void processBodyCollision();
		void processElementCollision();
		void processFoodCollision();

		void onFoodCollected(FoodType food_type);

		void createLinkedList();
		void destroy();

	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();

		void reset();
		void respawnSnake();
		void spawnSnake();

		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();
		void delayUpdate();

		vector<Vector2i> getSnakePositionList();

	};
}