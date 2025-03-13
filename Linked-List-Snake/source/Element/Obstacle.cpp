
#include "../../include/Element/Obstacle.h"
#include"../../include/Global/Config.h"
#include "../../include/Level/LevelView.h"

using namespace Global;
using namespace Level;

namespace Element
{
	
	Obstacle::Obstacle()
	{
		obstacle_image = new ImageView();
	}

	Obstacle::~Obstacle()
	{
		destroy();
	}

	void Obstacle::initialize(Vector2i position, float width, float height)
	{
		grid_position = position;
		cell_width = width;
		cell_height = height;

		initializeObstacleImage();
	}

	void Obstacle::update()
	{
		obstacle_image->update();
	}

	void Obstacle::render()
	{
		obstacle_image->render();
	}

	Vector2i Obstacle::getObstaclePosition()
	{
		return grid_position;
	}

	void Obstacle::initializeObstacleImage()
	{
		Vector2f screen_position = getObstacleScreenPosition();
		obstacle_image->initialize(Config::obstacle_texture_path,cell_width,cell_height,screen_position);
		obstacle_image->show();
	}

	Vector2f Obstacle::getObstacleScreenPosition()
	{
		float screen_position_x = LevelView::border_offset_top + (cell_width * grid_position.x);
		float screen_position_y = LevelView::border_offset_left + (cell_height * grid_position.y);
		return Vector2f(screen_position_x, screen_position_y);
	}

	void Obstacle::destroy()
	{
		delete(obstacle_image);
	}
}