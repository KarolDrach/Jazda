#pragma once
#include <vector>

class ItemInstanceInInv;

class Inventory
{
private:
	std::vector<ItemInstanceInInv> all_items;
public:
	std::vector<ItemInstanceInInv>& GetAllItems() { return all_items; }
	void AddItemToInventory(ItemInstanceInInv& item);
	Inventory();
	~Inventory();
};

