#pragma once
#include <string>
struct CharacterStats
{
	const unsigned int _maxStatValue = 10;

	unsigned int attack;
	unsigned int maxHealth;
	unsigned int speed;
	int health;
	
	CharacterStats();
	CharacterStats(unsigned int attack, unsigned int speed, unsigned int health);
	CharacterStats& operator=(const CharacterStats& other);

	unsigned int getHealth();
	void setHealth(unsigned int health);
};
	