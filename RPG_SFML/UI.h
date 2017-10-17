#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Character;
class UIElement;

class UI
{
private:
	UI();
	sf::View interface_view;
	std::vector<std::shared_ptr<UIElement>> UIElements;
public:
	UI(const UI &) = delete;
	void operator=(const UI &) = delete;

	inline static UI& Instance()
	{
		static UI instance;
		return instance;
	}
	
	void AddUIElement(std::shared_ptr<UIElement> element) { this->UIElements.emplace_back(element); }
	void Update(float& frame_time, sf::RenderWindow& main_window, sf::View& previous_view);
	~UI();
};

class UIElement
{
protected:
	bool updateThis;
	bool toRemove;
public:
	UIElement(bool updateThis);
	UIElement();
	void SetUpdateThis(bool updateThis) { this->updateThis = updateThis; }
	auto GetUpdateThis() { return updateThis; }
	void SetToRemove(bool remove) { this->toRemove = remove; }
	auto GetToRemove() { return toRemove; }
	virtual void Update(float& frame_time, sf::RenderWindow& main_window) = 0;
};
