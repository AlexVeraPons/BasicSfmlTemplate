#pragma once
#include <memory>
#include <string>

#include "observer.hpp"
#include "gameObject.hpp"
#include "fightCharacter.hpp"
#include "turnIndicatorEntityUI.hpp"

#include "SFML/Graphics.hpp"

class TurnIndicatorEntityUI;

class TurnIndicatorUI : public GameObject
{
private:
	sf::RectangleShape _rectBackground;
	std::unique_ptr<TurnIndicatorEntityUI>_entity1Indicator;
	std::unique_ptr<TurnIndicatorEntityUI>_entity2Indicator;

public:
	TurnIndicatorUI();
	TurnIndicatorUI(std::string identifier, sf::Vector2f position, sf::Vector2f size, FightCharacter* fighter1, FightCharacter* fighter2);
	~TurnIndicatorUI();

	sf::Vector2f getSize() const;
	void setPosition(sf::Vector2f position) override;
	void render(sf::RenderWindow& window) override;
	void update() override;
	void setEntityReferences(FightCharacter* fighter1, FightCharacter* fighter2);

private:


};

