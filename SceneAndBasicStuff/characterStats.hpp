#pragma once
#include <string>
struct CharacterStats
{
	unsigned int attack;
	unsigned int speed;
	unsigned int health;
	
	CharacterStats();
	CharacterStats(unsigned int attack, unsigned int speed, unsigned int health);
}	;
	