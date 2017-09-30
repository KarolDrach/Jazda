#pragma once
#include <unordered_map>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

class TextureManager final
{
private:
	TextureManager();
	std::unordered_map<std::string, std::shared_ptr<sf::Texture>> texture_pack;

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

	static std::shared_ptr<sf::Texture> Load(std::string &name, std::string &path);
	static std::shared_ptr<sf::Texture> GetTexture(std::string &name);
	static bool Delete(std::string &name);
};

