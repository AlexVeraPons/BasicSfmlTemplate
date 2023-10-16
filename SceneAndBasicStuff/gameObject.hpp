#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class GameObject {
private:
    const std::string identifier;
    std::vector<GameObject*> childGameObjects;
    void setParent(GameObject* parent);
protected:
    GameObject* parent = nullptr;
public:
    GameObject(std::string identifier);
    GameObject(const GameObject& other);

    virtual ~GameObject();
public:
    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    std::string getIdentifier() const;
    GameObject* getParent() const;
    void addChild(GameObject* child);
    void deleteChildFromList(std::string identifier);
    void seperateFromParent();
};