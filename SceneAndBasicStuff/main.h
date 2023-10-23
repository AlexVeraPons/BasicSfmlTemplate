#pragma once

void sceneSetup(sf::Font& font, SceneHandler& handler, sf::RenderWindow& window);

void mainScreenSetup(sf::Font& font, SceneHandler& handler, Scene& mainScreen, Scene& gameScreen, sf::RenderWindow& window);

void gameLoop(sf::RenderWindow& window, SceneHandler& handler);
