#pragma once
namespace Level {
	class LevelModel {
	private:
		void Destroy();

	public:
		LevelModel();
		~LevelModel();

		void initialize();
		void render();
		void update();
	};
}