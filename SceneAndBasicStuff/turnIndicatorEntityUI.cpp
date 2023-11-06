#include "turnIndicatorEntityUI.hpp"

TurnIndicatorEntityUI::TurnIndicatorEntityUI(sf::Vector2f position, sf::Color color, TurnIndicatorUI* turnIndicatorUI)
	: _turnIndicatorPosition(turnIndicatorUI->getPosition()), _turnIndicatorWidth(turnIndicatorUI->getSize().x), _turnIndicatorHeight(turnIndicatorUI->getSize().y)
{
	_mainCircle.setRadius(_radius);
	_mainCircle.setOrigin(_radius, _radius);
	_mainCircle.setFillColor(color);

	setPosition(position);
}

TurnIndicatorEntityUI::~TurnIndicatorEntityUI() { }

sf::Vector2f TurnIndicatorEntityUI::getPosition() const
{
	return _mainCircle.getPosition();
}

void TurnIndicatorEntityUI::render(sf::RenderWindow& window)
{
	
	window.draw(_mainCircle);
}


void TurnIndicatorEntityUI::setPosition(sf::Vector2f position)
{
	_mainCircle.setPosition(position);
}

void TurnIndicatorEntityUI::onNotified(const float& value)
{

	if (value == 0)
	{
		setPosition(sf::Vector2f(_turnIndicatorPosition.x-_mainCircle.getRadius(), _turnIndicatorPosition.y + _turnIndicatorHeight / 2));
		return;
	}
	
	float positionInIndicator = _turnIndicatorWidth * (value / 100);

	setPosition(sf::Vector2f(_turnIndicatorPosition.x + positionInIndicator, _turnIndicatorPosition.y + _turnIndicatorHeight / 2));
}


