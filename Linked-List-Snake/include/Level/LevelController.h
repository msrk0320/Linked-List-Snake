#pragma once
#include <vector>
#include "Element/ElementData.h"
using namespace std;
using namespace Element;
namespace Level
{
	class LevelModel;
	class LevelView;

	class LevelController
	{
	private:
		LevelModel* level_model;
		LevelView* level_view;

		void destroy();

	public:
		LevelController();
		~LevelController();

		void initialize();
		void update();
		void render();

		float getCellWidth();
		float getCellHeight();

		const vector<ElementData>& getElementDataList(int level_to_load);
	};
}