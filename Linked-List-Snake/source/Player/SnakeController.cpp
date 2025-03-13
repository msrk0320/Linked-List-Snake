#include "../../include/Player/SnakeController.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Event/EventService.h"
#include "../../include/Global/Config.h"

#include <iostream>
using namespace std;


using namespace Global;
using namespace Event;

namespace Player
{
	SnakeController::SnakeController()
	{
		single_linked_list = nullptr;
		current_direction = default_direction;
		createLinkedList();
	}

	SnakeController::~SnakeController()
	{
		destroy();
	}

	void SnakeController::initialize()
	{
		float width = ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		float height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		single_linked_list->initialize(width,height,default_position,default_direction);
	}

	void SnakeController::update()
	{
		if (current_snake_state == SnakeState::ALIVE)
		{
			processSnakeBehaviour();
		}
		else
		{

			handleRestart();
		}
	}

	void SnakeController::render()
	{
		if (current_snake_state == SnakeState::ALIVE)
		{
			single_linked_list->render();
		}
	}

	void SnakeController::reset()
	{
		current_snake_state = SnakeState::ALIVE;
		current_input_state = InputState::WAITING;
		current_direction = default_direction;
		elapsed_duration = 0.f;
		timer = 0;
	}

	void SnakeController::respawnSnake()
	{
		single_linked_list->removeAllHeadNode();
		reset();
		spawnSnake();
	}

	void SnakeController::spawnSnake()
	{
		for (int i = 0; i < initial_snake_length; i++)
		{
			single_linked_list->insertNodeAtTail();
		}
	}

	void SnakeController::setSnakeState(SnakeState state)
	{
		current_snake_state = state;
	}

	SnakeState SnakeController::getSnakeState()
	{
		return current_snake_state;
	}

	void SnakeController::delayUpdate()
	{
		elapsed_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (elapsed_duration >= movement_frame_duration)
		{
			elapsed_duration = 0.f;
			updateSnakeDirection();
			processSnakeCollision();

			if (current_snake_state == SnakeState::ALIVE)
			{
				moveSnake();
			}
		}
	}

	vector<Vector2i> SnakeController::getSnakePositionList()
	{
		return single_linked_list->getNodePositionList();
	}

	
	void SnakeController::processSnakeBehaviour()
	{
		if (current_input_state == InputState::WAITING)
		{
			processPlayerInput();
		}
		delayUpdate();

	}

	void SnakeController::processPlayerInput()
	{
		current_input_state = InputState::PROCESSING;

		EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedUpArrowKey() && current_direction!=Direction::DOWN)
		{
			current_direction = Direction::UP;
		}
		else if (event_service->pressedDownArrowKey() && current_direction != Direction::UP)
		{
			current_direction = Direction::DOWN;

		}
		else if (event_service->pressedLeftArrowKey() && current_direction != Direction::RIGHT)
		{
			current_direction = Direction::LEFT;

		}
		else if (event_service->pressedRightArrowKey() && current_direction != Direction::LEFT)
		{
			current_direction = Direction::RIGHT;

		}
	}

	void SnakeController::updateSnakeDirection()
	{
		single_linked_list->updateNodeDirection(current_direction);
	}

	void SnakeController::moveSnake()
	{
		single_linked_list->updateNodePosition();
		current_input_state = InputState::WAITING;

	}

	void SnakeController::processSnakeCollision()
	{
		processBodyCollision();
		processElementCollision();
		processFoodCollision();
	}

	void SnakeController::handleRestart()
	{
		//ServiceLocator::getInstance()->getFoodService()->stopFoodSpawning();

		timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (timer >= restart_timer)
		{
			respawnSnake();

		}
	}

	void SnakeController::processBodyCollision()
	{
		if (single_linked_list->processNodeCollision())
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
			current_snake_state = SnakeState::DEAD;
			timer = 0;
		}
	}

	void SnakeController::processElementCollision()
	{
		if (ServiceLocator::getInstance()->getElementService()->processElementCollision(single_linked_list->getHead()))
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
			current_snake_state = SnakeState::DEAD;
		}
	}

	void SnakeController::processFoodCollision()
	{
		FoodType food_type;

		if (ServiceLocator::getInstance()->getFoodService()->processFoodCollision(single_linked_list->getHead(), food_type))
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::PICKUP);
			ServiceLocator::getInstance()->getFoodService()->destroyFood();
			ServiceLocator::getInstance()->getFoodService()->spawnFood();
		}
	}

	void SnakeController::onFoodCollected(FoodType food_type)
	{
		switch (food_type)
		{
		case Food::FoodType::APPLE:
			single_linked_list->removeNodeAtHead();
			break;
		case Food::FoodType::MANGO:
			single_linked_list->removeNodeAtMiddle();
			break;
		case Food::FoodType::ORANGE:
			single_linked_list->removeNodeAtTail();
			break;
		case Food::FoodType::PIZZA:
			single_linked_list->insertNodeAtTail();
			break;
		case Food::FoodType::BURGER:
			single_linked_list->insertNodeAtHead();
			break;
		case Food::FoodType::CHEESE:
			single_linked_list->insertNodeAtMiddle();
			break;
		case Food::FoodType::POISION:
			single_linked_list->removeHalfNodes();
			break;
		case Food::FoodType::ALCOHOL:
			current_direction=single_linked_list->reverse();
			break;
		default:
			break;
		}
	}

	void SnakeController::createLinkedList()
	{
		single_linked_list = new SingleLinkedList();
	}

	void SnakeController::destroy()
	{
		delete(single_linked_list);
	}

}