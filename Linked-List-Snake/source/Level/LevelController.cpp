#include "../../include/Level/LevelController.h"
#include "../../include/Level/LevelModel.h"
#include "../../include/Level/LevelView.h"

namespace Level
{
    
    LevelController::LevelController()
    {
        level_model = new LevelModel();
        level_view = new LevelView(this);
    }

    LevelController::~LevelController()
    {
        destroy();
    }

    void LevelController::initialize()
    {
        level_view->initialize();
        level_model->initialize(level_view->getGridWidth(),level_view->getGridHeight() );
    }

    void LevelController::update()
    {
        level_view->update();
    }

    void LevelController::render()
    {
        level_view->render();
    }

    float LevelController::getCellWidth()
    {
        return level_model->getCellWidth();
    }

    float LevelController::getCellHeight()
    {
        return level_model->getCellHeight();
    }

    const vector<ElementData>& LevelController::getElementDataList(int level_to_load)
    {
        return level_model->getElementDataList(level_to_load);
    }

    void LevelController::destroy()
    {
        delete(level_model);
        delete(level_view);
    }

}