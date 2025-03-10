#include "../../include/Player/PlayerService.h"

namespace Player {
	void PlayerService::createController()
	{
		snakeController = new SnakeController();
	}

	PlayerService::PlayerService()
	{
		snakeController = nullptr;
		createController();
	}

	PlayerService::~PlayerService()
	{
		destroy();
	}

	void PlayerService::initialize()
	{
		snakeController->initizalize();
	}

	void PlayerService::update()
	{
		snakeController->update();
	}

	void PlayerService::render()
	{
		snakeController->render();
	}

	void PlayerService::spawnPlayer()
	{
		snakeController->spawnSnake();
	}


	void PlayerService::destroy()
	{
		delete(snakeController);
	}
}