#include "../../include/Level/LevelModel.h"

namespace Level
{
   
    LevelModel::LevelModel()
    {
    }

    LevelModel::~LevelModel()
    {
    }

    void LevelModel::initialize(int width,int height)
    {
        cell_width =static_cast<float>(width) / number_of_columns;
        cell_height = static_cast<float>(height) / number_of_rows;

        initializeLevelData();
    }

    void LevelModel::update()
    {
    }

    void LevelModel::render()
    {
    }

    float LevelModel::getCellWidth()
    {
        return cell_width;
    }

    float LevelModel::getCellHeight()
    {
        return cell_height;
    }

    const vector<ElementData>& LevelModel::getElementDataList(int level_to_load)
    {
        return *level_configurations[level_to_load].element_data_list;
    }

    void LevelModel::initializeLevelData()
    {
        level_configurations.push_back(LevelData(LevelNumber::ONE,&level_1_element_list));
        level_configurations.push_back(LevelData(LevelNumber::TWO,&level_2_element_list));
    }

    void LevelModel::destroy()
    {

    }
}