#include "FPSCounter.h"
#include "MultiTool.h"
#include <iostream>

void FPSCounter::Update(float & frame_time, sf::RenderWindow& main_window)
{
	measured_fps_total += (1.0 / frame_time);

	if (actual_iter >= fps_measure_iterations)
	{
		auto _fps = (measured_fps_total / (float)fps_measure_iterations);
		auto str = MultiTool::FloatToString(_fps);
		fps_counter.setString(std::string("FPS: ") + str);
		main_window.draw(fps_counter);
		measured_fps_total = 0;
		actual_iter = 1;
	}
	else
		actual_iter++;
}

FPSCounter::FPSCounter()
{
	this->updateThis = true;
	if (!font.loadFromFile(std::string("D://WielkiRPG//RPG_SFML//arial.ttf")))
		std::cout << "BLAD LADOWANIA CZCIONKI";

	fps_counter.setFont(font);
	fps_counter.setPosition(-430, 0);
	fps_counter.setFillColor(sf::Color::Magenta);
	fps_counter.setCharacterSize(20);

	this->actual_iter = 0;
	this->measured_fps_total = 0.0;
}


FPSCounter::~FPSCounter()
{
}
