#pragma once
#include"Food/FoodType.h"
#include "SFML/Graphics.hpp"
#include "../../include/UI/UIElement/ImageView.h"

using namespace sf;
using namespace UI::UIElement;

namespace Food
{
	class FoodItem
	{
	private:
		ImageView* food_image;
		FoodType food_type;

		float food_width;
		float food_height;
		Vector2i grid_position;
		
		void createFoodImage();
		Vector2f getFoodScreenPosition(Vector2i position);
		String getFoodTexturePath();
		
		void destroy();

	public:
		FoodItem();
		~FoodItem();
		static const int number_of_food = 8;
		void initialize(Vector2i position, float width, float height, FoodType type);
		void update();
		void render();

		FoodType getFoodType();
		Vector2i getFoodPosition();
	};
}