#pragma once

namespace Level {
	class LevelModel;
	class LevelView;
	class LevelController {
	private:
		LevelView* levelView;
		LevelModel* levelModel;

	public:
		LevelController();
		~LevelController();

		void initialize();
		void render();
		void update();

		float getCellWidth();
		float getCellHeight();
	};
}