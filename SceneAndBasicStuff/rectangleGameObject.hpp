#pragma once
#include "gameObject.hpp"
#include <SFML/Graphics.hpp>

class RectangleGameObject : public GameObject
{
private:
sf::RectangleShape _shape;

	sf::Vector2f _size;
	sf::Color _color;

public:
	RectangleGameObject();
	RectangleGameObject(std::string identifier,const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color);
	~RectangleGameObject();

	void render(sf::RenderWindow& window) override;

	void setPosition(const sf::Vector2f& position);
	void setSize(const sf::Vector2f& size);
	void setColor(const sf::Color& color);

	const sf::Vector2f& getSize() const;
	const sf::Color& getColor() const;
};