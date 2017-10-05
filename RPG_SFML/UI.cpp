#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "UI.h"
#include "Character.h"
#include "ItemInstanceInInv.h"
#include "MultiTool.h"
#include "ItemTemplate.h"

void UI::Update(float & frame_time, sf::RenderWindow& main_window, sf::View & previous_view)
{
	main_window.setView(interface_view);
	for (auto& el : UIElements)
	{
		el->Update(frame_time, main_window);
	}
	main_window.setView(previous_view);
}

UI::UI()
{
	this->interface_view = sf::View();
	this->interface_view.setCenter(1920.0 / 2.0, 1080.0 / 2.0);
	this->interface_view.setSize(1920, 1080);
}

UI::~UI()
{
}

UIElement::UIElement(bool updateThis)
{
	this->updateThis = updateThis;
}

UIElement::UIElement()
{
	this->updateThis = true;
}
