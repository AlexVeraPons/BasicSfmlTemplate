#include "playerObject.hpp"
#include <SFML/Window/Keyboard.hpp>

PlayerObject::PlayerObject(std::string identifier, std::string spriteFile) :
	SpriteObject(identifier, spriteFile)
{
	this->setPosition(sf::Vector2f(100, 100));
	this->setScale(sf::Vector2f(0.5, 0.5));
}

PlayerObject::PlayerObject(const PlayerObject& other) :
	SpriteObject(other.getIdentifier(), other.getSpriteFile())
{
	this->setPosition(sf::Vector2f(100, 100));
	this->setScale(sf::Vector2f(0.5, 0.5));
}

PlayerObject::PlayerObject(std::string identifier, std::string spriteFile, sf::Vector2f position) :
	SpriteObject(identifier, spriteFile)
{
	this->setPosition(position);
	this->setScale(sf::Vector2f(0.5, 0.5));
}

PlayerObject::~PlayerObject() { }

void PlayerObject::update() 
{
	SpriteObject::update();
	this->handleInput();
}

void PlayerObject::move(sf::Vector2f direction, float speed)
{
	this->setPosition(this->getPosition() + direction * speed);
}

void PlayerObject::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->move(sf::Vector2f(0, -1), _speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->move(sf::Vector2f(0, 1), _speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->move(sf::Vector2f(-1, 0), _speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move(sf::Vector2f(1, 0), _speed);
	}
}

void PlayerObject::setSpeed(int speed)
{
	this->_speed = speed;
}

