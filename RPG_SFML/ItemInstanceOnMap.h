#pragma once
#include "Pawn.h"

class ItemTemplate;

class ItemInstanceOnMap : public Pawn
{
private:
	ItemTemplate* item;
public:
	ItemTemplate* GetItemPointer() { return item; }
	virtual void Draw() override;
	ItemInstanceOnMap(ItemTemplate* item, PawnController* controller, Vector2D<> position);
	ItemInstanceOnMap(Actor* actor);
	~ItemInstanceOnMap();
};

