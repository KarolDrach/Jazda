#include <memory>
#include "ItemController.h"
#include "Pawn.h"
#include "ItemInstanceOnMap.h"

void ItemController::Update(float & frame_time)
{
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
