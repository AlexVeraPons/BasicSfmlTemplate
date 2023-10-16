#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <vector>


const int WINDOW_SIZE_X= 800;
const int WINDOW_SIZE_Y = 800;

int main() {

	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "BasicScene");

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		window.display();
	}

	return 0;
}