#include "../../include/Food/FoodService.h"
#include "../../include/Food/FoodItem.h"
#include "../../include/Level/LevelModel.h"
#include "../../include/Global/ServiceLocator.h"
#include "SFML/Graphics.hpp"

#include <iostream>
using namespace std;

using namespace Global;
using namespace sf;
using namespace Level;

namespace Food
{
	
	FoodService::FoodService(): random_engine(new_random_device())
	{
		current_food_item = nullptr;

	}
	FoodService::~FoodService()
	{
		destroyFood();
	}
	void FoodService::initialize()
	{
		elapsed_time = spawn_duration;
	}
	void FoodService::update()
	{
		if (current_spawn_status == FoodSpawningStatus::ACTIVE)
		{
			updateElapsedDuration();
			handleFoodSpawn();
		}

		if (current_food_item)
		{
			current_food_item->update();
		}
	}
	void FoodService::render()
	{
		if (current_food_item)
		{
		current_food_item->render();
		}
	}

	void FoodService::startFoodSpawning()
	{
		current_spawn_status = FoodSpawningStatus::ACTIVE;
		cell_width = ServiceLocator::getInstance()->getLevelService()->getCellWidth() ;
		cell_height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		spawnFood();
	}

	void FoodService::stopFoodSpawning()
	{
		current_spawn_status = FoodSpawningStatus::IN_ACTIVE;
		destroyFood();
		reset();
	}

	bool FoodService::isValidPosition(Vector2i random_position)
	{
		vector<Vector2i> obstacle_position_list = ServiceLocator::getInstance()->getElementService()->getElementPositionList();
		vector<Vector2i> snake_position_list = ServiceLocator::getInstance()->getPlayerService()->getSnakePositionList();
		
		for (int i = 0; i < obstacle_position_list.size(); i++)
		{
			if (getFoodPosition(random_position) == obstacle_position_list[i])
			{
				return false;
			}
		}

		for (int i = 0; i < snake_position_list.size(); i++)
		{
			if (getFoodPosition(random_position) == snake_position_list[i])
			{
				return false;
			}
		}

		return true;
	}

	bool FoodService::processFoodCollision(Node* head_node, FoodType& out_food_type)
	{
		
		if (current_food_item && getFoodPosition(current_food_item->getFoodPosition()) == head_node->body_part.getPosition())
		{
			out_food_type = current_food_item->getFoodType();
			return true;
		}

		return false;
	}

	Vector2i FoodService::getFoodPosition(Vector2i position)
	{

		return Vector2i(position.y,position.x);
	}

	

	FoodItem* FoodService::createFoodItem(Vector2i position, FoodType type)
	{
		FoodItem* food_item = new FoodItem();
		food_item->initialize(position, cell_width, cell_height, type);

		return food_item;
	}

	Vector2i FoodService::getRandomPosition()
	{
		uniform_int_distribution<int> x_distribution(0, LevelModel::number_of_rows - 1);
		uniform_int_distribution<int> y_distribution(0, LevelModel::number_of_columns -1);
		int xPosition = x_distribution(random_engine);
		int yPosition = y_distribution(random_engine);
		Vector2i random_position = Vector2i( xPosition, yPosition);

		if (!isValidPosition(random_position))
		{
			getRandomPosition();
		}

		return random_position;
	}

	FoodType FoodService::getRandomFoodType()
	{
		uniform_int_distribution<int> food_distribution(0, FoodItem::number_of_food - 1);
		return static_cast<FoodType>(food_distribution(random_engine));
	}

	void FoodService::spawnFood()
	{
		current_food_item = createFoodItem(getRandomPosition(), getRandomFoodType());

	}

	void FoodService::destroyFood()
	{
		if (current_food_item)
		{
			delete(current_food_item);
		}
	}
	void FoodService::updateElapsedDuration()
	{
		elapsed_time += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}
	void FoodService::handleFoodSpawn()
	{
		if (elapsed_time >= spawn_duration)
		{
			destroyFood();
			reset();
			spawnFood();
		}
	}
	void FoodService::reset()
	{
		elapsed_time = 0;
	}
}