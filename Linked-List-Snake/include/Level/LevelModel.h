#pragma once
#include <vector>
#include "LevelData.h"
namespace Level {
	class LevelModel {
	private:
		void Destroy();
		std::vector<LevelData> level_configurations;
		float cell_width;
		float cell_height;

	public:
		LevelModel();
		~LevelModel();
		
		static const int number_of_rows = 28;
		static const int number_of_columns = 50;

		float getCellWidth();
		float getCellHeight();

		void render();
		void update();
		void initialize(int width, int height);
	};
}