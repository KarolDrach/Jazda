#pragma once
#include "Pawn.h"
#include <memory.h>

class ItemTemplate;

class ItemInstanceOnMap : public Pawn
{
private:
	std::shared_ptr<ItemTemplate> item;
public:
	std::shared_ptr<ItemTemplate> GetItemPointer() { return item; }
	virtual void Draw() override;
	ItemInstanceOnMap(std::shared_ptr<ItemTemplate> item, Vector2D<> position);
	ItemInstanceOnMap(std::shared_ptr<Actor> actor);
	~ItemInstanceOnMap();
};

