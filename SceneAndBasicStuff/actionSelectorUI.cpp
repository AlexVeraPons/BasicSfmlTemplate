#include "actionSelectorUI.hpp"
#include "button.hpp"
#include <vector>

ActionSelectorUI::ActionSelectorUI(std::string identifier, sf::Vector2f position, float width, float height) : GameObject(identifier, position), _buttonColor(sf::Color())
{
	_width = width;
	_height = height;
}

ActionSelectorUI::~ActionSelectorUI() { }

void ActionSelectorUI::start()
{
	setupButtonPositions();
	for (auto& button : _buttons)
	{
		button->start();
	}
}

void ActionSelectorUI::update()
{
	for (auto&  button : _buttons)
	{
		button->update();
	}
}

void ActionSelectorUI::render(sf::RenderWindow& window)
{
	for (auto& button : _buttons)
	{
		button->render(window);
	}
}

void ActionSelectorUI::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{
	for (auto& button : _buttons)
	{
		button->handleEvent(event, window);
	}
}

void ActionSelectorUI::addButton(std::unique_ptr<Button> button)
{
	_buttons.push_back(std::move(button));
}

void ActionSelectorUI::setButtonColor(sf::Color color)
{
	_buttonColor = color;
}

void ActionSelectorUI::setupButtonPositions()
{
	int rows = _buttons.size() > 1 ? 2 : 1;
	int columns = (_buttons.size() + 1) / 2;
	float buttonHeight = _height / rows;
	float buttonWidth = _width / columns;

	for (unsigned int i = 0; i < _buttons.size(); ++i)
	{
		int column = i / rows;
		int row = i % rows;
		float buttonXPosition = this->position.x + buttonWidth * column;
		float buttonYPosition = this->position.y + buttonHeight * row;

		_buttons[i]->setPosition(sf::Vector2f(buttonXPosition, buttonYPosition));

		if (i == _buttons.size() - 1 && _buttons.size() % 2 != 0) {
			_buttons[i]->setShapeSize(sf::Vector2f(buttonWidth, _height));
		}
		else {
			_buttons[i]->setShapeSize(sf::Vector2f(buttonWidth, buttonHeight));
		}

		_buttons[i]->centerText();
	}
}
