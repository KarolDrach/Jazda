#pragma once
#include <memory>
#include <unordered_map>
#include <string>

extern class ItemTemplate;

class ItemsManager final
{
private:
	ItemsManager();
	std::unordered_map<std::string, std::shared_ptr<ItemTemplate>> item_pack;

public:
	/*K. kopiujacy i operator przypisania skasowane.*/
	ItemsManager(const ItemsManager &) = delete;
	void operator=(const ItemsManager &) = delete;
	~ItemsManager();

	inline static ItemsManager& Instance()
	{
		static ItemsManager instance;
		return instance;
	}

	static void LoadItemsFromFile(std::string & path);
	static std::shared_ptr<ItemTemplate> GetItem(std::string &name);
	static bool Delete(std::string &name);
};

