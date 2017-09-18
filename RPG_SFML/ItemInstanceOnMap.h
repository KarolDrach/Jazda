#pragma once
#include "Pawn.h"

class ItemTemplate;

class ItemInstanceOnMap : public Pawn
{
private:
	ItemTemplate* item;
public:
	virtual void Draw() override;
	ItemInstanceOnMap(ItemTemplate* item, PawnController* controller, Vector2D<> position);
	~ItemInstanceOnMap();
};

