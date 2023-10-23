#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

#include "TurnBasedGame.hpp"
#include "main.h"

const int _windowWidth = 1280;
const int _windowHeight = 720;

const sf::Color _backgroundColor = sf::Color(128, 128, 128);

const std::string _latoRegularFontPath = "Assets/Fonts/Lato-Regular.ttf";

int main() {

	sf::RenderWindow window(sf::VideoMode(_windowWidth, _windowHeight), "TurnBasedGame", sf::Style::Close);
	SceneHandler handler;

	sf::Font font;
	font.loadFromFile(_latoRegularFontPath);

	sceneSetup(font, handler, window);
	gameLoop(window, handler);

	return 0;
}

void gameLoop(sf::RenderWindow& window, SceneHandler& handler)
{
	ScoreFileIO scoreFileIO("Assets/Savedata/score.txt");


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

void sceneSetup(sf::Font& font, SceneHandler& handler, sf::RenderWindow& window)
{
	Scene mainScreen("mainScreen");
	Scene gameScreen("gameScreen");

	mainScreenSetup(font, handler, mainScreen, gameScreen, window);

	handler.addScene(mainScreen);
	handler.addScene(gameScreen);
}

void mainScreenSetup(sf::Font& font, SceneHandler& handler, Scene& mainScreen, Scene& gameScreen, sf::RenderWindow& window)
{
	sf::Vector2f mainScreenButtonsize(200, 100);

	//playbutton
	TextHighliteButton* play = new TextHighliteButton("play", font, "Play", mainScreenButtonsize);
	play->setPosition(sf::Vector2f(100, 100));
	play->setHighliteFillColor(sf::Color::Transparent);
	play->setHighliteTextColor(sf::Color::Cyan);
	play->setOutlineColor(sf::Color::Transparent);
	play->setOnClickAction([&handler, &mainScreen, &gameScreen]() {
		handler.stackScene("gameScreen");
		});
	mainScreen.addGameObject(*play);


	//erasedata button
	//TODO: make the save class and make this button work
	TextHighliteButton* eraseData = new TextHighliteButton("eraseData", font, "Erase Data", mainScreenButtonsize);
	eraseData->setPosition(sf::Vector2f(100, 200));
	eraseData->setHighliteFillColor(sf::Color::Transparent);
	eraseData->setHighliteTextColor(sf::Color::Cyan);
	eraseData->setOutlineColor(sf::Color::Transparent);
	mainScreen.addGameObject(*eraseData);



	//quitbutton
	TextHighliteButton* quit = new TextHighliteButton("quit", font, "Quit", mainScreenButtonsize);
	quit->setPosition(sf::Vector2f(100, 300));
	quit->setHighliteFillColor(sf::Color::Transparent);
	quit->setHighliteTextColor(sf::Color::Cyan);
	quit->setOutlineColor(sf::Color::Transparent);
	quit->setOnClickAction([&window]() {
		window.close();
		});
	mainScreen.addGameObject(*quit);

}







