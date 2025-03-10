#include "UI/LevelSelection/LevelSelectionUIController.h"
#include "Main/GameService.h"
#include "Graphics/GraphicService.h"
#include "Sound/SoundService.h"
#include "UI/UIElement/ButtonView.h"
#include "UI/UIElement/ImageView.h"
#include "Global/Config.h"
#include "Level/LevelService.h"
#include <SFML/Graphics.hpp>

using namespace sf;
namespace UI
{
	namespace LevelSelection {

		using namespace UIElement;
		using namespace Global;
		using namespace Sound;
		using namespace Main;

		LevelSelectionUIController::LevelSelectionUIController()
		{
			createImage();
			createButtons();
		}

		void LevelSelectionUIController::createImage()
		{
			background_Image = new ImageView();
		}

		void LevelSelectionUIController::createButtons()
		{
			levelOne_Button = new ButtonView();
			levelTwo_Button = new ButtonView();
			menu_Button = new ButtonView();
		}

		LevelSelectionUIController::~LevelSelectionUIController()
		{
			Destroy();
		}

		float LevelSelectionUIController::calculateLeftOffsetForButton()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			return (static_cast<float>(game_window->getSize().x) / 2) - buttonWidth / 2;
		}

		void LevelSelectionUIController::render()
		{
			background_Image->render();
			levelOne_Button->render();
			levelTwo_Button->render();
			menu_Button->render();
		}

		void LevelSelectionUIController::show()
		{
			background_Image->show();
			levelOne_Button->show();
			levelTwo_Button->show();
			menu_Button->show();
		}

		void LevelSelectionUIController::update()
		{
			background_Image->update();
			levelOne_Button->update();
			levelTwo_Button->update();
			menu_Button->update();
		}

		void LevelSelectionUIController::initialize()
		{
			initializeBackgroundImage();
			initializeButtons();
			registerButtons();
		}

		void LevelSelectionUIController::initializeButtons()
		{
			levelOne_Button->initialize("Play Button", Config::level_one_button_texture_path, buttonWidth, buttonHeight, Vector2f(0, levelOne_Button_Position));
			levelTwo_Button->initialize("Play Button", Config::level_two_button_texture_path, buttonWidth, buttonHeight, Vector2f(0, levelTwo_Button_Position));
			menu_Button->initialize("Play Button", Config::menu_button_texture_path, buttonWidth, buttonHeight, Vector2f(0, menu_Button_Position));

			levelOne_Button->setCentreAlinged();
			levelTwo_Button->setCentreAlinged();
			menu_Button->setCentreAlinged();
		}

		void LevelSelectionUIController::initializeBackgroundImage()
		{
			RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			background_Image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, Vector2f(0, 0));
			background_Image->setImageAlpha(background_alpha);
		}


		void LevelSelectionUIController::registerButtons()
		{
			levelOne_Button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::levelOne_Button_Callback, this));
			levelTwo_Button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::levelTwo_Button_Callback, this));
			menu_Button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::menu_Button_Callback, this));
		}

		void LevelSelectionUIController::levelOne_Button_Callback()
		{
			GameService::setGameState(GameState::GAMEPLAY);
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			ServiceLocator::getInstance()->getLevelService()->createLevel(Level::LevelNumber::ONE);
		}

		void LevelSelectionUIController::levelTwo_Button_Callback()
		{
			GameService::setGameState(GameState::GAMEPLAY);
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			ServiceLocator::getInstance()->getLevelService()->createLevel(Level::LevelNumber::TWO);
		}

		void LevelSelectionUIController::menu_Button_Callback()
		{
			GameService::setGameState(GameState::MAIN_MENU);
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
		}

		void LevelSelectionUIController::Destroy()
		{
			delete(levelOne_Button);
			delete(levelTwo_Button);
			delete(menu_Button);
			delete(background_Image);
		}

	}
}