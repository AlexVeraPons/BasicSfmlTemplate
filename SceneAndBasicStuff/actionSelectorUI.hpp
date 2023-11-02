#pragma once
#include <vector>
#include "gameObject.hpp"
#include "button.hpp"
#include "fightCharacter.hpp"

class ActionSelectorUI : public GameObject
{
private:
	FightCharacter* _player;
	std::vector <std::unique_ptr<Button>> _buttons;
	sf::Color _buttonColor;
	float _width;
	float _height;
public:
	ActionSelectorUI(std::string identifier, sf::Vector2f position, float width, float height,FightCharacter& player);
	~ActionSelectorUI();
public:
	void start() override;
	void update() override;
	void render(sf::RenderWindow& window) override;
	void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
	void addButton(std::unique_ptr<Button> button);
	void setButtonColor(sf::Color color);
private:
	
	void setupButtonPositions();
	bool isPlayerActive();

};

