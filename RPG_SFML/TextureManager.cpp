#include "TextureManager.h"

sf::Texture* TextureManager::Load(std::string & name, std::string & path)
{
	auto &instance = Instance();

	sf::Texture* result = GetTexture(name);

	if (result)
	{
		result->loadFromFile(path);
	}
	else
	{
		result = new sf::Texture;
		result->loadFromFile(path);
		instance.texture_pack[name] = result;
	}

	return result;
}

sf::Texture* TextureManager::GetTexture(std::string & name)
{
	auto &instance = Instance();
	auto textureIt = instance.texture_pack.find(name);

	if(textureIt == instance.texture_pack.end())
		return nullptr;

	return textureIt->second;
}

bool TextureManager::Delete(std::string & name)
{
	auto &instance = Instance();
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
	}	
}

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
	for (auto element : texture_pack)
		delete (element.second);
}
