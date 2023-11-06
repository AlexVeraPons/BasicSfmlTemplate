#include "rectangleGameObject.hpp"
#include <SFML/Graphics.hpp>
#include "gameObject.hpp"

RectangleGameObject::RectangleGameObject() : GameObject()
{
	_shape = sf::RectangleShape(sf::Vector2f(100, 100));

	_color = sf::Color::White;
	_shape.setFillColor(_color);

	position = sf::Vector2f(0, 0);
	_shape.setPosition(position);

	_size = sf::Vector2f(100, 100);
	_shape.setSize(_size);
}

RectangleGameObject::RectangleGameObject(std::string identifier, const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color) : GameObject(identifier, position)
{
	_shape = sf::RectangleShape(size);

	_color = color;
	_shape.setFillColor(_color);

	_size = size;
	_shape.setSize(_size);
}

RectangleGameObject::~RectangleGameObject() { }

void RectangleGameObject::render(sf::RenderWindow& window)
{
	window.draw(_shape);
}

void RectangleGameObject::setPosition(const sf::Vector2f& position)
{
	this->position = position;
	_shape.setPosition(position);
}

void RectangleGameObject::setSize(const sf::Vector2f& size)
{
	_size = size;
	_shape.setSize(_size);
}

void RectangleGameObject::setColor(const sf::Color& color)
{
	_color = color;
	_shape.setFillColor(_color);
}

const sf::Vector2f& RectangleGameObject::getSize() const
{
	return _size;
}

const sf::Color& RectangleGameObject::getColor() const
{
	return _color;
}
