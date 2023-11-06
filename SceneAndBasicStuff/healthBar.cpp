#include "healthBar.hpp"

HealthBar::HealthBar(std::string identifier, sf::Vector2f position, FightCharacter* owner) : GameObject(identifier, position)
{

	_background.setSize(sf::Vector2f(100, 10));
	_background.setFillColor(sf::Color(150, 150, 150));
	_background.setPosition(position);

	_innerBar.setSize(sf::Vector2f(90, 9));
	_innerBar.setFillColor(sf::Color::Green);
	_innerBar.setPosition(position.x + 5, position.y + 1);

	_maxWidth = _innerBar.getSize().x;
	_maxHealth = owner->getHealth();
	_currentHealth = owner->getHealth();

	owner->Subject<float>::addObserver(*this);
};

HealthBar::~HealthBar() { }

sf::Vector2f HealthBar::getSize() const
{
	return _background.getSize();
}

void HealthBar::setPosition(sf::Vector2f position)
{
	_background.setPosition(position);
	_innerBar.setPosition(position.x + 5, position.y + 1);
}

void HealthBar::render(sf::RenderWindow& window)
{
	window.draw(_background);
	window.draw(_innerBar);
}

void HealthBar::onNotified(const float& value)
{
	updateBar(value);
	updateBarColor();
}

void HealthBar::setOwner(FightCharacter* owner)
{
	_maxHealth = owner->getMaxHealth();
	_currentHealth = owner->getHealth();
}

void HealthBar::updateBar(const float& value)
{
	_currentHealth = value;

	float percentage = _currentHealth / _maxHealth;
	_innerBar.setSize(sf::Vector2f(_maxWidth * percentage, _innerBar.getSize().y));
}

void HealthBar::updateBarColor()
{
	float percentage = _currentHealth / _maxHealth;
	
	if (percentage > 0.5)
	{
		_innerBar.setFillColor(sf::Color::Green);
	}
	else if (percentage > 0.25)
	{
		_innerBar.setFillColor(sf::Color::Yellow);
	}
	else
	{
		_innerBar.setFillColor(sf::Color::Red);
	}
}


