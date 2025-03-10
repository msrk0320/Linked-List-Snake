#pragma once

namespace Level {
	class LevelController;
	class LevelService {
	private:
		void Destroy();
		LevelController* levelController;

	public:
		LevelService();
		~LevelService();

		void initialize();
		void render();
		void update();
	};
}