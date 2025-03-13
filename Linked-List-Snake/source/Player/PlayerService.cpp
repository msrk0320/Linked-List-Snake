#include "../../include/Player/PlayerService.h"
#include "../../include/Player/SnakeController.h"

namespace Player
{
	

	PlayerService::PlayerService()
	{
		snake_controller = nullptr;

		createController();
	}

	PlayerService::~PlayerService()
	{
		destroy();
	}

	void PlayerService::initialize()
	{
		snake_controller->initialize();
	}

	void PlayerService::update()
	{
		snake_controller->update();
	}

	void PlayerService::render()
	{
		snake_controller->render();
	}

	void PlayerService::createController()
	{
		snake_controller = new SnakeController();

	}

	void PlayerService::spawnPlayer()
	{
		snake_controller->spawnSnake();
	}

	vector<Vector2i> PlayerService::getSnakePositionList()
	{
		return snake_controller->getSnakePositionList();
	}

	void PlayerService::destroy()
	{
		delete(snake_controller);
	}

}