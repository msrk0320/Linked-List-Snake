#pragma once
#include "Level/LevelNumber.h"
#include "Element/ElementData.h"
#include <vector>

using namespace std;
using namespace Element;

namespace Level
{
	struct LevelData
	{
		LevelData(LevelNumber ind, vector<ElementData>* data_list)
		{
			level_index = ind;
			element_data_list = data_list;
		}

		LevelNumber level_index;
		vector<ElementData>* element_data_list;
	};
}