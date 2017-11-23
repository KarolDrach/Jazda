#include "ItemInstanceOnMap.h"
#include "ItemTemplate.h"
#include "PawnController.h"
#include "Vector2D.h"
#include "ItemInfo.h"
#include "Game.h"

void ItemInstanceOnMap::Draw()
{
	Game::Instance().GetMainWindow().draw(outfit);

	if (this->displayInfo)
	{
		ItemInfo::Instance().SetItem(this->item);
		ItemInfo::Instance().SetTopLeftPos(this->GetPosition());
	}
}

ItemInstanceOnMap::ItemInstanceOnMap(std::shared_ptr<ItemTemplate> item, 
									 Vector2D<> position) :
	Pawn(0.0, position)
{
	can_be_picked_up = true;
	displayInfo = false;
	this->item = item;
	SetOutfit(item->GetOutfitID());
}

ItemInstanceOnMap::ItemInstanceOnMap(std::shared_ptr<Actor> actor)
{
}


ItemInstanceOnMap::~ItemInstanceOnMap()
{
}
