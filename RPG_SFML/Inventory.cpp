#include <iostream>
#include "Inventory.h"
#include "ItemInstanceInInv.h"
#include "ItemInstanceOnMap.h"

bool Inventory::AddItemToInventory(ItemInstanceInInv & item)
{
	int i = 1;
	for (auto iter = all_items.cbegin(), end = all_items.cend(); iter != end && i == iter->first; ++iter, ++i);

	std::cout << i << " " << all_items.size() << "\n";
	if (i <= max_capacity)
	{
		all_items[i] = item;
		return true;
	}
	else
	{
		return false;
	}
}

Inventory::Inventory()
{
	this->max_capacity = 12;
}


Inventory::~Inventory()
{
}
