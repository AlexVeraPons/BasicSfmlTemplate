#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "main.h"
#include "turnBasedGame.hpp"

const int _windowWidth = 1280;
const int _windowHeight = 720;
const sf::Color _backgroundColor = sf::Color(128, 128, 128);
const std::string _latoRegularFontPath = "Assets/Fonts/Lato-Regular.ttf";
const std::string _scoreFilePath = "Savedata/score.txt";

void SetupWindow(sf::RenderWindow& window);
void SetupScenes(SceneHandler& handler, sf::Font& font, sf::RenderWindow& window);
void SetupGameScreen(Scene* gameScreen, sf::Font& font, Scene* mainScreen);
void SetupMainScreen(sf::Font& font, Scene* mainScreen, SceneHandler& hanlder, sf::RenderWindow& window);
void GameLoop(sf::RenderWindow& window, SceneHandler& handler);

int main() {
	sf::RenderWindow window;
	SceneHandler handler;
	sf::Font font;
	font.loadFromFile(_latoRegularFontPath);

	SetupWindow(window);
	SetupScenes(handler, font, window);
	GameLoop(window, handler);

	return 0;
}

void SetupWindow(sf::RenderWindow& window) {
	window.create(sf::VideoMode(_windowWidth, _windowHeight), "TurnBasedGame", sf::Style::Close);
}

void SetupScenes(SceneHandler& handler, sf::Font& font, sf::RenderWindow& window) {
	Scene* mainScreen = new Scene("mainScreen");
	Scene* gameScreen = new Scene("gameScreen");

	SetupMainScreen(font, mainScreen, handler, window);
	SetupGameScreen(gameScreen, font, mainScreen);

	handler.addScene(*mainScreen);
	handler.addScene(*gameScreen);
}

void GameLoop(sf::RenderWindow& window, SceneHandler& handler) {
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			handler.handleEvent(event, window);
		}
		window.clear(_backgroundColor);
		handler.update();
		handler.render(window);
		window.display();
	}
	handler.onDisable();
}

void SetupMainScreen(sf::Font& font, Scene* mainScreen, SceneHandler& handler, sf::RenderWindow& window)
{
	sf::Vector2f mainScreenButtonsize(200, 100);

	// scoreboard
	auto scoreboard = std::make_unique<Scoreboard>("scoreboard", sf::Vector2f(_windowWidth - _windowWidth / 6, _windowHeight / 4), _scoreFilePath, font);
	mainScreen->addGameObject(std::move(scoreboard));

	// play button
	auto play = std::make_unique<TextHighliteButton>("play", font, "Play", mainScreenButtonsize);
	play->setPosition(sf::Vector2f(100, 100));
	play->setHighliteFillColor(sf::Color::Transparent);
	play->setHighliteTextColor(sf::Color::Cyan);
	play->setOutlineColor(sf::Color::Transparent);
	play->setOnClickAction([&handler]() {
		handler.stackScene("gameScreen");
		});
	mainScreen->addGameObject(std::move(play));

	// erase data button
	auto eraseData = std::make_unique<TextHighliteButton>("eraseData", font, "Erase Data", mainScreenButtonsize);
	eraseData->setPosition(sf::Vector2f(100, 200));
	eraseData->setHighliteFillColor(sf::Color::Transparent);
	eraseData->setHighliteTextColor(sf::Color::Cyan);
	eraseData->setOutlineColor(sf::Color::Transparent);
	eraseData->setOnClickAction([mainScreen]() {
		GameObject* gameObject = mainScreen->getGameObject("scoreboard");
		Scoreboard* scoreboard = dynamic_cast<Scoreboard*>(gameObject);
		if (scoreboard) {
			scoreboard->clearScores();
		}
		});
	mainScreen->addGameObject(std::move(eraseData));

	// quit button
	auto quit = std::make_unique<TextHighliteButton>("quit", font, "Quit", mainScreenButtonsize);
	quit->setPosition(sf::Vector2f(100, 300));
	quit->setHighliteFillColor(sf::Color::Transparent);
	quit->setHighliteTextColor(sf::Color::Cyan);
	quit->setOutlineColor(sf::Color::Transparent);
	quit->setOnClickAction([&]() {
		window.close();
		});
	mainScreen->addGameObject(std::move(quit));
}


void SetupGameScreen(Scene* gameScreen, sf::Font& font, Scene* mainScreen)
{

	CharacterData playerData;
	playerData.name = "Player";
	playerData.stats.attack = 10;
	playerData.stats.health= 10;

	FightCharacter player(playerData);

	CharacterData enemyData;
	enemyData.name = "Enemy";
	enemyData.stats.attack = 10;
	enemyData.stats.health = 10;

	FightCharacter enemy(enemyData);

	FightController fightController();

	auto lightAttackButton = std::unique_ptr<TextHighliteButton>(new TextHighliteButton("lightAttack", font, "Light Attack", sf::Vector2f(_windowWidth / 4, _windowHeight / 4)));
	lightAttackButton->setHighliteFillColor(sf::Color(100, 100, 100));
	lightAttackButton->setGrowFactor(1);
	lightAttackButton->setOnClickAction([&]() {
		//AttackMove()();
		});

	auto actionSelectorUI = std::unique_ptr<ActionSelectorUI>(new ActionSelectorUI("actionSelectorUI", sf::Vector2f(_windowWidth / 2, _windowHeight - _windowHeight / 4), _windowWidth / 2, _windowHeight / 4));
	actionSelectorUI->addButton(std::move(lightAttackButton));


	gameScreen->addGameObject(std::move(actionSelectorUI));
}