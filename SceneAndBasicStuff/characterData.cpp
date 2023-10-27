#include "characterData.hpp"

CharacterData::CharacterData(std::string name, sf::Sprite sprite, CharacterStats stats) : name(name), sprite(sprite), stats(stats) { }

CharacterData::CharacterData(std::string name, sf::Sprite sprite, unsigned int attack, unsigned int speed, unsigned int health) : name(name), sprite(sprite), stats(attack, speed, health) { }
