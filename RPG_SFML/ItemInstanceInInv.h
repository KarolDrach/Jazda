#pragma once

class ItemTemplate;
class ItemInstanceOnMap;
class Actor;

class ItemInstanceInInv
{
private:
	ItemTemplate* item;
public:
	ItemInstanceInInv(Actor* item);
	ItemInstanceInInv(ItemInstanceOnMap* item);
	~ItemInstanceInInv();
};

