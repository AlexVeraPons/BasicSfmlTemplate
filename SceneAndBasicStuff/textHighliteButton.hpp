#pragma once
#include "button.hpp"
#include <string>


class TextHighliteButton : public Button {

private:
	sf::Color textColor;
	sf::Color fillColor;
	sf::Color highliteTextColor = sf::Color::Yellow;
	sf::Color highliteFillColor = sf::Color::Black;

	sf::Vector2f originalTextSize;
	sf::Vector2f originalShapeSize;
	float growFactor = 1.1f;

public:
	TextHighliteButton(std::string identifier, sf::Font& font, std::string buttonText,
		sf::Vector2f size);
	~TextHighliteButton();

public:
	void start() override;
	void render(sf::RenderWindow& window) override;
	void setHighliteTextColor(const sf::Color color);
	void setHighliteFillColor(const sf::Color color);
	void setGrowFactor(const float factor);

private:
	// Inherited via Button
	void onClick() override;
	void onHover() override;
	void onHoverEnter() override;
	void onHoverExit() override;
};
