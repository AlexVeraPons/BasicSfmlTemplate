#pragma once

#include "gameObject.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <functional>


typedef std::function<void()> buttonAction;

class Button : public GameObject {

protected:
	sf::Text text;
	sf::Font& font;
	sf::RectangleShape shape;
	std::string buttonText;
	bool startedHovering = false;

	buttonAction action;

public:
	Button(std::string identifier, sf::Font& font, std::string buttonText,
		sf::Vector2f size);
	~Button();


public:
	void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
	virtual void onClick();
	
	void update() override;
	void render(sf::RenderWindow& window) override;
	void setPosition(const sf::Vector2f position) override;
	
	void setOnClickAction(buttonAction action);
	void setCharacterSize(const int size);
	void setFillColor(const sf::Color color);
	void setOutlineColor(const sf::Color color);
	void setOutlineThickness(const float thickness);
	void setTextColor(const sf::Color color);
	void setTextSize(const int size);
	void setShapeSize(sf::Vector2f size);


protected:
	virtual void onHover() = 0;
	virtual void onHoverEnter() = 0;
	virtual void onHoverExit() = 0;

};

