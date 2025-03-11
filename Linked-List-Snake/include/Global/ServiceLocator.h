#pragma once
#include "Graphics/GraphicService.h"
#include "Event/EventService.h"
#include "UI/UIService.h"
#include "Sound/SoundService.h"
#include "Level/LevelService.h"
#include "Time/TimeService.h"
#include "Player/PlayerService.h"
#include "Element/ElementService.h"
#include "Food/FoodService.h"

namespace Global
{
    class ServiceLocator
    {
    private:
        Event::EventService* event_service;
        Graphics::GraphicService* graphic_service;
        Sound::SoundService* sound_service;
        Level::LevelService* level_service;
        UI::UIService* ui_service;
        Time::TimeService* time_service;
		Player::PlayerService* player_service;
        Element::ElementService* element_service;
        Food::FoodService* food_service;

        ServiceLocator();
        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        Event::EventService* getEventService();
        Graphics::GraphicService* getGraphicService();
        Sound::SoundService* getSoundService();
        Level::LevelService* getLevelService();
        UI::UIService* getUIService();
        Time::TimeService* getTimeService();
		Player::PlayerService* getPlayerService();
        Element::ElementService* getElementService();
        Food::FoodService* getFoodService();
        void deleteServiceLocator();
    };
}