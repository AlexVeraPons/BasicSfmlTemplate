#include <iostream>
#include "gameObject.hpp"


GameObject::GameObject() : identifier("GameObject"), position(sf::Vector2f(0, 0)) { }

GameObject::GameObject(std::string identifier) : identifier(identifier) { }

GameObject::GameObject(std::string identifier, sf::Vector2f position) : identifier(identifier), position(position) { }

GameObject::GameObject(const GameObject& other) : identifier(other.getIdentifier()) { }

GameObject::~GameObject() { }

void GameObject::setPosition(const sf::Vector2f position)
{
	this->position = position;
}

bool GameObject::isAlwaysActive() const
{
	return alwaysActive;
}

void GameObject::setAlwaysActive(const bool value)
{
	alwaysActive = value;
}

sf::Vector2f GameObject::getPosition() const
{
	return this->position;
}

std::string GameObject::getIdentifier() const {
	return this->identifier;
}

