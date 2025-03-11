#pragma once
#include <vector>
#include "LevelModel.h"
#include <Element/ElementData.h>

using namespace Element;
namespace Level
{
    class LevelView;

    class LevelController
    {
    private:
        LevelModel* level_model;
        LevelView* level_view;

    public:
        LevelController();
        ~LevelController();

        void initialize();
        void update();
        void render();

        float getCellWidth();
        float getCellHeight();
        const std::vector<ElementData>& getElementDataList(int level_to_load);
    };
}