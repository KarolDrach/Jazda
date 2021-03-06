#include "Game.h"
#include "TextureManager.h"
#include "ItemsManager.h"
#include "Character.h"
#include "CharacterController.h"
#include "PawnController.h"
#include "Mob.h"
#include "MobController.h"
#include "UI.h"
#include "FPSCounter.h"
#include "UIInventoryDisplay.h"
#include "ItemInstanceOnMap.h"
#include "ItemController.h"
#include "MultiTool.h"

using namespace MultiTool;

Game::Game(): main_window(sf::VideoMode(1920, 1080), "SFML works!"),
			  main_status(INITIALIZE),
			  current_level(Level())
{
	this->npc_attributes_symbols = LoadFromFileAsVector<std::string>(std::string("D://test.txt"));
    main_view = main_window.getDefaultView();
	ItemsManager::Instance().LoadItemsFromFile(std::string("D://test_item.txt"));
	TextureManager::Instance().Load(std::string("T_UP"), std::string("D://textures//t_up.png"));
	TextureManager::Instance().Load(std::string("T_DOWN"), std::string("D://textures//t_down.png"));
	TextureManager::Instance().Load(std::string("T_LEFT"), std::string("D://textures//t_left.png"));
	TextureManager::Instance().Load(std::string("T_RIGHT"), std::string("D://textures//t_right.png"));
	TextureManager::Instance().Load(std::string("FIREBALL"), std::string("D://textures//fireball.png"));
	TextureManager::Instance().Load(std::string("ITEM_TEST"), std::string("D://textures//item.png"));
	TextureManager::Instance().Load(std::string("EQ_BACKGROUND"), std::string("D://textures//eq_bgr.png"));
	TextureManager::Instance().Load(std::string("ITEM_INFO_BACKGROUND"), std::string("D://textures//item_info_bgr.png"));
}

Game::~Game()
{
	if (main_window.isOpen())
	{
		main_window.close();
	}
}

void Game::GameLoop()
{
	sf::Clock GameClock;
	float frame_time = 1.0f / 60.0f;
	main_status = RUN;
	auto test2 = std::make_shared<Character>(0.0, Vector2D<>(190.0, 800.0));
	for (int i = 1; i < 10; i++)
	{	
		auto item = std::make_shared<ItemInstanceOnMap>(ItemsManager::GetItem(std::string("MIECZOR")), Vector2D<>(250.0 + i * 15.0, 900.0));
		auto item2 = std::make_shared<ItemInstanceOnMap>(ItemsManager::GetItem(std::string("MIECZOR")), Vector2D<>(250.0, 900.0 + i * 15.0));
		current_level.AddActor(item);
		current_level.AddActor(item2);
		item->SetController(std::make_shared<ItemController>());
		item2->SetController(std::make_shared<ItemController>());
	}
	current_level.AddActor(test2);
	test2->SetController(std::make_shared<CharacterController>());
	
	UI& ui = UI::Instance();
	UIInventoryDisplay::Instance().SetCharacter(test2);

	while (main_status != TO_CLOSE)
	{
		float start_time = GameClock.getElapsedTime().asSeconds();

		sf::Event event;
		while (main_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				main_status = TO_CLOSE;

			if (event.type == sf::Event::Resized)
			{
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				main_window.setView(sf::View(visibleArea));
			}
		}
		main_window.clear();
		main_view.setCenter(test2->GetPosition().GetFirst(), test2->GetPosition().GetSecond());
		current_level.UpdateAll(frame_time);
		current_level.DrawAll(frame_time);
		ui.Update(frame_time, main_window, main_view);
		
		main_window.display();
		frame_time = GameClock.getElapsedTime().asSeconds() - start_time;
	}
}
