#include <iostream>
#include "gameObject.hpp"

GameObject::GameObject(std::string identifier) : identifier(identifier) { }

GameObject::GameObject(const GameObject& other) : identifier(other.getIdentifier()) { }

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
			this->childGameObjects.erase(childGameObjects.begin()+i);
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
	}
}


