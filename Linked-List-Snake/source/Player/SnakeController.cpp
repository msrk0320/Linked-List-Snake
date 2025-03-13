#include "../../include/Player/SnakeController.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Level/LevelService.h"
#include <iostream>
using namespace Food;
using namespace Element;

namespace Player {
	
	using namespace Global;
	using namespace Level;

	SnakeController::SnakeController()
	{
		single_linked_list = nullptr;
		createLinkedList();
	}

	SnakeController::~SnakeController()
	{
		destroy();
	}

	void SnakeController::initizalize()
	{
		float width = ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		float height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		single_linked_list->initialize(width, height, default_position, default_direction);
	}
	void SnakeController::createLinkedList()
	{
		single_linked_list = new SingleLinkedList();
	}

	void SnakeController::update()
	{
		switch (current_snake_state)
		{
		case Player::SnakeState::ALIVE:
			processPlayerInput();
			delayedUpdate();
			break;
		case Player::SnakeState::DEAD:
			handleRestart();
			break;
		}
	}

	void SnakeController::delayedUpdate()
	{
		elapsed_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (elapsed_duration >= movement_frame_duration)
		{
			elapsed_duration = 0.f;
			updateSnakeDirection();
			processSnakeCollision();
			if (current_snake_state == SnakeState::ALIVE)
				moveSnake();
			current_input_state = InputState::WAITING;
		}
	}

	void SnakeController::render() 
	{
		single_linked_list->render();
	}

	void SnakeController::processPlayerInput() 
	{
		if (current_input_state == InputState::PROCESSING)
			return;

		Event::EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedUpArrowKey() && current_snake_direction != Direction::DOWN)
		{
			current_snake_direction = Direction::UP;
			current_input_state = InputState::PROCESSING;
		}

		if (event_service->pressedDownArrowKey() && current_snake_direction != Direction::UP)
		{
			current_snake_direction = Direction::DOWN;
			current_input_state = InputState::PROCESSING;
		}

		if (event_service->pressedLeftArrowKey() && current_snake_direction != Direction::RIGHT)
		{
			current_snake_direction = Direction::LEFT;
			current_input_state = InputState::PROCESSING;
		}

		if (event_service->pressedRightArrowKey() && current_snake_direction != Direction::LEFT)
		{
			current_snake_direction = Direction::RIGHT;
			current_input_state = InputState::PROCESSING;
		}
	}

	void SnakeController::updateSnakeDirection() 
	{
		single_linked_list->updateNodeDirection(current_snake_direction);
	}

	void SnakeController::moveSnake() 
	{
		single_linked_list->updateNodePosition();
	}

	void SnakeController::processSnakeCollision()
	{
		processBodyCollision();
		processElementsCollision();
		processFoodCollision();
	}

	void SnakeController::processBodyCollision()
	{
		if (single_linked_list->processNodeCollision())
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
			current_snake_state = SnakeState::DEAD;
		}
	}

	void SnakeController::processElementsCollision()
	{
		ElementService* element_service = ServiceLocator::getInstance()->getElementService();

		if (element_service->processElementsCollision(single_linked_list->getHeadNode()))
		{
			current_snake_state = SnakeState::DEAD;
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::DEATH);
		}
	}

	void SnakeController::processFoodCollision()
	{
		FoodService* food_service = ServiceLocator::getInstance()->getFoodService();
		FoodType food_type;

		if (food_service->processFoodCollision(single_linked_list->getHeadNode(), food_type))
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::PICKUP);

			food_service->destroyFood();
			food_service->spawnFood();
			OnFoodCollected(food_type);
		}
	}

	void SnakeController::OnFoodCollected(FoodType food_type)
	{
		switch (food_type)
		{
		case FoodType::PIZZA:
			single_linked_list->insertNodeAtTail();
			//Insert At Tail
			break;

		case FoodType::BURGER:
			single_linked_list->insertNodeAtHead();
			//Insert At Head
			break;

		case FoodType::CHEESE:
			single_linked_list->insertNodeAtMiddle();
			//Insert in Middle
			break;

		case FoodType::APPLE:
			single_linked_list->removeNodeAtHead();
			//Delete at Head
			break;

		case FoodType::MANGO:
			single_linked_list->removeNodeAtMiddle();
			//Delete at Middle
			break;

		case FoodType::ORANGE:
			single_linked_list->removeNodeAtTail();
			//Delete at Tail
			break;

		case FoodType::POISION:
			single_linked_list->removeHalfNodes();
			//Delete half the snake
			break;

		case FoodType::ALCOHOL:
			current_snake_direction = single_linked_list->reverse();
			//Reverse the snake
			break;
		}
	}

	void SnakeController::handleRestart() 
	{
		restart_counter += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (restart_counter >= restart_duration)
		{
			respawnSnake();
		}
	}

	void SnakeController::spawnSnake()
	{
		//for (int i = 0; i < initial_snake_length; i++) {
		//	single_linked_list->insertNodeAtTail();     // Insert nodes at tail to create the initial snake
		//}
		for (size_t i = 0; i < initial_snake_length; i++)
		{
			single_linked_list->insertNodeAtTail();
		}
	}

	void SnakeController::reset()
	{
		current_snake_state = SnakeState::ALIVE;
		current_snake_direction = default_direction;
		elapsed_duration = 0.f;
		restart_counter = 0.f;
		current_input_state = InputState::WAITING;
	}

	void SnakeController::respawnSnake()
	{
		single_linked_list->removeAllNodes();
		reset();
		spawnSnake();
	}

	void SnakeController::setSnakeState(SnakeState state)
	{
		current_snake_state = state;
	}

	SnakeState SnakeController::getSnakeState()
	{
		return current_snake_state;
	}

	std::vector<sf::Vector2i> SnakeController::getCurrentSnakePositionList()
	{
		return single_linked_list->getNodesPositionList();
	}


	void SnakeController::destroy()
	{
		delete (single_linked_list);
	}

}