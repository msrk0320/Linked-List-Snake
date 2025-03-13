#pragma once
#include "Level/LevelNumber.h"

namespace Level
{
	class LevelController;
	class LevelService
	{
	private:
		LevelController* level_controller;
		LevelNumber current_level;

		void destroy();
	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		void createLevelController();
		void createLevel(LevelNumber level_to_load);

		void spawnPlayer();

		float getCellWidth();
		float getCellHeight();

		void spawnFood();
		void spawnLevelElements(LevelNumber level_to_load);
	};
}