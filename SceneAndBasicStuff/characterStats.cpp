#include "characterStats.hpp"

CharacterStats::CharacterStats() : attack(0), speed(0), health(0) { }

CharacterStats::CharacterStats(unsigned int attack, unsigned int speed, unsigned int health)
{
	this->attack = attack;
	this->speed = speed;
	this->health = health;
}
