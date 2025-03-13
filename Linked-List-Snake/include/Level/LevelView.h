#pragma once
#include <SFML/Graphics.hpp>
#include "../../include/UI/UIElement/RectangleShapeView.h"

using namespace UI::UIElement;
using namespace sf;

namespace Level
{
	class LevelController;
	class LevelView
	{
	private:

		//Background: properties
		RectangleShapeView* background_rectangle;
		const Color background_color = Color(180, 200, 160);

		//Border: Properties
		RectangleShapeView* border_rectangle;
		const Color border_color = Color::Black;

		float grid_width;
		float grid_height;

		LevelController* level_controller;

		//Background: methods
		void initializeBackground();

		//Border: methods
		void initializeBorder();

		void createViews();
		void updateViews();
		void renderViews();

		void destroy();

	public:

		//Border: Properties
		static const int border_thickness = 10;
		static const int border_offset_left = 90;
		static const int border_offset_top = 90;

		LevelView(LevelController* controller);
		~LevelView();

		void initialize();
		void update();
		void render();

		float getGridWidth();
		float getGridHeight();
		void calculateGridExtents();
	};
}