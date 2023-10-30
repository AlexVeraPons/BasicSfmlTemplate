#include "textHighliteButton.hpp"

TextHighliteButton::TextHighliteButton(std::string identifier,
	sf::Font& font,
	std::string buttonText,
	sf::Vector2f size) : Button(identifier, font, buttonText, size)
{
	this->textColor = this->text.getFillColor();
	this->fillColor = this->shape.getFillColor();

	this->originalTextSize = this->text.getScale();
	this->originalShapeSize = this->shape.getScale();

	this->text.setFont(font);
	//print font name
	printf("font name: %s\n", font.getInfo().family.c_str());
}

TextHighliteButton::~TextHighliteButton() { }


void TextHighliteButton::onHoverEnter()
{
	this->text.setFillColor(highliteTextColor);
	this->shape.setFillColor(highliteFillColor);
	this->text.setScale(originalTextSize.x * growFactor, originalTextSize.y * growFactor);
	this->shape.setScale(originalShapeSize.x * growFactor, originalShapeSize.y * growFactor);
}

void TextHighliteButton::onHoverExit()
{
	this->text.setFillColor(textColor);
	this->shape.setFillColor(fillColor);
	this->text.setScale(originalTextSize.x, originalTextSize.y);
	this->shape.setScale(originalShapeSize.x, originalShapeSize.y);
}

void TextHighliteButton::onHover()
{
}

void TextHighliteButton::setHighliteTextColor(const sf::Color color)
{
	highliteTextColor = color;
}

void TextHighliteButton::setHighliteFillColor(const sf::Color color)
{
	highliteFillColor = color;
}

void TextHighliteButton::setGrowFactor(const float factor)
{
	growFactor = factor;
}

void TextHighliteButton::onClick()
{
	Button::onClick();
}

void TextHighliteButton::start()
{
}

void TextHighliteButton::render(sf::RenderWindow& window)
{
	Button::render(window);
}
