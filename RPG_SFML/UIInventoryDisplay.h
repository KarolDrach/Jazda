#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "UI.h"
#include "Character.h"

class UIInventoryDisplay : public UIElement
{
private:
	UIInventoryDisplay();
	sf::Sprite background;
	Vector2D<> top_left_pos;
	sf::Font font;
	std::shared_ptr<Character> controlled_character;
public:
	UIInventoryDisplay(const UIInventoryDisplay &) = delete;
	void operator=(const UIInventoryDisplay &) = delete;

	inline static UIInventoryDisplay& Instance()
	{
		static UIInventoryDisplay instance;
		return instance;
	}

	void SetCharacter(std::shared_ptr<Character> ch) { controlled_character = ch; }
	std::shared_ptr<Character> GetCharacter() { return controlled_character; }
	virtual void Update(float& frame_time, sf::RenderWindow& main_window) override;
	~UIInventoryDisplay();
};

