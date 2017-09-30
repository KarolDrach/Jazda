#include "ItemInstanceOnMap.h"
#include "ItemTemplate.h"
#include "PawnController.h"
#include "Vector2D.h"
#include "Game.h"

void ItemInstanceOnMap::Draw()
{
	//std::cout << "TEST " << this->item->GetOutfitID() << "\n";
	Game::Instance().GetMainWindow().draw(outfit);
}

ItemInstanceOnMap::ItemInstanceOnMap(std::shared_ptr<ItemTemplate> item, 
									 std::shared_ptr<PawnController> controller, 
									 Vector2D<> position) :
	Pawn(controller, 0.0, position)
{
	can_be_picked_up = true;
	this->item = item;
	SetOutfit(item->GetOutfitID());
}

ItemInstanceOnMap::ItemInstanceOnMap(std::shared_ptr<Actor> actor)
{
//
}


ItemInstanceOnMap::~ItemInstanceOnMap()
{
}
