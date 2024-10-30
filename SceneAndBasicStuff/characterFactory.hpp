#pragma once
#include "characterData.hpp"
#include "characterStats.hpp"

#include <string>

typedef unsigned int uint;
class CharacterFactory
{
public:
	CharacterFactory();
	~CharacterFactory();

	//override the () operator to create a fighter
	CharacterData operator()(std::string name, uint hp, uint attack, uint speed, uint health);
	CharacterData operator()(std::string name, uint difficultyLevel);
	CharacterData operator()(uint difficultyLevel);


private:
	CharacterData createFighter(std::string name, uint hp, uint attack, uint speed, uint health);
	CharacterData createFighter(std::string name, uint difficultyLevel);
	CharacterStats getRandomStats(uint difficultyLevel);
};


