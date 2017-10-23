#pragma once
#include <memory>

class ItemTemplate;
class ItemInstanceOnMap;
class Actor;

class ItemInstanceInInv
{
private:
	std::shared_ptr<ItemTemplate> item;
	int position;
public:
	std::shared_ptr<ItemTemplate> GetItem() { return item; }
	int GetPosition() { return position; }
	void SetPosition(int position) { this->position = position; }
	ItemInstanceInInv();
	ItemInstanceInInv(std::shared_ptr<Actor> item);
	ItemInstanceInInv(std::shared_ptr<ItemInstanceOnMap> item);
	~ItemInstanceInInv();
};

