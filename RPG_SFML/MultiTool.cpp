#include <sstream>
#include "Game.h"
#include "MultiTool.h"

std::string MultiTool::FloatToString(float input)
{
	std::ostringstream buff;
	buff << input;
	return buff.str();
}

float MultiTool::StringToFloat(std::string input)
{
	return 0.0f;
}

bool MultiTool::IsMouseInRect(sf::FloatRect rect)
{
	auto pos_original = sf::Mouse::getPosition();
	//auto pos = Game::Instance().GetMainWindow().mapPixelToCoords(pos_original);
	//auto rect_pos = Game::Instance().GetMainWindow().mapPixelToCoords(sf::Vector2i(rect.left, rect.top));]
	auto pos = pos_original;
	auto rect_pos = sf::Vector2f(rect.left, rect.top);

	if ((pos.x > rect_pos.x) && (pos.x < (rect_pos.x + rect.width)) &&
		(pos.y > rect_pos.y) && (pos.y < (rect_pos.y + rect.height)))
		return true;
	else
		return false;

}

bool MultiTool::IsMouseOverSprite(sf::Sprite & sprite)
{
	auto pos_original = sf::Mouse::getPosition(Game::Instance().GetMainWindow());
	auto pos = Game::Instance().GetMainWindow().mapPixelToCoords(pos_original);
	auto sprite_dim = sprite.getGlobalBounds();
	return ((pos.x > sprite_dim.left) && (pos.x < (sprite_dim.left + sprite_dim.width)) &&
		(pos.y > sprite_dim.top) && (pos.y < (sprite_dim.top + sprite_dim.height)));
}
