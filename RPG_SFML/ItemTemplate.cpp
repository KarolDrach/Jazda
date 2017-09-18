#include <iostream>
#include <string>
#include <variant>
#include "ItemTemplate.h"
#include "MultiTool.h"

void ItemTemplate::WriteItemParametersInConsole()
{
	std::cout << "NAZWA:  " << name << "\n";
	std::cout << "OPIS:  " << description << "\n";
	std::cout << "ID OUTF: " << outfit_ID << "\nBONUSY:\n";
	for (auto i : bonuses)
	{
		std::cout << i.first << " " << i.second << "\n";
	}
	std::cout << "\n\n";
}

ItemTemplate::ItemTemplate()
{
	;
}

ItemTemplate::ItemTemplate(std::unordered_map<std::string, float> bonuses, 
						   std::string outfit_ID, 
						   std::string name, 
						   std::string description):
	bonuses(bonuses), name(name), description(description)
{
	this->outfit_ID = outfit_ID;
}

ItemTemplate::~ItemTemplate()
{
}
