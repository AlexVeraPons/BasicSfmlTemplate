#include "image.hpp"

Image::Image(std::string identifier, sf::Texture texture) : GameObject(identifier)
{
	this->texture = std::make_unique<sf::Texture>(texture);
	this->sprite.setTexture(*this->texture);
}
Image::~Image() { }
void Image::update() { }
void Image::render(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}
