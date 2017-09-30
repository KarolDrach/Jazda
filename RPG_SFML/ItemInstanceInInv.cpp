#include "ItemInstanceInInv.h"
#include "ItemInstanceOnMap.h"
#include "Actor.h"

ItemInstanceInInv::ItemInstanceInInv(std::shared_ptr<Actor> item)
{
	auto test = std::dynamic_pointer_cast<std::shared_ptr<ItemInstanceOnMap>>(item);
	this->item = (*test)->GetItemPointer();
}

ItemInstanceInInv::ItemInstanceInInv(std::shared_ptr<ItemInstanceOnMap> item)
{
	this->item = item->GetItemPointer();
}

ItemInstanceInInv::~ItemInstanceInInv()
{
}
