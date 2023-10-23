#pragma once

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

#include "gameObject.hpp"

class Scene {
private:
    const std::string identifier;
    std::vector<GameObject*> listOfGameObjects;
    bool started;

public:
    Scene(std::string identifier);
    ~Scene();

public:
    void addGameObject(GameObject& object);

    void handleEvent(const sf::Event& event, sf::RenderWindow& window);
    void update();
    void render(sf::RenderWindow& window);
    void start();
    std::string getIdentifier() const;
};

