#pragma once
#include <UI/UIElement/ImageView.h>
#include <UI/UIElement/ButtonView.h>
#include "UI/Interface/IUIController.h"

namespace UI {
	namespace LevelSelection {
		class LevelSelectionUIController : public Interface::IUIController {
		private:
			void Destroy();

			UIElement::ImageView* background_Image;
			UIElement::ButtonView* levelOne_Button;
			UIElement::ButtonView* levelTwo_Button;
			UIElement::ButtonView* menu_Button;

			const float levelOne_Button_Position = 500.0f;
			const float levelTwo_Button_Position = 700.0f;
			const float menu_Button_Position = 900.0f;
			const float buttonWidth = 400.0f;
			const float buttonHeight = 140.f;

			const float background_alpha = 85.0f;

		public:
			LevelSelectionUIController();
			~LevelSelectionUIController();

			void initializeBackgroundImage();
			float calculateLeftOffsetForButton();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

			void createImage();
			void createButtons();
			void initializeButtons();
			void registerButtons();

			void levelOne_Button_Callback();
			void levelTwo_Button_Callback();
			void menu_Button_Callback();

		};
	}
}