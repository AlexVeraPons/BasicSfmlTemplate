#pragma once
#include <SFML/Graphics.hpp>

#include "gameObject.hpp"
#include "observer.hpp"
#include "fightCharacter.hpp"

class HealthBar : public GameObject, public Observer<float>
{
private:
	sf::RectangleShape _background;
	sf::RectangleShape _innerBar;

	sf::Vector2f _position;
	sf::Vector2f _size;

	float _maxWidth;
	float _maxHealth;
	float _currentHealth;
public:
	HealthBar(std::string identifier, sf::Vector2f position, FightCharacter* owner);
	~HealthBar();

	sf::Vector2f getSize() const;
	void setPosition(sf::Vector2f position) override;
	
	void render(sf::RenderWindow& window) override;
	void onNotified(const float& value) override;
	void setOwner(FightCharacter* owner);


private:
	void updateBar(const float& value);
	void updateBarColor();
};

