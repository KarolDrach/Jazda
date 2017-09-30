#pragma once
#include <memory>
#include "PawnController.h"
#include "Game.h"

class Mob;

class MobController : public PawnController
{
private:
	std::shared_ptr<Mob> controlled_pawn;
public:
	virtual void Update(float &frame_time) override;
	virtual bool Possess(std::shared_ptr<Pawn> pawn) override;
	virtual inline bool IsPossesed();
	MobController();
	~MobController();
};

