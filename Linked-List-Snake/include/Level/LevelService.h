#pragma once
#include "LevelNumber.h"

namespace Level {
	class LevelController;
	class LevelService {
	private:
		void Destroy();
		LevelController* levelController;
		LevelNumber current_level;

	public:
		LevelService();
		~LevelService();

		void createLevelController();

		void initialize();
		void render();
		void update();
		void createLevel(LevelNumber level_to_load);
	};
}