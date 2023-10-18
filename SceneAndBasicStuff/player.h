#pragma once
#include "gameObject.hpp"

class Player : public GameObject {
public:
    Player(std::string identifier);
    Player(const GameObject& other);

    virtual ~Player();

private:
    const std::string identifier;
public:
    // Inherited via GameObject
    void update() override;
    void render(sf::RenderWindow& window) override;
    void start() override;
};