#pragma once
#include "PawnController.h"

class ItemInstanceOnMap;

class ItemController :
	public PawnController
{
protected:
	std::shared_ptr<ItemInstanceOnMap> controlled_pawn;
public:
	virtual void Update(float &frame_time) override;
	virtual bool Possess(std::shared_ptr<Pawn> pawn) override;
	virtual inline bool IsPossesed();
	ItemController();
	~ItemController();
};

