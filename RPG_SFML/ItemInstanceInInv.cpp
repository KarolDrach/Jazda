#include <iostream>
#include "ItemInstanceInInv.h"
#include "ItemInstanceOnMap.h"
#include "Actor.h"

ItemInstanceInInv::ItemInstanceInInv(std::shared_ptr<Actor> item)
{
	auto test = std::static_pointer_cast<ItemInstanceOnMap>(item);
	if (item && test)
	{
		this->item = test->GetItemPointer();
	}
	else
	{
		std::cout << "Something went wrong when ItemInstanceInInv from Actor Created\n check why its nullptr";
	}
}

ItemInstanceInInv::ItemInstanceInInv(std::shared_ptr<ItemInstanceOnMap> item)
{
	if (item)
	{
		this->item = item->GetItemPointer();
	}
	else
	{
		std::cout << "Something went wrong when ItemInstanceInInv from ItemInstanceOnMap Created\n check why its nullptr";
	}
}

ItemInstanceInInv::ItemInstanceInInv()
{
}

ItemInstanceInInv::~ItemInstanceInInv()
{
}
