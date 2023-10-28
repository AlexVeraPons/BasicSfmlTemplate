#include "characterStats.hpp"

CharacterStats::CharacterStats() : attack(0), speed(0), health(0) { }

CharacterStats::CharacterStats(unsigned int attack, unsigned int speed, unsigned int health)
{
	this->attack = (attack<=_maxStatValue) ? attack: _maxStatValue;
	this->speed = (speed <= _maxStatValue) ? speed : _maxStatValue;
	this->health = (health <= _maxStatValue) ? health : _maxStatValue;
}

CharacterStats& CharacterStats::operator=(const CharacterStats& other)
{
	attack = other.attack;
	speed = other.speed;
	health = other.health;
	return *this;
}
