#include "animatedSprite.hpp"
#include <functional>

AnimatedSprite::AnimatedSprite(const sf::Texture& texture, const sf::Vector2i& frameSize, const float& timeBetweenFrames)
{
	load(texture, frameSize, timeBetweenFrames);
}

AnimatedSprite::AnimatedSprite(const sf::Texture& texture, unsigned int numberOfRows, const float& timeBetweenFrames)
{
	load(texture, numberOfRows, timeBetweenFrames);
}

AnimatedSprite::AnimatedSprite()
{
	_texture = sf::Texture();
	_frameSize = sf::Vector2i();
	_timeBetweenFrames = 0;
	_numberOfFrames = 0;
	_currentFrame = 0;
	_currentFrameRect = sf::IntRect();
	_loop = false;
	_isPlaying = false;
	_sprite = sf::Sprite();
}

AnimatedSprite::AnimatedSprite(const AnimatedSprite& other)
{
	this->_texture = other._texture;
	this->_frameSize = other._frameSize;
	this->_timeBetweenFrames = other._timeBetweenFrames;
	this->_numberOfFrames = other._numberOfFrames;
	this->_currentFrame = other._currentFrame;
	this->_currentFrameRect = other._currentFrameRect;
	this->_loop = other._loop;
	this->_isPlaying = other._isPlaying;
	this->_sprite = other._sprite;
	_sprite.setOrigin(_frameSize.x / 2, _frameSize.y / 2);
	_sprite.setTexture(_texture);
	_onAnimationFinished = other._onAnimationFinished;
}

AnimatedSprite::~AnimatedSprite() { }

AnimatedSprite::operator bool() const
{
	printf("Current frame: %d\n", _currentFrame);
	printf("Number of frames: %d\n", _numberOfFrames);
	printf("Is at last frame: %d\n", _currentFrame >= _numberOfFrames - 1);
	return _currentFrame >= _numberOfFrames - 1;
}

bool AnimatedSprite::isPlaying()
{
	return _isPlaying;
}


bool AnimatedSprite::isAtLastFrame()
{
	return _currentFrame >= _numberOfFrames - 1;
}

void AnimatedSprite::update()
{
	if (_isPlaying)
	{
		updateAnimation();
	}
}

void AnimatedSprite::render(sf::RenderWindow& window)
{
	window.draw(_sprite);
}

void AnimatedSprite::setColor(const sf::Color& color)
{
	_sprite.setColor(color);
}

void AnimatedSprite::flip(const bool& flip)
{
	if (flip)
	{
		_sprite.setScale(-1, 1);
	}
	else
	{
		_sprite.setScale(1, 1);
	}
}

void AnimatedSprite::nextFrame()
{
	_currentFrame++;
	_currentFrameRect = getFrameRect(_currentFrame);
}

sf::IntRect AnimatedSprite::getFrameRect(const unsigned int& frameNumber)
{
	return sf::IntRect(frameNumber * _frameSize.x, 0, _frameSize.x, _frameSize.y);
}

void AnimatedSprite::setFrame(const unsigned int& frameNumber)
{
	_currentFrame = frameNumber;
	_currentFrameRect = getFrameRect(_currentFrame);
}

void AnimatedSprite::updateAnimation()
{
	if (_clock.getElapsedTime().asSeconds() >= _timeBetweenFrames)
	{
		nextFrame();

		if (_currentFrame >= _numberOfFrames - 1)
		{
			if (_loop)
			{
				_currentFrame = 0;

				if (_onAnimationFinished != nullptr)
				{
					_onAnimationFinished();
				}
			}
			else
			{
				stop();
				if (_onAnimationFinished != nullptr)
				{
					_onAnimationFinished();
				}
			}
		}

		_sprite.setTextureRect(_currentFrameRect);
		_clock.restart();
	}
}

void AnimatedSprite::onAnimationFinished(std::function<void()> callback)
{
	_onAnimationFinished = callback;
}

void AnimatedSprite::load(const sf::Texture& texture, const sf::Vector2i& frameSize, const float& timeBetweenFrames)
{
	_texture = texture;
	_frameSize = frameSize;
	_timeBetweenFrames = timeBetweenFrames;
	_numberOfFrames = _texture.getSize().x / _frameSize.x;
	_sprite.setOrigin(_frameSize.x / 2, _frameSize.y / 2);
	_sprite.setTexture(_texture);
	_currentFrame = 0;
	_currentFrameRect = getFrameRect(_currentFrame);
	_sprite.setTextureRect(_currentFrameRect);
}

void AnimatedSprite::load(const sf::Texture& texture, unsigned int numberOfRows, const float& timeBetweenFrames)
{
	_texture = texture;
	_frameSize = sf::Vector2i(_texture.getSize().x / numberOfRows, _texture.getSize().y);
	_timeBetweenFrames = timeBetweenFrames;
	_numberOfFrames = numberOfRows;
	_sprite.setOrigin(_frameSize.x / 2, _frameSize.y / 2);
	_currentFrame = 0;
	_currentFrameRect = getFrameRect(_currentFrame);
	_sprite.setTexture(_texture);
	_sprite.setTextureRect(_currentFrameRect);
	_sprite.setOrigin(_frameSize.x / 2, _frameSize.y / 2);
}


void AnimatedSprite::setTexture(const sf::Texture& texture)
{
	_texture = texture;
}

void AnimatedSprite::setFrameSize(const sf::Vector2i& frameSize)
{
	_frameSize = frameSize;
}

void AnimatedSprite::setTimeBetweenFrames(const float& timeBetweenFrames)
{
	_timeBetweenFrames = timeBetweenFrames;
}

void AnimatedSprite::setPosition(const sf::Vector2f& position)
{
	_sprite.setPosition(position);
}

void AnimatedSprite::setLoop(const bool& loop)
{
	_loop = loop;
}

void AnimatedSprite::play()
{
	_isPlaying = true;
	_clock.restart();
}

void AnimatedSprite::stop()
{
	_isPlaying = false;
	_currentFrame = 0;
	_currentFrameRect = getFrameRect(_currentFrame);
	_sprite.setTextureRect(_currentFrameRect);
}



