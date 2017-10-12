#include <sstream>
#include <SFML/Graphics.hpp>
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
	auto pos = sf::Mouse::getPosition();
	if ((pos.x > rect.left) && (pos.x < (rect.left + rect.width)) &&
		(pos.y < rect.top) && (pos.y > (rect.top - rect.height)))
		return true;
	else
		return false;
}
