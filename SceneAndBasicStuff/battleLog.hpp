#pragma once
#include <string>

#include "gameObject.hpp"
#include "observer.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class BattleLog : public GameObject, public Observer<std::string>
{
private:
	sf::Text _pastText;
	sf::Text _mainText;
	sf::RectangleShape _background;

	float _width;
	float _height;
public:
	BattleLog(std::string identifier, sf::Vector2f position, float width, float height, sf::Font& font);
	~BattleLog();

public:
	void render(sf::RenderWindow& window) override;

private:
	// Inherited via Observer
	void onNotified(const std::string& value) override;
	void addLine(std::string line);
};

