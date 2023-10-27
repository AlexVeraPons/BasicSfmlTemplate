#include "button.hpp"

#include <SFML/Window/Event.hpp>

Button::Button(std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size) :
	GameObject(identifier), font(font), buttonText(buttonText)
{
	this->shape.setSize(size);
	this->shape.setFillColor(sf::Color::Transparent);
	this->shape.setOutlineColor(sf::Color::Black);
	this->shape.setOutlineThickness(1);

	this->text.setFont(font);
	this->text.setString(buttonText);
	this->text.setCharacterSize(26);
	this->text.setFillColor(sf::Color::White);

	sf::FloatRect textRect = this->text.getLocalBounds();
	this->text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

	this->setPosition(sf::Vector2f(0.0f, 0.0f));
}

Button::~Button() { }

void Button::handleEvent(const sf::Event& event, sf::RenderWindow& window) {

	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f position = shape.getPosition();
	sf::Vector2f size = shape.getSize();

	// Check if mouse is inside button
	if (mousePosition.x >= position.x && mousePosition.x <= position.x + size.x &&
		mousePosition.y >= position.y && mousePosition.y <= position.y + size.y) {

		if (startedHovering == false)
		{
			this->onHoverEnter();
			startedHovering = true;

		}
		this->onHover();

		// Check if mouse is clicked
		if (event.type == sf::Event::MouseButtonPressed) {
			this->onClick();
		}
	}
	else
	{
		if (startedHovering == true)
		{
			this->onHoverExit();
			startedHovering = false;
		}
	}

}

void Button::update() { }

void Button::render(sf::RenderWindow& window) {
	window.draw(this->shape);
	window.draw(this->text);
}

void Button::setOnClickAction(buttonAction action)
{
	this->action = action;
}


void Button::setCharacterSize(const int size) {
	this->text.setCharacterSize(size);
}

void Button::setPosition(const sf::Vector2f position) {
	GameObject::setPosition(position);
	
	this->shape.setPosition(position);
	sf::Vector2f size = this->shape.getSize();
	sf::Vector2f centerButton(position.x + (size.x / 2.0f), position.y + (size.y / 2.0f));
	this->text.setPosition(centerButton);
}

void Button::setFillColor(const sf::Color color)
{
	this->shape.setFillColor(color);
}

void Button::setOutlineColor(const sf::Color color)
{
	this->shape.setOutlineColor(color);
}

void Button::setOutlineThickness(const float thickness)
{
		this->shape.setOutlineThickness(thickness);
}

void Button::setTextColor(const sf::Color color)
{
	this->text.setFillColor(color);
}

void Button::setTextSize(const int size)
{
	this->text.setCharacterSize(size);
}

void Button::onClick() {
	if (this->action)
	{
		this->action();
	}
}

