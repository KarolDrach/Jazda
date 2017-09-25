#include "ItemInstanceInInv.h"
#include "ItemInstanceOnMap.h"
#include "Actor.h"

ItemInstanceInInv::ItemInstanceInInv(Actor * item)
{
	auto test = static_cast<ItemInstanceOnMap*>(item);
	this->item = test->GetItemPointer();
}

ItemInstanceInInv::ItemInstanceInInv(ItemInstanceOnMap* item)
{
	this->item = item->GetItemPointer();
}

ItemInstanceInInv::~ItemInstanceInInv()
{
}
