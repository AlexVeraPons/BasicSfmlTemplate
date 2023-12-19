#pragma once
#include "gameObject.hpp"
#include "healthBar.hpp"
#include "turnIndicatorUI.hpp"
#include "fightCharacter.hpp"
#include "SFML/Graphics.hpp"
#include "image.hpp"

class FightUI : public GameObject
{
private:
	HealthBar _healthBar1;
	HealthBar _healthBar2;

	Image _player;
	Image _enemy;

	TurnIndicatorUI _turnIndicatorUI;
	
public:
	FightUI();
	FightUI(std::string identifier, FightCharacter* fighter1, FightCharacter* fighter, sf::Vector2f windowSize);
	~FightUI();

	void render(sf::RenderWindow& window) override;
	void update() override;

	void setEntityReferences(FightCharacter* fighter1, FightCharacter* fighter2);
};

