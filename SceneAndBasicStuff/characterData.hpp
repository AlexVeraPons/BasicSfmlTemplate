#pragma once
#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include "characterStats.hpp"
struct CharacterData
{
	std::string name;
	sf::Sprite sprite;
	CharacterStats stats;

	CharacterData();
	CharacterData(std::string name, sf::Sprite sprite, CharacterStats stats);
	CharacterData(std::string name, sf::Sprite sprite, unsigned int attack, unsigned int speed, unsigned int health);
};