#include <fstream>
#include <iostream>
#include "ItemsManager.h"
#include "MultiTool.h"
#include "ItemTemplate.h"

void ItemsManager::LoadItemsFromFile(std::string & path)
{
	auto& instance = Instance();
	
	std::fstream input_file;
	std::string symbol, bonus_value, name, description, outfit_ID;
	std::unordered_map <std::string, float> bonuses;
	input_file.open(path, std::ios::in);

	if (input_file.good())
	{
		while (!input_file.eof())
		{
			if (input_file >> symbol, symbol == std::string("ITEM"))
			{
				input_file >> name;
				input_file >> outfit_ID;
				while (symbol != std::string("ITEM_END"))
				{
					if (input_file >> symbol, symbol != std::string("ITEM_END"))
					{
						input_file >> bonus_value;
						bonuses[symbol] = std::stof(bonus_value);
					}			
				}

				instance.item_pack[name] = std::make_shared<ItemTemplate>(bonuses, outfit_ID, name, description);
				bonuses = {};
				description = "";
				outfit_ID = "";
				symbol = "";
				bonus_value = "";
				name = "";
			}
		}
	}
	else
	{
		std::cout << "Blad wczytywania pliku ladujacego itemki z pliku";
	}

	for (auto i : instance.item_pack)
	{
		std::cout << i.first << "\n";
		(i.second)->WriteItemParametersInConsole();
	}
}

std::shared_ptr<ItemTemplate> ItemsManager::GetItem(std::string & name)
{
	auto &instance = Instance();
	auto itemIt = instance.item_pack.find(name);

	if (itemIt == instance.item_pack.end())
		return std::make_shared<ItemTemplate>();

	return std::make_shared<ItemTemplate>(*(itemIt->second));
}

bool ItemsManager::Delete(std::string & name)
{
	return false;
}

ItemsManager::ItemsManager()
{
}

ItemsManager::~ItemsManager()
{
}
