#include "../../include/Level/LevelService.h"
#include "../../include/Global/Config.h"
#include "../../include/Level/LevelController.h"

namespace Level {
	using namespace Global;

	LevelService::LevelService()
	{
		levelController = nullptr;
		createLevelController();
	}

	LevelService::~LevelService()
	{
		Destroy();
	}

	void LevelService::createLevelController()
	{
		levelController = new LevelController();
	}

	void LevelService::initialize()
	{
		levelController->initialize();
	}

	void LevelService::render()
	{
		levelController->render();
	}

	void LevelService::update()
	{
		levelController->update();
	}

	void LevelService::createLevel(LevelNumber level_to_load)
	{
		current_level = level_to_load;
	}

	void LevelService::Destroy()
	{
		delete levelController;
	}

}