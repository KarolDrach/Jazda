#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "UI.h"
#include "MultiTool.h"

void UI::Update(float & frame_time, sf::RenderWindow& main_window, sf::View & previous_view)
{
	measured_fps_total += (1.0 / frame_time);

	if (actual_iter >= fps_measure_iterations)
	{
		auto _fps = (measured_fps_total / (float)fps_measure_iterations);
		auto str = MultiTool::FloatToString(_fps);
		fps_counter.setString(std::string("FPS: ") + str);
		main_window.setView(interface_view);
		main_window.draw(fps_counter);
		main_window.setView(previous_view);
		measured_fps_total = 0;
		actual_iter = 1;
	}
	else
		actual_iter++;
}

UI::UI()
{
	if (!font.loadFromFile(std::string("D://WielkiRPG//RPG_SFML//arial.ttf")))
		std::cout << "BLAD LADOWANIA CZCIONKI";

	fps_counter.setFont(font);
	fps_counter.setPosition(-430, 0);
	fps_counter.setFillColor(sf::Color::Magenta);
	fps_counter.setCharacterSize(20);

	this->interface_view = sf::View();
	//this->interface_view.setCenter(1920 / 2, 1080 / 2);
	this->interface_view.setSize(1920, 1080);
	this->actual_iter = 0;
	this->measured_fps_total = 0.0;
}

UI::~UI()
{
}
