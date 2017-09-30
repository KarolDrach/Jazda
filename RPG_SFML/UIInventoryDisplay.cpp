#include "UIInventoryDisplay.h"
#include "ItemInstanceInInv.h"
#include "ItemTemplate.h"

void UIInventoryDisplay::Update(float & frame_time, sf::RenderWindow& main_window)
{
	auto items = controlled_character->GetInventory().GetAllItems();

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

UIInventoryDisplay::UIInventoryDisplay(std::shared_ptr<Character> controlled_character):
	controlled_character(controlled_character)
{
	updateThis = true;
	if (!font.loadFromFile(std::string("D://WielkiRPG//RPG_SFML//arial.ttf")))
		std::cout << "BLAD LADOWANIA CZCIONKI";
}

UIInventoryDisplay::UIInventoryDisplay(std::shared_ptr<Character> controlled_character, bool updateThis):
	UIElement(updateThis),
	controlled_character(controlled_character)
{
	if (!font.loadFromFile(std::string("D://WielkiRPG//RPG_SFML//arial.ttf")))
		std::cout << "BLAD LADOWANIA CZCIONKI";
}

UIInventoryDisplay::~UIInventoryDisplay()
{
}
