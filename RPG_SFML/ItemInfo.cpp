#include "ItemInfo.h"
#include "TextureManager.h"
#include "UnitTests.h"

void ItemInfo::Update(float & frame_time, sf::RenderWindow & main_window)
{
	if (updateThis && controlled_item)
	{
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
	this->updateThis = false;
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
