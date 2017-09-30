#include "TextureManager.h"
#include <memory>

std::shared_ptr<sf::Texture> TextureManager::Load(std::string & name, std::string & path)
{
	auto &instance = Instance();

	std::shared_ptr<sf::Texture> result = GetTexture(name);

	if (result)
	{
		result->loadFromFile(path);
	}
	else
	{
		result = std::make_shared<sf::Texture>();
		result->loadFromFile(path);
		instance.texture_pack[name] = result;
	}

	return result;
}

std::shared_ptr<sf::Texture> TextureManager::GetTexture(std::string & name)
{
	auto &instance = Instance();
	auto textureIt = instance.texture_pack.find(name);

	if(textureIt == instance.texture_pack.end())
		return nullptr;

	return textureIt->second;
}

bool TextureManager::Delete(std::string & name)
{
	/* FUNCTION TO BE DONE*/
	/*auto &instance = Instance();
	auto textureIt = instance.texture_pack.find(name);

	if (textureIt == instance.texture_pack.end())
	{
		return false;
	}
	else
	{
		delete textureIt->second;
		instance.texture_pack.erase(textureIt);
		return true;
	}*/	
}

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}
