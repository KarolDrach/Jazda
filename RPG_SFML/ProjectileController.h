#pragma once
#include <memory>
#include "PawnController.h"

class Projectile;

class ProjectileController : public PawnController
{
private:
	std::shared_ptr<Projectile> controlled_pawn;
public:
	virtual void Update(float &frame_time) override;
	virtual bool Possess(std::shared_ptr<Pawn> pawn) override;
	virtual inline bool IsPossesed();
	ProjectileController();
	~ProjectileController();
};

