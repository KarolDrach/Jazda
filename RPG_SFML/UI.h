#pragma once

extern class sf::Text;

class UI
{
private:
	UI();
	sf::View interface_view;
	sf::Text fps_counter;
	sf::Font font;
	const int fps_measure_iterations = 1;
	int actual_iter;
	float measured_fps_total;
public:
	UI(const UI &) = delete;
	void operator=(const UI &) = delete;

	inline static UI& Instance()
	{
		static UI instance;
		return instance;
	}

	void Update(float& frame_time, sf::RenderWindow& main_window, sf::View& previous_view);
	~UI();
};

