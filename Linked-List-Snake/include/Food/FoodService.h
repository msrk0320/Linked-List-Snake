#pragma once
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <random>
#include "LinkedList/SingleLinkedList.h"

namespace Food {
	enum class FoodType;
	class FoodItem;
	enum FoodSpawningStatus
	{
		ACTIVE,
		IN_ACTIVE,
	};
	class FoodService {
	private:
		FoodItem* current_food_item;
		float cell_width;
		float cell_height;

		void reset();
		void updateElapsedDuration();
		void handleFoodSpawning();
		
		std::default_random_engine random_engine;
		std::random_device random_device;

		const float spawn_duration = 4.f;
		float elapsed_duration;

		FoodSpawningStatus current_spawning_status;


	public:
		FoodService();
		~FoodService();

		void initialize();
		void update();
		void render();

		void startFoodSpawning();
		void stopFoodSpawning();
		void spawnFood();
		
		sf::Vector2i getRandomPosition();
		sf::Vector2i getValidSpawnPosition();
		
		bool isValidPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position);
		bool processFoodCollision(LinkedList::Node* head_node, FoodType& out_food_type);

		FoodType getRandomFoodType();
		FoodItem* createFood(sf::Vector2i position, FoodType type);
		void destroyFood();
	};
}