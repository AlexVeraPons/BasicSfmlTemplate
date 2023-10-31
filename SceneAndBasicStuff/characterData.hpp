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
	/*
		 @param name The name of the character.
		 @param sprite The sprite of the character.
		 @param attack The attack of the character.
		 @param speed The speed of the character.
		 @param health The health of the character.
	*/
	CharacterData(std::string name, sf::Sprite sprite, unsigned int attack, unsigned int speed, unsigned int health);
	CharacterData& operator=(const CharacterData& other);
	bool operator==(const CharacterData& other);

};