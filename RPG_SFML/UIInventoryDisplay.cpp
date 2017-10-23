#include "UIInventoryDisplay.h"
#include "ItemInstanceInInv.h"
#include "ItemTemplate.h"
#include "UnitTests.h"
#include "ItemInfo.h"
#include "TextureManager.h"

void UIInventoryDisplay::Update(float & frame_time, sf::RenderWindow& main_window)
{
	auto& items = controlled_character->GetInventory().GetAllItems();
	main_window.draw(background);
	for (auto& i : items)
	{
		if (i.second.GetItem() != nullptr)
		{
			auto texture_to_load = TextureManager::GetTexture(i.second.GetItem()->GetOutfitID());
			if (texture_to_load)
			{
				sf::Sprite sprite;
				auto x = top_left_pos.GetFirst() + (i.first % 5) * 35.0;
				auto y = top_left_pos.GetSecond() + ((i.first / 5) + 1.0) * 35.0;
				sprite.setTexture(*texture_to_load);
				sprite.setPosition(x, y);
				main_window.draw(sprite);

				if (MultiTool::IsMouseOverSprite(sprite))
				{
					if (!ItemInfo::Instance().GetUpdateThis())
					{
						ItemInfo::Instance().SetTopLeftPos(Vector2D<>(x + 15.0, y + 15.0));
						ItemInfo::Instance().SetUpdateThis(true);
						ItemInfo::Instance().SetItem(i.second.GetItem());
					}
				}
				else
				{
					ItemInfo::Instance().SetUpdateThis(false);
				}
			}
		}		
	}
}

UIInventoryDisplay::UIInventoryDisplay()
{
	toRemove = false;
	if (!font.loadFromFile(std::string("D://WielkiRPG//RPG_SFML//arial.ttf")))
		UnitTests::PrintConsoleFailed("UIInventoryDisplay loading font bad");
	else
		UnitTests::PrintConsolePassed("UIInventoryDisplay loading font OK");

	top_left_pos = Vector2D<>(1600, 400);
	auto texture_to_load = TextureManager::GetTexture(std::string("EQ_BACKGROUND"));
	if (texture_to_load != nullptr)
	{
		UnitTests::PrintConsolePassed("UIInventoryDisplay loading background texture OK");
		background.setTexture(*texture_to_load);
		auto x = texture_to_load->getSize().x;
		auto y = texture_to_load->getSize().y;
		background.setOrigin(0, 0);
		background.setPosition(top_left_pos.GetFirst(), top_left_pos.GetSecond());
	}
	else
	{
		UnitTests::PrintConsoleFailed("UIInventoryDisplay loading background texture failed");
	}
}

UIInventoryDisplay::~UIInventoryDisplay()
{
}
