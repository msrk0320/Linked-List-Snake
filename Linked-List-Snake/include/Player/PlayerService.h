#pragma once
#include "Player/SnakeController.h"

namespace Player {
	class PlayerService {
	private:
		SnakeController* snakeController;

		void createController();
		void destroy();

	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();

		void spawnPlayer();
		std::vector<sf::Vector2i> getCurrentSnakePositionList();
	};
}