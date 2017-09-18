#pragma once
#include "Pawn.h"

class Mob : public Pawn
{
public:
	virtual void Draw() override;
	Mob(PawnController* controller, float rotation, Vector2D<> position);
	~Mob();
	friend class MobController;
};

