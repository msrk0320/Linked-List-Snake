#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace Element
{
	enum class ElementType
	{
		OBSTACLE,
	};

	struct ElementData
	{
		ElementData(ElementType type, Vector2i position)
		{
			element_type = type;
			grid_position = position;
		}

		ElementType element_type;
		Vector2i grid_position;
	};
}