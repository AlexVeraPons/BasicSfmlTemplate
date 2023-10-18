#include <iostream>
#include "gameObject.hpp"

GameObject::GameObject(std::string identifier) : identifier(identifier) {
	this->absolutePosition = sf::Vector2f(0, 0);
	this->relativePosition = sf::Vector2f(0, 0);
}

GameObject::GameObject(const GameObject& other) : identifier(other.getIdentifier()) {
	this->absolutePosition = other.absolutePosition;
	this->relativePosition = other.relativePosition;
	this->parent = other.parent;
	this->childGameObjects = other.childGameObjects;
}

GameObject::GameObject(std::string identifier, sf::Vector2f position) : identifier(identifier), absolutePosition(position)
{
	this->relativePosition = sf::Vector2f(0, 0);
}

GameObject::~GameObject() { }

std::string GameObject::getIdentifier() const {
	return this->identifier;
}

GameObject* GameObject::getParent() const {
	return this->parent;
}

void GameObject::setParent(GameObject* parent)
{
	this->parent = parent;
	relativePosition = this->absolutePosition - parent->getPosition();
}

void GameObject::addChild(GameObject* child)
{
	this->childGameObjects.push_back(child);
	child->setParent(this);
}

void GameObject::deleteChildFromList(std::string identifier)
{
	for (int i = 0; i < this->childGameObjects.size(); i++)
	{
		if (childGameObjects[i]->getIdentifier() == identifier)
		{
			this->childGameObjects.erase(childGameObjects.begin() + i);
			return;
		}
	}
}

void GameObject::seperateFromParent()
{
	if (this->parent != nullptr)
	{
		parent->deleteChildFromList(this->getIdentifier());
		this->parent = nullptr;
		this->relativePosition = this->absolutePosition;
	}
}

sf::Vector2f GameObject::getPositionRelativeFromParent() const
{
	return this->relativePosition;
}

sf::Vector2f GameObject::getPosition() const
{
	if (this->parent != nullptr)
	{
		return this->parent->getPosition() + this->relativePosition;
	}
	else
	{
		return this->absolutePosition;
	}
}

void GameObject::setPosition(sf::Vector2f position) {
	this->absolutePosition = position;
	if (parent != nullptr)
	{
		this->relativePosition = this->absolutePosition - parent->getPosition();
	}
}


