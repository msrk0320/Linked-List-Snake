#pragma once


namespace Level {
	class LevelController;
	class LevelView {
	private:
		void Destroy();
		LevelController* levelController;

	public:
		LevelView();
		~LevelView();

		void initialize(LevelController* level_Controller);
		void render();
		void update();
	};
}