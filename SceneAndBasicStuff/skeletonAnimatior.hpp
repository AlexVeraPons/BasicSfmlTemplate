#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "animatedSprite.hpp"
#include "gameObject.hpp"
#include "assetManager.hpp"

class SkeletonAnimatior : public GameObject
{
private:
	AnimatedSprite _idleAnimation;
	AnimatedSprite _attackAnimation;
	AnimatedSprite _hurtAnimation;
	AnimatedSprite _deathAnimation;

	AnimatedSprite* _nextAnimation;
	AnimatedSprite* _currentAnimation;

public:
	SkeletonAnimatior();
	~SkeletonAnimatior();

	void start() override;
	void update() override;
	void render(sf::RenderWindow& window) override;
	void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;

	void playIdleAnimation();
	void playAttackAnimation();
	void playHurtAnimation();
	void playDeathAnimation();

	void flip(const bool& flip);
	void setColor(const sf::Color& color);
	void setPosition(const sf::Vector2f position) override;
};

