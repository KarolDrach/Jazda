#pragma once
#include "PawnController.h"

class ProjectileController : public PawnController
{
public:
	virtual void Update(float &frame_time) override;
	ProjectileController();
	~ProjectileController();
};

