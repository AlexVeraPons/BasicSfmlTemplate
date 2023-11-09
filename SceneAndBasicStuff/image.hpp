#pragma once
#include "gameObject.hpp"
#include "SFML/Graphics.hpp"
#include <string>


struct Image : public GameObject
{
	std::unique_ptr<sf::Texture> texture;
	sf::Sprite sprite;
	Image(std::string identifier, sf::Texture texture);
	~Image();

	void update() override;

	void render(sf::RenderWindow& window) override;
};

