#pragma once

#include <map>
#include <string>

#include "gameObject.hpp"
#include "animatedSprite.hpp"
#include "SFML/Graphics.hpp"

class AnimationController : public GameObject
{
private:
	std::map<std::string, std::shared_ptr<AnimatedSprite>> _animations;
	std::string _defaultAnimation;
	std::string _currentAnimation;
	std::string _bufferedAnimation;

public:
	AnimationController();
	AnimationController(std::string identifier);
	AnimationController(const AnimationController& other);
	~AnimationController();

	void addAnimation(const std::string& name, std::shared_ptr<AnimatedSprite> animation);
	void deleteAnimation(const std::string& name);
	void bufferAnimation(const std::string& name);
	void setDefaultAnimation(const std::string& name);
	void setColor(const sf::Color& color);
	void flip(const bool& flip);

	// Inherited via GameObject
	virtual void start() override;
	virtual void update() override;
	virtual void render(sf::RenderWindow& window) override;

	void setPosition(const sf::Vector2f position) override;
private:
	void startAnimationChange();
};

