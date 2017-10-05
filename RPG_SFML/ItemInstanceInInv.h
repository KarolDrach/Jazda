#pragma once
#include <memory>

class ItemTemplate;
class ItemInstanceOnMap;
class Actor;

class ItemInstanceInInv
{
private:
	std::shared_ptr<ItemTemplate> item;
public:
	std::shared_ptr<ItemTemplate> GetItem() { return item; }
	ItemInstanceInInv();
	ItemInstanceInInv(std::shared_ptr<Actor> item);
	ItemInstanceInInv(std::shared_ptr<ItemInstanceOnMap> item);
	~ItemInstanceInInv();
};

