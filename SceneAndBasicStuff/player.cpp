#include "player.h"

Player::Player(std::string identifier) : GameObject(identifier)
{
}

Player::Player(const GameObject& other) : GameObject(other.getIdentifier())
{
}

Player::~Player()
{
}

void Player::update()
{
}

void Player::render(sf::RenderWindow& window)
{
}

void Player::start()
{
	printf("player started");
}

