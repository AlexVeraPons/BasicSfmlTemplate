#include <iostream>
#include <string>

#include "battleLog.hpp"


BattleLog::BattleLog(std::string identifier, sf::Vector2f position, float width, float height, sf::Font& font) : GameObject(identifier,position)
{
	_width = width;
	_height = height;
	
	_mainText.setFont(font);
	_mainText.setPosition(position);
	_mainText.setCharacterSize(26);
	_mainText.setFillColor(sf::Color::White);
	_mainText.setOutlineColor(sf::Color::White);
	_mainText.setString("Battle Log");

	_pastText.setFont(font);
	_pastText.setPosition(position + sf::Vector2f(0, _mainText.getCharacterSize() + 4));
	_pastText.setCharacterSize(26);
	_pastText.setFillColor(_defaultColor);
	_pastText.setOutlineColor(_defaultColor);



	_background.setPosition(position);
	_background.setSize(sf::Vector2f(width, height));
	_background.setFillColor(sf::Color::Black);
}

BattleLog::~BattleLog()
{
}

void BattleLog::start()
{
	clear();
}

void BattleLog::render(sf::RenderWindow& window)
{
	window.draw(_background);
	window.draw(_mainText);
	window.draw(_pastText);
}

void BattleLog::clear()
{
	_mainText.setString(" ");
	_pastText.setString(" ");
}

void BattleLog::onNotified(const std::string& value)
{
	addLine(value);
}

void BattleLog::addLine(std::string line)
{
	std::string pastText = _mainText.getString() + "\n" + _pastText.getString();
	std::string mainText = line;
	_mainText.setString(mainText);
	_pastText.setString(pastText);
}
