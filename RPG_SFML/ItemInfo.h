#pragma once
#include <SFML/Graphics.hpp>
#include "ItemTemplate.h"
#include "Vector2D.h"
#include "UI.h"

class ItemInfo : public UIElement
{
private:
	Vector2D<> top_left_pos;
	sf::Sprite background;
	sf::Font font;
	std::shared_ptr<ItemTemplate> controlled_item;

	ItemInfo();
public:
	ItemInfo(const ItemInfo &) = delete;
	void operator=(const ItemInfo &) = delete;
	static inline ItemInfo& Instance()
	{
		ItemInfo instance;
		return instance;
	}
	virtual void Update(float& frame_time, sf::RenderWindow& main_window) override;
	void SetItem(std::shared_ptr<ItemTemplate> item) { controlled_item = item; }
	auto GetItem() { return controlled_item; }
	void SetTopLeftPos(Vector2D<>& pos) { top_left_pos = pos; }
	auto GetTopLeftPos() { return top_left_pos; }
	
	~ItemInfo();
};

