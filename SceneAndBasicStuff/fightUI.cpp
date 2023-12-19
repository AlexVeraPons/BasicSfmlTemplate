#include "fightUI.hpp"
#include "fightCharacter.hpp"
#include "turnIndicatorUI.hpp"
#include "assetManager.hpp"

FightUI::FightUI() : GameObject("FightUI"),
_healthBar1("HealthBar1", sf::Vector2f(0, 0), nullptr),
_healthBar2("HealthBar2", sf::Vector2f(0, 0), nullptr),
_turnIndicatorUI(),
_player("playerImage", AssetManager::getInstance()->getTexture("skeleton")),
_enemy("enemyImage", AssetManager::getInstance()->getTexture("skeleton"))
{ }

FightUI::FightUI(std::string identifier, FightCharacter* fighter1, FightCharacter* fighter2, sf::Vector2f windowSize)
	: GameObject(identifier),
	_healthBar1("HealthBar1", sf::Vector2f(0, 0), fighter1),
	_healthBar2("HealthBar2", sf::Vector2f(0, 0), fighter2),
	_turnIndicatorUI("TurnIndicatorUI", sf::Vector2f(windowSize.x * 1 / 4, windowSize.y * 1 / 16),sf::Vector2f(windowSize.x * 2 / 4,10), fighter1, fighter2),
	_player("playerImage",AssetManager::getInstance()->getTexture("skeleton")),
	_enemy("enemyImage",AssetManager::getInstance()->getTexture("skeleton"))
{
	_player.sprite.setScale(sf::Vector2f(-0.25, 0.25));
	_player.sprite.setPosition(sf::Vector2f((windowSize.x * 1 / 4 - _player.sprite.getGlobalBounds().width /2)+300, windowSize.y * 4 / 8 - _player.sprite.getGlobalBounds().height / 2 + 50));
	_player.texture->setSmooth(true);
	_player.sprite.setColor(sf::Color(100, 100, 255, 255));

	_enemy.sprite.setScale(sf::Vector2f(0.25, 0.25));
	_enemy.sprite.setColor(sf::Color(200, 100, 100, 255));
	_enemy.sprite.setPosition(sf::Vector2f((windowSize.x * 3 / 4 + _enemy.sprite.getGlobalBounds().width /2)- 300, windowSize.y * 4 / 8 - _enemy.sprite.getGlobalBounds().height / 2 + 50));
	_enemy.texture->setSmooth(true);
	_healthBar1.setPosition(sf::Vector2f(_player.sprite.getPosition().x - _healthBar1.getSize().x / 2, _player.sprite.getPosition().y - _player.sprite.getScale().x - _healthBar1.getSize().y - 5));
	_healthBar2.setPosition(sf::Vector2f(_enemy.sprite.getPosition().x - _healthBar2.getSize().x / 2, _enemy.sprite.getPosition().y - _enemy.sprite.getScale().x - _healthBar2.getSize().y - 5));
}


FightUI::~FightUI() { }

void FightUI::render(sf::RenderWindow& window)
{
	_healthBar1.render(window);
	_healthBar2.render(window);

	_player.render(window);
	_enemy.render(window);

	_turnIndicatorUI.render(window);

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


