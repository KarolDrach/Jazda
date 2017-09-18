#pragma once
#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>

class TextureManager final
{
private:
	TextureManager();
	std::unordered_map<std::string, sf::Texture*> texture_pack;

public:
	/*K. kopiujacy i operator przypisania skasowane.*/
	TextureManager(const TextureManager &) = delete;
	void operator=(const TextureManager &) = delete;
	~TextureManager();

	inline static TextureManager& Instance()
	{
		static TextureManager instance;
		return instance;
	}

	static sf::Texture* Load(std::string &name, std::string &path);
	static sf::Texture* GetTexture(std::string &name);
	static bool Delete(std::string &name);
};

