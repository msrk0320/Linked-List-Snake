#pragma once
#include <SFML/System/Vector2.hpp>
#include "Level/LevelData.h"
#include <vector>
#include "Global/Config.h"
#include "Element/ElementData.h"

using namespace Element;
using namespace Global;
namespace Level
{
   class LevelModel
   {
   private:

       float cell_width=0.0f;
       float cell_height=0.0f;

       std::vector<Element::ElementData> level_one_element_list = {};
       std::vector<Element::ElementData> level_two_element_list ={
           //TOP-LEFT
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 1)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(2, 1)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(3, 1)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 2)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 3)),

   //TOP-RIGHT
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(49, 1)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(49, 2)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(49, 3)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(48, 1)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(47, 1)),

   //BOTTOM-LEFT
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 26)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 25)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 24)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(2, 26)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(3, 26)),

   //BOTTOM-RIGHT
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(49, 26)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(49, 25)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(49, 24)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(48, 26)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(47, 26)),

   //CENTER-TOP-BAR
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(21, 11)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(22, 11)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(23, 11)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(24, 11)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(25, 11)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(26, 11)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(27, 11)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(28, 11)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(29, 11)),

   //CENTER-BOTTOM-BAR
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(21, 15)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(22, 15)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(23, 15)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(24, 15)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(25, 15)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(26, 15)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(27, 15)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(28, 15)),
   Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(29, 15)),
       };

       std::vector<LevelData> level_configurations;

   public:
       static const int number_of_rows = 28;
       static const int number_of_columns = 50;

       LevelModel();
       ~LevelModel();

       void initialize(int width, int height);

       float getCellWidth();
       float getCellHeight();
       void initializeLevelData();
       const std::vector<ElementData>& getElementDataList(int level_to_load);
   };
}