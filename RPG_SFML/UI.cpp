#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "UI.h"
#include "FPSCounter.h"
#include "ItemInfo.h"
#include "UIInventoryDisplay.h"
#include "Character.h"
#include "ItemInstanceInInv.h"
#include "MultiTool.h"
#include "ItemTemplate.h"

void UI::Update(float & frame_time, sf::RenderWindow& main_window, sf::View & previous_view)
{
	main_window.setView(interface_view);
	UIInventoryDisplay::Instance().Update(frame_time, main_window);
	FPSCounter::Instance().Update(frame_time, main_window);
	ItemInfo::Instance().Update(frame_time, main_window);
	auto it = UIElements.begin();
	for (auto& el : UIElements)
	{
		el->GetToRemove() ? it = UIElements.erase(it) : it++;
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
