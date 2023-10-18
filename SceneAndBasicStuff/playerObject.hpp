#pragma once
#include "spriteObject.hpp"

class PlayerObject : public SpriteObject {
private:
	float _speed = 0.1;
	void move(sf::Vector2f direction,float speed);
	void handleInput();
public:
	void update() override;

	PlayerObject(std::string identifier, std::string spriteFile);
	PlayerObject(std::string identifier, std::string spriteFile, sf::Vector2f position);
	PlayerObject(const PlayerObject& other);
	~PlayerObject();

	void setSpeed(int speed);
};


