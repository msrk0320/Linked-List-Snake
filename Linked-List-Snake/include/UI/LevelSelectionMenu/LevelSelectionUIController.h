#pragma once
#include "UI/UIElement/ImageView.h"
#include "UI/UIElement/ButtonView.h"
#include "UI/Interface/IUIController.h"

using namespace UI::UIElement;

namespace UI
{
	namespace LevelSelection
	{
		class LevelSelectionUIController : public Interface::IUIController
		{
		private:
			//button
			const float button_width = 400.f;
			const float button_height = 140.f;

			//positions
			const float level_1_button_y_position = 500.f;
			const float level_2_button_y_position = 700.f;
			const float menu_button_y_position = 900.f;

			//alpha
			const float background_alpha = 85.f;

			//Button and background
			ImageView* background_image;

			ButtonView* level_1_button;
			ButtonView* level_2_button;
			ButtonView* menu_button;

			void createImage();
			void createButtons();
			void initializeBackgroundImage();
			void initializeButtons();

			void updateButtons();
			void renderButtons();

			void registerButtonCallback();
			void level1Callback();
			void level2Callback();
			void menuCallback();
			void destroy();
		public:

			LevelSelectionUIController();
			~LevelSelectionUIController();

			void initialize();
			void update();
			void render();
			void show();
		};
	}
}