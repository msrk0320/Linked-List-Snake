#include "../../include/Food/FoodItem.h"
#include "../../include/Global/Config.h"
#include "../../include/Level/LevelView.h"
#include <iostream>

using namespace std;
using namespace Global;
using namespace Level;

namespace Food
{
	
	
	FoodItem::FoodItem()
	{
		food_image = new ImageView();

	}
	
	FoodItem::~FoodItem()
	{
		destroy();
	}

	void FoodItem::initialize(Vector2i position, float width, float height, FoodType type)
	{
		food_type = type;
		food_width = width;
		food_height = height;
		grid_position = position;

		createFoodImage();
	}
	
	void FoodItem::update()
	{
		food_image->update();
	}
	
	void FoodItem::render()
	{
		food_image->render();
	}

	FoodType FoodItem::getFoodType()
	{
		return food_type;
	}

	Vector2i FoodItem::getFoodPosition()
	{
		return grid_position;
	}

	void FoodItem::createFoodImage()
	{
		food_image->initialize(getFoodTexturePath(), food_width, food_height, getFoodScreenPosition(grid_position));
		food_image->show();
	}

	Vector2f FoodItem::getFoodScreenPosition(Vector2i position)
	{
		//problem
		float food_position_x = LevelView::border_offset_top + (position.x * food_height);
		float food_position_y = LevelView::border_offset_left + (position.y * food_width);

		return Vector2f(food_position_y,food_position_x);
	}

	String FoodItem::getFoodTexturePath()
	{
		switch (food_type)
		{
		case Food::FoodType::APPLE:
			return Config::apple_texture_path;

		case Food::FoodType::MANGO:
			return Config::mango_texture_path;

		case Food::FoodType::ORANGE:
			return Config::mango_texture_path;

		case Food::FoodType::PIZZA:
			return Config::pizza_texture_path;

		case Food::FoodType::BURGER:
			return Config::burger_texture_path;

		case Food::FoodType::CHEESE:
			return Config::cheese_texture_path;

		case Food::FoodType::POISION:
			return Config::poision_texture_path;

		case Food::FoodType::ALCOHOL:
			return Config::alcohol_texture_path;

		}
	}

	void FoodItem::destroy()
	{
		delete(food_image);
	}
}