#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

#include "scene.hpp"
#include "spriteObject.hpp"
#include "sceneHandler.hpp"

std::string _headSprite = "Assets/Sprites/head.png";
std::string _headHurtSprite = "Assets/Sprites/head_hurt.png";

const int _windowWidth = 800;
const int _windowHeight = 800;

int main() {
	sf::RenderWindow window(sf::VideoMode(_windowWidth, _windowHeight), "SFML with Scenes!");

	Scene scene01("scene01");


	SceneHandler handler;
	handler.addScene(scene01);

	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::A)
				{
					handler.stackScene("scene02");
				}
			}
		}

		window.clear();
		handler.update();
		handler.render(window);
		window.display();
	}

	return 0;
}





