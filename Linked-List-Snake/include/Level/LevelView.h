#pragma once
#include <SFML/Graphics.hpp>
#include <UI/UIElement/RectangleShapeView.h>

using namespace UI::UIElement;


namespace Level {
	class LevelController;
	class LevelView {
	private:
		void createViews();
		void initializeBackground();
		void initializeBorder();
		void calculateGridExtents();
		void Destroy();
		LevelController* levelController;

	public:
		LevelView();
		~LevelView();

		void initialize();
		void render();
		void update();

	private:
		const sf::Color background_color = sf::Color(180, 200, 160);
		RectangleShapeView* background_rectangle;
		RectangleShapeView* border_rectangle;
		sf::Color border_color = sf::Color::Black;
		float grid_width;
		float grid_height;

	public:
		static const int border_thickness = 10;
		static const int border_offset_left = 40;
		static const int border_offset_top = 40;
		
		float getGridWidth();
		float getGridHeight();
	};
}