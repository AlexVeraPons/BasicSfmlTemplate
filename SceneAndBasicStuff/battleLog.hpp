#pragma once
#include <string>

#include "gameObject.hpp"
#include "observer.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class BattleLog : public GameObject, public Observer<std::string>
{
private:
	sf::Text _mainText;
	sf::Text _pastText;
	sf::RectangleShape _background;

	sf::Color const _defaultColor = sf::Color(100,100,100);

	float _width;
	float _height;
public:
	BattleLog(std::string identifier, sf::Vector2f position, float width, float height, sf::Font& font);
	~BattleLog();

public:
	void start() override;
	void render(sf::RenderWindow& window) override;
	void clear();

private:
	// Inherited via Observer
	void onNotified(const std::string& value) override;
	void addLine(std::string line);
};

