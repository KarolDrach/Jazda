#pragma once
#include "UI.h"
class FPSCounter :
	public UIElement
{
private:
	sf::Text fps_counter;
	sf::Font font;
	const int fps_measure_iterations = 1;
	int actual_iter;
	float measured_fps_total;
public:
	virtual void Update(float& frame_time, sf::RenderWindow& main_window) override;
	FPSCounter();
	~FPSCounter();
};

