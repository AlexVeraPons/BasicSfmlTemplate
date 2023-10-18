#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class GameObject {
private:
    const std::string identifier;
    sf::Vector2f absolutePosition;
    sf::Vector2f relativePosition;
    std::vector<GameObject*> childGameObjects;
    void setParent(GameObject* parent);
protected:
    GameObject* parent = nullptr;
public:
    GameObject(std::string identifier);
    GameObject(const GameObject& other);
    GameObject(std::string identifier, sf::Vector2f position);

    virtual ~GameObject();
public:
    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    std::string getIdentifier() const;
    GameObject* getParent() const;
    void addChild(GameObject* child);
    void deleteChildFromList(std::string identifier);
    void seperateFromParent();
    sf::Vector2f getPositionRelativeFromParent() const;
    sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f position);
};