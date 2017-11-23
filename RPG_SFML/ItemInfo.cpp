#include <vector>
#include "ItemInfo.h"
#include "Game.h"
#include "TextureManager.h"
#include "UIInventoryDisplay.h"
#include "UnitTests.h"

void ItemInfo::Update(float & frame_time, sf::RenderWindow & main_window)
{
	auto inv = UIInventoryDisplay::Instance().GetCharacter()->GetInventory();
	for (auto& item : inv.GetAllItems())
	{
		controlled_items.emplace_back(item.second);
	}

	std::vector<ItemInstanceOnMap> items_on_map(99);
	for (auto i : Game::Instance().GetCurrentLevel().GetAllActors())
	{
		if (auto result = std::dynamic_pointer_cast<std::shared_ptr<ItemInstanceOnMap>>(i))
		{
			controlled_items.emplace_back(*result);
		}
	}

	if (updateThis /*&& controlled_item*/)
	{
		for (auto& i : controlled_items)
		{
			auto var = std::get<0>(i);
		}
		background.setPosition(top_left_pos.GetFirst(), top_left_pos.GetSecond());
		main_window.draw(background);
		sf::Text text;
		text.setFont(font);
		text.setFillColor(sf::Color::Yellow);
		text.setString(controlled_item->GetName());
		text.setPosition(top_left_pos.GetFirst() + 20.0, top_left_pos.GetSecond() + 20.0);
		main_window.draw(text);
	}
}

ItemInfo::ItemInfo()
{
	this->updateThis = true;
	if (!font.loadFromFile(std::string("D://WielkiRPG//RPG_SFML//arial.ttf")))
		std::cout << "BLAD LADOWANIA CZCIONKI";

	auto texture_to_load = TextureManager::GetTexture(std::string("ITEM_INFO_BACKGROUND"));
	if (texture_to_load != nullptr)
	{
		UnitTests::PrintConsolePassed("ItemInfo loading background texture ok");
		background.setTexture(*texture_to_load);
		auto x = texture_to_load->getSize().x;
		auto y = texture_to_load->getSize().y;
		background.setOrigin(0, 0);
		background.setPosition(top_left_pos.GetFirst(), top_left_pos.GetSecond());
	}
	else
	{
		UnitTests::PrintConsoleFailed("ItemInfo loading background texture");
	}
}


ItemInfo::~ItemInfo()
{
}
