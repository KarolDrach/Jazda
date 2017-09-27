#pragma once
#include "UI.h"
#include "Character.h"

class UIInventoryDisplay :
	public UIElement
{
private:
	Character* controlled_character;
public:
	void SetCharacter(Character* ch) { controlled_character = ch; }
	Character* GetCharacter() { return controlled_character; }
	virtual void Update(float& frame_time, sf::RenderWindow& main_window) override;
	UIInventoryDisplay(Character* controlled_character);
	UIInventoryDisplay(Character* controlled_character, bool updateThis);
	~UIInventoryDisplay();
};

