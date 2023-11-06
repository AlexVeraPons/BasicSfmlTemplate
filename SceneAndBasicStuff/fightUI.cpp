#include "fightUI.hpp"
#include "fightCharacter.hpp"
#include "turnIndicatorUI.hpp"

FightUI::FightUI() : GameObject("FightUI"),
_healthBar1("HealthBar1", sf::Vector2f(0, 0), nullptr),
_healthBar2("HealthBar2", sf::Vector2f(0, 0), nullptr),
_turnIndicatorUI(),
_floor() { }

FightUI::FightUI(std::string identifier, FightCharacter* fighter1, FightCharacter* fighter2, sf::Vector2f windowSize)
	: GameObject(identifier),
	_healthBar1("HealthBar1", sf::Vector2f(0, 0), fighter1),
	_healthBar2("HealthBar2", sf::Vector2f(0, 0), fighter2),
	_turnIndicatorUI("TurnIndicatorUI", sf::Vector2f(windowSize.x * 1 / 4, windowSize.y * 1 / 16),sf::Vector2f(windowSize.x * 2 / 4,10), fighter1, fighter2),
	_playerindicator1(),
	_playerindicator2(),
	_floor()
{
	_floor.setSize(sf::Vector2f(windowSize.x * 2 / 4, 20));
	_floor.setPosition(sf::Vector2f(windowSize.x*1/4, windowSize.y * 4 / 8));
	_floor.setFillColor(sf::Color::Black);

	_playerindicator1.setRadius(40);
	_playerindicator1.setOrigin(_playerindicator1.getRadius(), _playerindicator1.getRadius());
	_playerindicator1.setFillColor(sf::Color::Blue);
	_playerindicator1.setPosition(sf::Vector2f(_floor.getPosition().x + 45, _floor.getPosition().y - 45));

	_playerindicator2.setRadius(40);
	_playerindicator2.setOrigin(_playerindicator2.getRadius(), _playerindicator2.getRadius());
	_playerindicator2.setFillColor(sf::Color::Red);
	_playerindicator2.setPosition(sf::Vector2f(_floor.getPosition().x + _floor.getSize().x - 45, _floor.getPosition().y - 45));

	_healthBar1.setPosition(sf::Vector2f(_playerindicator1.getPosition().x - _healthBar1.getSize().x / 2, _playerindicator1.getPosition().y - _playerindicator1.getRadius() - _healthBar1.getSize().y - 5));
	_healthBar2.setPosition(sf::Vector2f(_playerindicator2.getPosition().x - _healthBar2.getSize().x / 2, _playerindicator2.getPosition().y - _playerindicator2.getRadius() - _healthBar2.getSize().y - 5));
}


FightUI::~FightUI() { }

void FightUI::render(sf::RenderWindow& window)
{
	_healthBar1.render(window);
	_healthBar2.render(window);

	window.draw(_playerindicator1);
	window.draw(_playerindicator2);

	_turnIndicatorUI.render(window);

	window.draw(_floor);
}

void FightUI::update()
{
	_healthBar1.update();
	_healthBar2.update();

	_turnIndicatorUI.update();
}

void FightUI::setEntityReferences(FightCharacter* fighter1, FightCharacter* fighter2)
{
	_healthBar1.setOwner(fighter1);
	_healthBar2.setOwner(fighter2);

	_turnIndicatorUI.setEntityReferences(fighter1, fighter2);
}


