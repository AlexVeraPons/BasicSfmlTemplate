#include "animationController.hpp"

AnimationController::AnimationController()
{
	_currentAnimation = "";
	_defaultAnimation = "";
	_bufferedAnimation = "";
}

AnimationController::AnimationController(std::string identifier) : GameObject(identifier),
_currentAnimation(""),
_defaultAnimation(""),
_bufferedAnimation("") { }

AnimationController::AnimationController(const AnimationController& other)
{
	_animations = other._animations;
	_defaultAnimation = other._defaultAnimation;
	_currentAnimation = other._currentAnimation;
	_bufferedAnimation = other._bufferedAnimation;

}

AnimationController::~AnimationController() { }

void AnimationController::addAnimation(const std::string& name, std::shared_ptr<AnimatedSprite> animation)
{
	_animations[name] = std::move(animation);
	_animations[name]->setPosition(position);
}

void AnimationController::deleteAnimation(const std::string& name)
{
	auto iterator = _animations.find(name);
	if (iterator != _animations.end())
	{
		_animations.erase(iterator);
	}
}

void AnimationController::bufferAnimation(const std::string& name)
{
	printf("Buffering animation: %s\n", name.c_str());
	_bufferedAnimation = name;
}

void AnimationController::setDefaultAnimation(const std::string& name)
{
	_defaultAnimation = name;

	for (auto& animation : _animations)
	{
		if (animation.first == _defaultAnimation)
		{
			animation.second->setLoop(true);
		}
		else
		{
			animation.second->setLoop(false);
		}
	}
}

void AnimationController::setColor(const sf::Color& color)
{
	for (auto& animation : _animations)
	{
		animation.second->setColor(color);
	}
}

void AnimationController::flip(const bool& flip)
{
	for (auto& animation : _animations)
	{
		animation.second->flip(flip);
	}
}

void AnimationController::start()
{
	setPosition(position);

	if (_defaultAnimation != "")
	{
		_currentAnimation = _defaultAnimation;
	}
	else
	{
		_currentAnimation = _animations.begin()->first;
	}

	if (_currentAnimation != "")
	{
		_animations[_currentAnimation]->play();
	}
}

void AnimationController::update()
{
	_animations[_currentAnimation]->update();

	if (_bufferedAnimation != "")
	{
		startAnimationChange();
	}

	if (_animations[_currentAnimation]->isPlaying() == false)
	{
		_animations[_currentAnimation]->stop();
		_currentAnimation = _defaultAnimation;
		_animations[_currentAnimation]->play();
	}
}

void AnimationController::render(sf::RenderWindow& window)
{
	_animations[_currentAnimation]->render(window);
}

void AnimationController::setPosition(const sf::Vector2f position)
{
	this->position = position;

	for (auto& animation : _animations)
	{
		animation.second->setPosition(position);
	}
}

void AnimationController::startAnimationChange()
{
	if (_animations[_currentAnimation]->isAtLastFrame() == false)
	{
		_animations[_currentAnimation]->stop();

		_currentAnimation = _bufferedAnimation;

		_animations[_currentAnimation]->play();

		_bufferedAnimation = "";
	}
}
