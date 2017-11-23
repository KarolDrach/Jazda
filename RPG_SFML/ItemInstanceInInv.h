#pragma once
#include <memory>

class ItemTemplate;
class ItemInstanceOnMap;
class Actor;

class ItemInstanceInInv
{
private:
	std::shared_ptr<ItemTemplate> item;
	int stack_size;
public:
	bool displayInfo;
	std::shared_ptr<ItemTemplate> GetItem() { return item; }
	bool AddToStack(std::shared_ptr<ItemTemplate>& item);
	ItemInstanceInInv();
	ItemInstanceInInv(std::shared_ptr<Actor> item);
	ItemInstanceInInv(std::shared_ptr<ItemInstanceOnMap> item);
	~ItemInstanceInInv();
};

