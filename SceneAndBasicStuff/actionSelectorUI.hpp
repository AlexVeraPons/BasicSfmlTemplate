#pragma once
#include <vector>
#include "gameObject.hpp"
#include "button.hpp"


class ActionSelectorUI : public GameObject
{
private:
	std::vector <Button*> _buttons;
	sf::Color _buttonColor;
	float _width;
	float _height;
public:
	ActionSelectorUI(std::string identifier, sf::Vector2f position, float width, float height);
	~ActionSelectorUI();
public:
	void start() override;
	void update() override;
	void render(sf::RenderWindow& window) override;
	void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
	void addButton(Button* button);
	void setButtonColor(sf::Color color);
private:
	void setupButtonPositions();

};

