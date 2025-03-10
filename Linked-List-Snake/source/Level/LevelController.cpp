#include "../../include/Level/LevelController.h"
#include "../../include/Level/LevelModel.h"
#include "../../include/Level/LevelView.h"

namespace Level {

	LevelController::LevelController()
	{
		levelModel = new LevelModel();
		levelView = new LevelView();
	}

	LevelController::~LevelController()
	{
		delete levelView;
		delete levelModel;
	}

	void LevelController::initialize()
	{
		levelView->initialize();
		levelModel->initialize(levelView->getGridWidth(), levelView->getGridHeight());
	}

	void LevelController::render()
	{
		levelView->render();
	}

	void LevelController::update()
	{
		levelView->update();
	}

	float LevelController::getCellWidth()
	{
		return levelModel->getCellWidth();
	}

	float LevelController::getCellHeight()
	{
		return levelModel->getCellHeight();
	}
}