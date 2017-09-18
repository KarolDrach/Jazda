#pragma once
#include "PawnController.h"

class ItemController :
	public PawnController
{
public:
	virtual void Update(float &frame_time) override;
	ItemController();
	~ItemController();
};

