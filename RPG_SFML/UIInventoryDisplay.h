#pragma once
#include <memory>
#include "UI.h"
#include "Character.h"

class UIInventoryDisplay : public UIElement
{
private:
	sf::Font font;
	std::shared_ptr<Character> controlled_character;
public:
	void SetCharacter(std::shared_ptr<Character> ch) { controlled_character = ch; }
	std::shared_ptr<Character> GetCharacter() { return controlled_character; }
	virtual void Update(float& frame_time, sf::RenderWindow& main_window) override;
	UIInventoryDisplay(std::shared_ptr<Character> controlled_character);
	UIInventoryDisplay(std::shared_ptr<Character> controlled_character, bool updateThis);
	~UIInventoryDisplay();
};

