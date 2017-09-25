#pragma once
#include <iostream>
#include "Pawn.h"
#include "Inventory.h"

class Character : public Pawn
{
	Inventory inventory;
public:
	Inventory& GetInventory() { return inventory; }
	virtual void Draw() override;
	Character(PawnController* controller, float rotation, Vector2D<> position);
	~Character();
	friend class CharacterController;
};

