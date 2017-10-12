#include "UIInventoryDisplay.h"
#include "ItemInstanceInInv.h"
#include "ItemTemplate.h"
#include "ItemInfo.h"
#include "TextureManager.h"

void UIInventoryDisplay::Update(float & frame_time, sf::RenderWindow& main_window)
{
	auto& items = controlled_character->GetInventory().GetAllItems();
	main_window.draw(background);
	for (auto& i : items)
	{
		auto txture = TextureManager::GetTexture(i.second.GetItem()->GetOutfitID());
		sf::Sprite sprite;
		if (txture)
		{
			auto x = top_left_pos.GetFirst() + (i.first % 5) * 35.0;
			auto y = top_left_pos.GetSecond() + ((i.first / 5) + 1.0) * 35.0;
			sprite.setTexture(*txture);
			sprite.setPosition(x, y);
			main_window.draw(sprite);
			auto rect = sf::FloatRect(x, y, 35.0, 35.0);
			
			if (MultiTool::IsMouseInRect(rect))
			{
				auto&& ref = std::make_shared<ItemInfo>();
				UI::Instance().AddUIElement(ref);
				ref->SetItem(i.second.GetItem());

			}
		}
	}
}

UIInventoryDisplay::UIInventoryDisplay(std::shared_ptr<Character> controlled_character, bool updateThis = true):
	UIElement(updateThis),
	controlled_character(controlled_character)
{
	toRemove = false;
	if (!font.loadFromFile(std::string("D://WielkiRPG//RPG_SFML//arial.ttf")))
		std::cout << "BLAD LADOWANIA CZCIONKI";

	top_left_pos = Vector2D<>(1700, 400);
	auto texture_to_load = TextureManager::GetTexture(std::string("EQ_BACKGROUND"));
	if (texture_to_load != nullptr)
	{
		background.setTexture(*texture_to_load);
		auto x = texture_to_load->getSize().x;
		auto y = texture_to_load->getSize().y;
		background.setOrigin(0, 0);
		background.setPosition(top_left_pos.GetFirst(), top_left_pos.GetSecond());
	}
}

UIInventoryDisplay::~UIInventoryDisplay()
{
}
