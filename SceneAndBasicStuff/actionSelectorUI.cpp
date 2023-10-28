#include "actionSelectorUI.hpp"
#include "button.hpp"
#include <vector>

ActionSelectorUI::ActionSelectorUI(std::string identifier, sf::Vector2f position, float width, float height) : GameObject(identifier, position), _buttonColor(sf::Color())
{
	_width = width;
	_height = height;

	setupButtonPositions()
}

ActionSelectorUI::~ActionSelectorUI() { }

void ActionSelectorUI::render(sf::RenderWindow& window)
{
	for (Button* button : _buttons)
	{
		button->render(window);
	}
}

void ActionSelectorUI::addButton(Button& button)
{
	_buttons.push_back(&button);
}

void ActionSelectorUI::setButtonColor(sf::Color color)
{
	_buttonColor = color;
}

void ActionSelectorUI::setupButtonPositions()
{

}
