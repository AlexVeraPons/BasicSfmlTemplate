#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

#include "scene.hpp"
#include "spriteObject.hpp"
#include "sceneHandler.hpp"
#include "playerObject.hpp"

std::string _headSprite = "Assets/Sprites/head.png";
std::string _headHurtSprite = "Assets/Sprites/head_hurt.png";

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML with Scenes!");
	Scene scene1("scene01");

	SpriteObject sprite("sprite1", _headHurtSprite);
	scene1.addGameObject(sprite);
	

	PlayerObject player("player", _headSprite);
	sprite.addChild(&player);
	scene1.addGameObject(player);


	SceneHandler handler;
	handler.addScene(scene1);

	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		s
		window.clear();
		handler.update();
		handler.render(window);
		window.display();
	}

	return 0;
}





