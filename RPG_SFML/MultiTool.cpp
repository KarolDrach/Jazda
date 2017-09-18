#include <sstream>
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
