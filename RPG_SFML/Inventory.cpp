#include "Inventory.h"
#include "ItemInstanceInInv.h"
#include "ItemInstanceOnMap.h"

void Inventory::AddItemToInventory(ItemInstanceInInv & item)
{
	this->max_capacity = 45;

	int i = 1;
	for (auto iter = all_items.cbegin(), end = all_items.cend(); iter != end && i == iter->first; ++iter, ++i);
	all_items[i] = item;
}

Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}
