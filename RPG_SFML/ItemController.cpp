#include <memory>
#include "Game.h"
#include "ItemController.h"
#include "MultiTool.h"
#include "Pawn.h"
#include "ItemInfo.h"
#include "ItemInstanceOnMap.h"

void ItemController::Update(float & frame_time)
{
	if (MultiTool::IsMouseOverSprite(this->controlled_pawn->GetOutfit()))
	{
		this->controlled_pawn->displayInfo = true;
	}	
	else
	{
		this->controlled_pawn->displayInfo = false;
	}
}

bool ItemController::Possess(std::shared_ptr<Pawn> controlled_pawn)
{
	if (!this->controlled_pawn)
	{
		this->controlled_pawn = std::static_pointer_cast<ItemInstanceOnMap>(controlled_pawn);
		return true;
	}
	return false;
}

inline bool ItemController::IsPossesed()
{
	return false;
}

ItemController::ItemController()
{
}


ItemController::~ItemController()
{
}
