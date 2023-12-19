#include "characterFactory.hpp"
CharacterFactory::CharacterFactory() { }

CharacterFactory::~CharacterFactory() { }

CharacterData CharacterFactory::operator()(std::string name, uint hp, uint attack, uint speed, uint health)
{
	return createFighter(name, hp, attack, speed, health);
}

CharacterData CharacterFactory::operator()(std::string name, uint difficultyLevel)
{
	return createFighter(name, difficultyLevel);
}

CharacterData CharacterFactory::operator()(uint difficultyLevel)
{
	return createFighter("Enemy", difficultyLevel);
}

CharacterData CharacterFactory::createFighter(std::string name, uint hp, uint attack, uint speed, uint health)
{
	CharacterStats stats(attack, speed, health);
	CharacterData data(name, stats);
	return data;
}

CharacterData CharacterFactory::createFighter(std::string name, uint difficultyLevel)
{
	CharacterStats stats = getRandomStats(difficultyLevel);
	CharacterData data(name, stats);
	return data;
}

CharacterStats CharacterFactory::getRandomStats(uint difficultyLevel)
{
	int modifier = (difficultyLevel < CharacterStats()._maxStatValue) ? difficultyLevel : CharacterStats()._maxStatValue;
	int attack = rand() % 10 + difficultyLevel;
	int health = rand() % 10 + (difficultyLevel + 5);
	int speed = rand() % 10 + difficultyLevel + 3;
	return CharacterStats(attack, speed, health);
}
