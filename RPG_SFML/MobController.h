#pragma once
#include "PawnController.h"
#include "Game.h"
class MobController : public PawnController
{
public:
	virtual void Update(float &frame_time) override;
	MobController();
	~MobController();
};

