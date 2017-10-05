#include "UIInventoryDisplay.h"
#include "ItemInstanceInInv.h"
#include "ItemTemplate.h"
#include "TextureManager.h"

void UIInventoryDisplay::Update(float & frame_time, sf::RenderWindow& main_window)
{
	auto items = controlled_character->GetInventory().GetAllItems();

	main_window.draw(background);
	for (auto&i : items)
	{
		sf::Text text;
		text.setFont(font);
		text.setPosition(-400, 700);
		text.setFillColor(sf::Color::Green);
		text.setString((i.GetItem())->GetName());
		main_window.draw(text);
	}
}

UIInventoryDisplay::UIInventoryDisplay(std::shared_ptr<Character> controlled_character, bool updateThis = true):
	UIElement(updateThis),
	controlled_character(controlled_character)
{
	if (!font.loadFromFile(std::string("D://WielkiRPG//RPG_SFML//arial.ttf")))
		std::cout << "BLAD LADOWANIA CZCIONKI";

	top_left_pos = Vector2D<>(1300, 500);
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
