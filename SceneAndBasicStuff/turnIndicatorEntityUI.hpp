#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "observer.hpp"
#include "turnIndicatorUI.hpp"

class TurnIndicatorUI;

class TurnIndicatorEntityUI : public Observer<float>
{
private:
	sf::CircleShape _mainCircle;
	unsigned int const _radius = 20;
	float const _turnIndicatorWidth;
	float const _turnIndicatorHeight;
	sf::Vector2f _turnIndicatorPosition;

public:
	TurnIndicatorEntityUI(sf::Vector2f position, sf::Color color, TurnIndicatorUI* turnIndicatorUI);
	~TurnIndicatorEntityUI();

	sf::Vector2f getPosition() const;

	void render(sf::RenderWindow& window);
	void setPosition(sf::Vector2f position);

	void onNotified(const float& value) override;
};
