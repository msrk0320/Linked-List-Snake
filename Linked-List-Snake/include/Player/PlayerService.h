#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
using namespace sf;
using namespace std;
namespace Player
{
	class SnakeController;
	class PlayerService
	{
	private:
		SnakeController* snake_controller;

		void destroy();

	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();

		void createController();
		void spawnPlayer();
		vector<Vector2i> getSnakePositionList();

	};
}