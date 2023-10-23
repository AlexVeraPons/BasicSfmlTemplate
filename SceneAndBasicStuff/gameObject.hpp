#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class GameObject {
private:
	const std::string identifier;
public:
	GameObject(std::string identifier);
	GameObject(const GameObject& other);

	virtual ~GameObject();
public:

	/*
		 Handles events like keyboard/mouse input.
		 
		 @param event The event object containing details about the event.
		 @param window The render window where events are captured.
	*/
	virtual void handleEvent(const sf::Event& event, sf::RenderWindow& window) { };

	/*
		 Called whenever a scene starts.
	*/
	virtual void start();

	virtual void update() = 0;
	virtual void render(sf::RenderWindow& window) = 0;
	std::string getIdentifier() const;
};