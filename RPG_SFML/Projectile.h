#pragma once
#include "Pawn.h"

class Projectile : public Pawn
{
public:
	virtual void Draw() override;
	Projectile(float rotation, Vector2D<>position);
	~Projectile();
	friend class ProjectileController;
};

