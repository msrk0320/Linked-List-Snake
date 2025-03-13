#pragma once
#include <vector>
#include "Level/LevelData.h"
#include "Element/ElementData.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
using namespace Element;

namespace Level
{

	class LevelModel
	{
	private:

		//level data
		vector<LevelData> level_configurations;
		vector<ElementData> level_1_element_list = {};
		vector<ElementData> level_2_element_list =
		{
			//top left
			ElementData(ElementType::OBSTACLE,Vector2i(1,1)),
			ElementData(ElementType::OBSTACLE,Vector2i(1,2)),
			ElementData(ElementType::OBSTACLE,Vector2i(1,3)),
			ElementData(ElementType::OBSTACLE,Vector2i(1,4)),
			ElementData(ElementType::OBSTACLE,Vector2i(2,1)),
			ElementData(ElementType::OBSTACLE,Vector2i(3,1)),
			ElementData(ElementType::OBSTACLE,Vector2i(4,1)),

			////top right
			ElementData(ElementType::OBSTACLE,Vector2i(49,1)),
			ElementData(ElementType::OBSTACLE,Vector2i(48,1)),
			ElementData(ElementType::OBSTACLE,Vector2i(47,1)),
			ElementData(ElementType::OBSTACLE,Vector2i(46,1)),
			ElementData(ElementType::OBSTACLE,Vector2i(49,2)),
			ElementData(ElementType::OBSTACLE,Vector2i(49,3)),
			ElementData(ElementType::OBSTACLE,Vector2i(49,4)),


			//middle top
			ElementData(ElementType::OBSTACLE,Vector2i(25,12)),
			ElementData(ElementType::OBSTACLE,Vector2i(24,12)),
			ElementData(ElementType::OBSTACLE,Vector2i(23,12)),
			ElementData(ElementType::OBSTACLE,Vector2i(22,12)),
			ElementData(ElementType::OBSTACLE,Vector2i(21,12)),
			ElementData(ElementType::OBSTACLE,Vector2i(20,12)),
			ElementData(ElementType::OBSTACLE,Vector2i(26,12)),
			ElementData(ElementType::OBSTACLE,Vector2i(27,12)),
			ElementData(ElementType::OBSTACLE,Vector2i(28,12)),
			ElementData(ElementType::OBSTACLE,Vector2i(29,12)),
			ElementData(ElementType::OBSTACLE,Vector2i(30,12)),

			////middle bottom
			ElementData(ElementType::OBSTACLE,Vector2i(25,16)),
			ElementData(ElementType::OBSTACLE,Vector2i(24,16)),
			ElementData(ElementType::OBSTACLE,Vector2i(23,16)),
			ElementData(ElementType::OBSTACLE,Vector2i(22,16)),
			ElementData(ElementType::OBSTACLE,Vector2i(21,16)),
			ElementData(ElementType::OBSTACLE,Vector2i(20,16)),
			ElementData(ElementType::OBSTACLE,Vector2i(26,16)),
			ElementData(ElementType::OBSTACLE,Vector2i(27,16)),
			ElementData(ElementType::OBSTACLE,Vector2i(28,16)),
			ElementData(ElementType::OBSTACLE,Vector2i(29,16)),
			ElementData(ElementType::OBSTACLE,Vector2i(30,16)),


			//bottom left
			ElementData(ElementType::OBSTACLE,Vector2i(1,26)),
			ElementData(ElementType::OBSTACLE,Vector2i(1,25)),
			ElementData(ElementType::OBSTACLE,Vector2i(1,24)),
			ElementData(ElementType::OBSTACLE,Vector2i(1,23)),
			ElementData(ElementType::OBSTACLE,Vector2i(2,26)),
			ElementData(ElementType::OBSTACLE,Vector2i(3,26)),
			ElementData(ElementType::OBSTACLE,Vector2i(4,26)),

			////bottom right
			ElementData(ElementType::OBSTACLE,Vector2i(49,26)),
			ElementData(ElementType::OBSTACLE,Vector2i(48,26)),
			ElementData(ElementType::OBSTACLE,Vector2i(47,26)),
			ElementData(ElementType::OBSTACLE,Vector2i(46,26)),
			ElementData(ElementType::OBSTACLE,Vector2i(49,25)),
			ElementData(ElementType::OBSTACLE,Vector2i(49,24)),
			ElementData(ElementType::OBSTACLE,Vector2i(49,23)),

		};
		//vector<LevelData> level_configurations;


		//cell data
		float cell_width;
		float cell_height;

		void initializeLevelData();
		void destroy();
	public:

		static const int number_of_rows = 28;
		static const int number_of_columns = 51;

		LevelModel();
		~LevelModel();

		void initialize(int width,int height);
		void update();
		void render();

		float getCellWidth();
		float getCellHeight();
		const vector<ElementData>& getElementDataList(int level_to_load);
	};
}