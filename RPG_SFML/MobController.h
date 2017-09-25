#pragma once
#include "PawnController.h"
#include "Game.h"

class Mob;

class MobController : public PawnController
{
private:
	Mob* controlled_pawn;
public:
	virtual void Update(float &frame_time) override;
	virtual bool Possess(Pawn* pawn) override;
	virtual inline bool IsPossesed();
	MobController();
	~MobController();
};

