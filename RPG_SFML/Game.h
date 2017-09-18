#include <SFML/Graphics.hpp>
#include <vector>
#include "Game_Status.h"
#include "Level.h"
#include "MultiTool.h"

#pragma once

class Game final
{
private:
	sf::RenderWindow main_window;
	sf::View main_view;
	GameStatus main_status;
	Level current_level;
	std::vector<std::string> npc_attributes_symbols;
	Game();
public:
	/*K. kopiujacy i operator przypisania skasowane.*/
	Game          (const Game &) = delete;
	void operator=(const Game &) = delete;
	~Game();

	inline static Game& Instance()
	{
		static Game instance;
		return instance;
	}

	inline std::vector<std::string>& GetNPCAttributesSymbols() { return npc_attributes_symbols; } const
	inline GameStatus& GetGameStatus() { return main_status; }
	inline sf::RenderWindow& GetMainWindow() { return main_window; }
	inline Level& GetCurrentLevel() { return current_level; }
	inline sf::View& GetMainView() { return main_view; }
	void GameLoop();
	friend class PawnController;
};

