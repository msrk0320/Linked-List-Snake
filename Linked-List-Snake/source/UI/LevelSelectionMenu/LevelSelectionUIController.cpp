#include <SFML/Graphics.hpp>
#include "../../include/UI/LevelSelectionMenu/LevelSelectionUIController.h"
#include "../../include/Global/Config.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Main/GameService.h"


using namespace Global;
using namespace Main;
using namespace sf;

namespace UI
{
	namespace LevelSelection
	{
		
		LevelSelectionUIController::LevelSelectionUIController()
		{
			createImage();
			createButtons();
		}
		LevelSelectionUIController::~LevelSelectionUIController()
		{
			destroy();
		}

		void LevelSelectionUIController::initialize()
		{
			initializeBackgroundImage();
			initializeButtons();
			registerButtonCallback();
		}

		void LevelSelectionUIController::update()
		{
			background_image->update();
			updateButtons();

		}

		void LevelSelectionUIController::render()
		{
			if (GameService::getGameState() == GameState::LEVEL_SELECTION)
			{
				background_image->render();
				renderButtons();
			}
		}

		void LevelSelectionUIController::show()
		{
			background_image->show();
			level_1_button->show();
			level_2_button->show();
			menu_button->show();
		}

		void LevelSelectionUIController::createImage()
		{
			background_image = new ImageView();
		}

		void LevelSelectionUIController::createButtons()
		{
			level_1_button = new ButtonView();
			level_2_button = new ButtonView();
			menu_button = new ButtonView();
		}

		void LevelSelectionUIController::initializeBackgroundImage()
		{
			RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
				
			background_image->initialize(Config::background_texture_path,
					game_window->getSize().x,
					game_window->getSize().y,
					Vector2f(0,0));
			background_image->setImageAlpha(background_alpha);
		}

		void LevelSelectionUIController::initializeButtons()
		{
			level_1_button->initialize("Level 1 Button",
				Config::level_one_button_texture_path,
				button_width,
				button_height,
				Vector2f(0, level_1_button_y_position));

			level_2_button->initialize("Level 2 Button",
				Config::level_two_button_texture_path,
				button_width,
				button_height,
				Vector2f(0, level_2_button_y_position));

			menu_button->initialize("Menu Button",
				Config::menu_button_texture_path,
				button_width,
				button_height,
				Vector2f(0, menu_button_y_position));

			level_1_button->setCentreAlinged();
			level_2_button->setCentreAlinged();
			menu_button->setCentreAlinged();

		}

		void LevelSelectionUIController::updateButtons()
		{
			level_1_button->update();
			level_2_button->update();
			menu_button->update();
		}

		void LevelSelectionUIController::renderButtons()
		{
			level_1_button->render();
			level_2_button->render();
			menu_button->render();
		}

		void LevelSelectionUIController::registerButtonCallback()
		{
			level_1_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::level1Callback, this));
			level_2_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::level2Callback, this));
			menu_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::menuCallback, this));
		}

		void LevelSelectionUIController::level1Callback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			ServiceLocator::getInstance()->getLevelService()->createLevel(LevelNumber::ONE);
			GameService::setGameState(GameState::GAMEPLAY);

		}

		void LevelSelectionUIController::level2Callback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			ServiceLocator::getInstance()->getLevelService()->createLevel(LevelNumber::TWO);
			GameService::setGameState(GameState::GAMEPLAY);
		}

		void LevelSelectionUIController::menuCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			GameService::setGameState(GameState::MAIN_MENU);
		}

		void LevelSelectionUIController::destroy()
		{
			delete(background_image);
			delete(level_1_button);
			delete(level_2_button);
			delete(menu_button);
		}
	}
}