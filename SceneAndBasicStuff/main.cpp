#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "TurnBasedGame.hpp"
#include "main.h"

const int _windowWidth = 1280;
const int _windowHeight = 720;
const sf::Color _backgroundColor = sf::Color(128, 128, 128);
const std::string _latoRegularFontPath = "Assets/Fonts/Lato-Regular.ttf";
const std::string _scoreFilePath = "Savedata/score.txt";


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
	play->setOnClickAction([&]() {  // capture by value if you don't want to capture the pointers
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










