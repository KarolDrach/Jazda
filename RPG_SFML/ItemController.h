#pragma once
#include "PawnController.h"

class ItemInstanceOnMap;

class ItemController :
	public PawnController
{
protected:
	ItemInstanceOnMap* controlled_pawn;
public:
	virtual void Update(float &frame_time) override;
	virtual bool Possess(Pawn* pawn) override;
	virtual inline bool IsPossesed();
	ItemController();
	~ItemController();
};

