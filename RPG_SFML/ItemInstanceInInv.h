#pragma once

class ItemTemplate;
class ItemInstanceOnMap;
class Actor;

class ItemInstanceInInv
{
private:
	ItemTemplate* item;
public:
	ItemTemplate* GetItem() { return item; }
	ItemInstanceInInv(Actor* item);
	ItemInstanceInInv(ItemInstanceOnMap* item);
	~ItemInstanceInInv();
};

