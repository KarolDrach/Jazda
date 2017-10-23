#pragma once
#include <iostream>
#include "Pawn.h"
#include "Inventory.h"

class Character : public Pawn
{
private:
	Inventory inventory;
public:
	const float fire_rate_delay = 0.5;
	float fire_rate_reload;
	const float picking_items_delay = 0.5;
	float picking_items_reload;

	Inventory& GetInventory() { return inventory; }
	virtual void Draw() override;
	Character(float rotation, Vector2D<> position);
	~Character();
	friend class CharacterController;
};

