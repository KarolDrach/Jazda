#pragma once
#include "PawnController.h"

class Projectile;

class ProjectileController : public PawnController
{
private:
	Projectile* controlled_pawn;
public:
	virtual void Update(float &frame_time) override;
	virtual bool Possess(Pawn* pawn) override;
	virtual inline bool IsPossesed();
	ProjectileController();
	~ProjectileController();
};

