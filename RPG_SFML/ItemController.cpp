#include <memory>
#include "ItemController.h"
#include "MultiTool.h"
#include "Pawn.h"
#include "ItemInfo.h"
#include "ItemInstanceOnMap.h"

void ItemController::Update(float & frame_time)
{
	if (MultiTool::IsMouseOverSprite(this->controlled_pawn->GetOutfit()))
	{
		if (!ItemInfo::Instance().GetUpdateThis())
		{
			ItemInfo::Instance().SetTopLeftPos(this->controlled_pawn->GetPosition());
			ItemInfo::Instance().SetUpdateThis(true);
			ItemInfo::Instance().SetItem(this->controlled_pawn->GetItemPointer());
		}
	}
	else
	{
		ItemInfo::Instance().SetUpdateThis(false);
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
