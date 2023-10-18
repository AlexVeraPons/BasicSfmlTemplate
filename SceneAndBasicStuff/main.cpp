#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

#include "scene.hpp"
#include "spriteObject.hpp"
#include "sceneHandler.hpp"
#include "playerObject.hpp"

std::string _headSprite = "Assets/Sprites/head.png";
std::string _headHurtSprite = "Assets/Sprites/head_hurt.png";

const int _windowWidth = 800;
const int _windowHeight = 800;

int main() {
	sf::RenderWindow window(sf::VideoMode(_windowWidth, _windowHeight), "SFML with Scenes!");
	
	Scene mainScene("scene01");

	SceneHandler handler;
	handler.addScene(mainScene);

	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();
		handler.update();
		handler.render(window);
		window.display();
	}

	return 0;
}





