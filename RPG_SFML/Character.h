#pragma once
#include <iostream>
#include "Pawn.h"

class Character : public Pawn
{
public:
	void CharacterTest() { std::cout << "EE"; }
	virtual void Draw() override;
	Character(PawnController* controller, float rotation, Vector2D<> position);
	~Character();
	friend class CharacterController;
};

