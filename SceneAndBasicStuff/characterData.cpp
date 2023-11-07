#include "characterData.hpp"

CharacterData::CharacterData(): name(""), sprite(sf::Sprite()), stats(CharacterStats()) { }

CharacterData::CharacterData(std::string name, CharacterStats stats) : name(name), sprite(sf::Sprite()), stats(stats) { }

CharacterData::CharacterData(std::string name, sf::Sprite sprite, CharacterStats stats) : name(name), sprite(sprite), stats(stats) { }

CharacterData::CharacterData(std::string name, sf::Sprite sprite, unsigned int attack, unsigned int speed, unsigned int health) : name(name), sprite(sprite), stats(attack, speed, health) { }

CharacterData& CharacterData::operator=(const CharacterData& other)
{
	name = other.name;
	sprite = other.sprite;
	stats = other.stats;
	return *this;
}

bool CharacterData::operator==(const CharacterData& other)
{
return name == other.name;
}
