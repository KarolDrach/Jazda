#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Game.h"
#include "TextureManager.h"
#include "Vector2D.h"
#include "Pawn.h"
#include "Character.h"

using namespace std;

int main()
{
	auto &game = Game::Instance();
	auto &texture_manager = TextureManager::Instance();

	game.GameLoop();
	return 0;
}