#pragma once
#include <vector>
#include <optional>
#include <map>

class ItemInstanceInInv;

class Inventory
{
private:
	std::map<int, ItemInstanceInInv> all_items;
	int max_capacity;
public:
	auto& GetAllItems() { return all_items; }
	int GetMaxCapacity() { return max_capacity; }
	bool AddItemToInventory(ItemInstanceInInv& item);
	Inventory();
	~Inventory();
};

