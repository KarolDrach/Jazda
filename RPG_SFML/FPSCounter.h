#pragma once
#include "UI.h"

class FPSCounter : public UIElement
{
private:
	FPSCounter();
	sf::Text fps_counter;
	sf::Font font;
	const int fps_measure_iterations = 1;
	int actual_iter;
	float measured_fps_total;
public:
	FPSCounter(const FPSCounter &) = delete;
	void operator=(const FPSCounter &) = delete;

	inline static FPSCounter& Instance()
	{
		static FPSCounter instance;
		return instance;
	}
	virtual void Update(float& frame_time, sf::RenderWindow& main_window) override;
	~FPSCounter();
};

