#pragma once
#include "LevelNumber.h"

namespace Level
{
    class LevelController;

    class LevelService
    {
    private:
        LevelController* level_controller;
        LevelNumber current_level;

        void createLevelController();
        void destroy();

		void spawnPlayer();

    public:
        LevelService();
        ~LevelService();

        void initialize();
        void update();
        void render();

        void createLevel(LevelNumber level_to_load);

        const float getCellWidth();
		const float getCellHeight();

        void spawnFood();

        void spawnLevelElements(LevelNumber level_to_load);
    };
}