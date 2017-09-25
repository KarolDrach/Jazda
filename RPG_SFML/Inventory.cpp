#include "Inventory.h"
#include "ItemInstanceInInv.h"
#include "ItemInstanceOnMap.h"

void Inventory::AddItemToInventory(ItemInstanceInInv & item)
{
	this->all_items.emplace_back(item);
}

Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}
