#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class GameObject {
private:
	const std::string identifier;
protected:
	sf::Vector2f position;

public:
	/*
		Default constructor. Sets the identifier to "GameObject" and the position to (0,0).
	*/
	GameObject();
	GameObject(std::string identifier);
	GameObject(std::string identifier, sf::Vector2f position);
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
	virtual void start() { };
	virtual void onDisable() { };
	virtual void update() { };
	virtual void render(sf::RenderWindow& window) { };
	virtual void setPosition(const sf::Vector2f position);
	void setAlwaysActive(const bool value);

	bool isAlwaysActive() const;
	virtual sf::Vector2f getPosition() const;
	std::string getIdentifier() const;
};