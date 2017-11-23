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
	int max_stack_size;
public:
	void WriteItemParametersInConsole();
	std::string GetName() { return name; }
	std::string GetDescription() { return description; }
	std::string GetOutfitID() { return outfit_ID; }
	int GetMaxStackSize() { return max_stack_size; }
	void SetName(std::string name) { this->name = name; }
	void SetDescription(std::string description) { this->description = description; }
	void SetOutfitID(std::string outfit_ID) { this->outfit_ID = outfit_ID; }
	void SetMaxStackSize(int max_stack_size) { this->max_stack_size = max_stack_size; }
	ItemTemplate();
	ItemTemplate(std::unordered_map<std::string, float> bonuses, std::string outfit_ID, std::string name, std::string description);
	~ItemTemplate();
};

