#include "characterStats.hpp"

CharacterStats::CharacterStats() : attack(0), speed(0), health(0), maxHealth(0) { }

CharacterStats::CharacterStats(unsigned int attack, unsigned int speed, unsigned int health)
{
	this->attack = (attack <= _maxStatValue) ? attack : _maxStatValue;
	this->speed = (speed <= _maxStatValue) ? speed : _maxStatValue;
	this->health = (health <= _maxStatValue) ? health * 10 : _maxStatValue * 10;
	this->maxHealth = this->health;
}

CharacterStats& CharacterStats::operator=(const CharacterStats& other)
{
	attack = other.attack;
	speed = other.speed;
	health = other.health;
	maxHealth = other.maxHealth;
	return *this;
}

void CharacterStats::setHealth(unsigned int health)
{
	this->health = (health <= _maxStatValue) ? health * 10 : _maxStatValue * 10;
	this->maxHealth = this->health;
}

unsigned int CharacterStats::getHealth()
{
	return health;
}
