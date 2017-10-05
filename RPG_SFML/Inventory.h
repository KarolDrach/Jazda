#pragma once
#include <vector>
#include <unordered_map>

class ItemInstanceInInv;

class Inventory
{
private:
	std::unordered_map<int, ItemInstanceInInv> all_items;
	int max_capacity;
public:
	std::unordered_map<int, ItemInstanceInInv>& GetAllItems() { return all_items; }
	int GetMaxCapacity() { return max_capacity; }
	void AddItemToInventory(ItemInstanceInInv& item);
	Inventory();
	~Inventory();
};

