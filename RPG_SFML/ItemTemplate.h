#include <string>
#include <variant>
#include <unordered_map>
#include "MultiTool.h"
#pragma once

class ItemTemplate
{
private:
	std::unordered_map<std::string, float> bonuses;
	std::string name;
	std::string description;
	std::string outfit_ID;
public:
	void WriteItemParametersInConsole();
	std::string GetName() { return name; }
	std::string GetDescription() { return description; }
	std::string GetOutfitID() { return outfit_ID; }
	std::string SetName(std::string name) { this->name = name; }
	std::string SetDescription(std::string description) { this->description = description; }
	std::string SetOutfitID(std::string outfit_ID) { this->outfit_ID = outfit_ID; }
	ItemTemplate();
	ItemTemplate(std::unordered_map<std::string, float> bonuses, std::string outfit_ID, std::string name, std::string description);
	~ItemTemplate();
};

