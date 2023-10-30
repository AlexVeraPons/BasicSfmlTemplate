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

void SetupGameScreen(Scene* gameScreen, sf::Font& font, Scene* mainScreen)
{
	FightController* fightController = new FightController();
	CharacterData playerData("Player", sf::Sprite(), 100, 20, 20);
	CharacterData enemyData("Enemy", sf::Sprite(), 100, 19, 19);

	FightCharacter enemy(enemyData);
	FightCharacter player(playerData);

	fightController->setupFight(player, enemy);
	gameScreen->addGameObject(*fightController);

	//print the font name
	printf("Font name: %s\n", font.getInfo().family.c_str());

	ActionSelectorUI* actionSelectorUI = new ActionSelectorUI("actionSelectorUI", sf::Vector2f(0.0f,0.0f), _windowWidth, _windowHeight);

	sf::Vector2f mainScreenButtonsize = sf::Vector2f(200, 100);
	TextHighliteButton* play = new TextHighliteButton("play", font, "2", mainScreenButtonsize);
	play->setPosition(sf::Vector2f(100, 100));
	play->setHighliteTextColor(sf::Color::Cyan);
	play->setHighliteFillColor(sf::Color::Blue);
	play->setOutlineColor(sf::Color::Transparent);
	play->setOnClickAction([&]() {  // capture by value if you don't want to capture the pointers
		});

	// erase data button
	TextHighliteButton* eraseData = new TextHighliteButton("eraseData", font, "3 Data", mainScreenButtonsize);
	eraseData->setPosition(sf::Vector2f(100, 200));
	eraseData->setHighliteTextColor(sf::Color::Cyan);
	eraseData->setOutlineColor(sf::Color::Transparent);
	eraseData->setHighliteFillColor(sf::Color::Blue);
	eraseData->setOnClickAction([=]() {
		});

	// quit button
	TextHighliteButton* quit = new TextHighliteButton("quit", font, "4", mainScreenButtonsize);
	quit->setPosition(sf::Vector2f(100, 300));
	quit->setHighliteTextColor(sf::Color::Cyan);
	quit->setOutlineColor(sf::Color::Transparent);
	quit->setHighliteFillColor(sf::Color::Blue);
	quit->setOnClickAction([&]() {
		printf("Quit button clicked\n");
		});

	actionSelectorUI->addButton(play);
	actionSelectorUI->addButton(eraseData);
	actionSelectorUI->addButton(quit);

	gameScreen->addGameObject(*actionSelectorUI);
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
}

void SetupMainScreen(sf::Font& font, Scene* mainScreen, SceneHandler& handler, sf::RenderWindow& window)
{

	sf::Vector2f mainScreenButtonsize(200, 100);

	// scoreboard
	Scoreboard* scoreboard = new Scoreboard("scoreboard", sf::Vector2f(_windowWidth - _windowWidth / 6, _windowHeight / 4), _scoreFilePath, font);
	mainScreen->addGameObject(*scoreboard);

	// play button
	TextHighliteButton* play = new TextHighliteButton("play", font, "Play", mainScreenButtonsize);
	play->setPosition(sf::Vector2f(100, 100));
	play->setHighliteFillColor(sf::Color::Transparent);
	play->setHighliteTextColor(sf::Color::Cyan);
	play->setOutlineColor(sf::Color::Transparent);
	play->setOnClickAction([&]() {  
		handler.stackScene("gameScreen");
		});
	mainScreen->addGameObject(*play);

	// erase data button
	TextHighliteButton* eraseData = new TextHighliteButton("eraseData", font, "Erase Data", mainScreenButtonsize);
	eraseData->setPosition(sf::Vector2f(100, 200));
	eraseData->setHighliteFillColor(sf::Color::Transparent);
	eraseData->setHighliteTextColor(sf::Color::Cyan);
	eraseData->setOutlineColor(sf::Color::Transparent);
	eraseData->setOnClickAction([=]() {
		scoreboard->clearScores();
		});
	mainScreen->addGameObject(*eraseData);

	// quit button
	TextHighliteButton* quit = new TextHighliteButton("quit", font, "Quit", mainScreenButtonsize);
	quit->setPosition(sf::Vector2f(100, 300));
	quit->setHighliteFillColor(sf::Color::Transparent);
	quit->setHighliteTextColor(sf::Color::Cyan);
	quit->setOutlineColor(sf::Color::Transparent);
	quit->setOnClickAction([&]() {
		window.close();
		});
	mainScreen->addGameObject(*quit);

}











