#pragma once
#include <unordered_map>

template <typename ID = string, typename Type>
class ResourcesManager
{
private:
	ResourcesManager();
	std::unordered_map<ID, Type> resource_pack;
public:
	/*K. kopiujacy i operator przypisania skasowane.*/
	ResourcesManager(const ResourcesManager &) = delete;
	void operator=(const ResourcesManager &) = delete;
	~ResourcesManager();

	inline static ResourcesManager& Instance()
	{
		static ResourcesManager instance;
		return instance;
	}

	virtual static Type& Load(ID &name, std::string &path) = 0;
	virtual static Type& GetItem(ID &name) = 0;
	virtual static bool Delete(ID &name) = 0;
};

