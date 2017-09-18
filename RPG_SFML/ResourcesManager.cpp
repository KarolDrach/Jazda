#include "ResourcesManager.h"



ResourcesManager::ResourcesManager()
{
}


ResourcesManager::~ResourcesManager()
{
}

template<typename ID, typename Type>
ItemTemplate ResourcesManager<ID, Type>::Load(ID & name, std::string & path)
{
	return ItemTemplate();
}

template<typename ID, typename Type>
ItemsManager & ResourcesManager<ID, Type>::GetItem(ID & name)
{
	// TODO: insert return statement here
}
