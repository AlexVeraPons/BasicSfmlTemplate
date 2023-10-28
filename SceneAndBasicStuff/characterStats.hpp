#pragma once
#include <string>
struct CharacterStats
{
	unsigned int attack;
	unsigned int speed;
	unsigned int health;
	
	CharacterStats();
	CharacterStats(unsigned int attack, unsigned int speed, unsigned int health);
	CharacterStats& operator=(const CharacterStats& other);

private:
	const unsigned int _maxStatValue = 10;
};
	