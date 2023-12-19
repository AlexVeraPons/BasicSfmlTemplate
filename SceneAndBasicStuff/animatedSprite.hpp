#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class AnimatedSprite
{
private:
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Vector2i _frameSize;
	sf::Clock _clock;
	sf::IntRect _currentFrameRect;

	float _timeBetweenFrames;

	unsigned int _currentFrame;
	unsigned int _numberOfFrames;

	bool _loop = false;
	bool _isPlaying = false;

	std::function<void()> _onAnimationFinished;
public:
	AnimatedSprite();
	AnimatedSprite(const sf::Texture& texture, const sf::Vector2i& frameSize, const float& timeBetweenFrames);
	AnimatedSprite(const sf::Texture& texture, unsigned int numberOfRows, const float& timeBetweenFrames);
	AnimatedSprite(const AnimatedSprite& other);
	~AnimatedSprite();

	explicit operator bool() const;

	bool isPlaying();
	bool isAtLastFrame();

	void load(const sf::Texture& texture, const sf::Vector2i& frameSize, const float& timeBetweenFrames);
	void load (const sf::Texture& texture, unsigned int numberOfRows, const float& timeBetweenFrames);
	void setTexture(const sf::Texture& texture);
	void setFrameSize(const sf::Vector2i& frameSize);
	void setTimeBetweenFrames(const float& timeBetweenFrames);
	void setPosition(const sf::Vector2f& position);
	void setLoop(const bool& loop);
	void setColor(const sf::Color& color);
	void flip(const bool& flip);
	void onAnimationFinished(std::function<void()> callback);
	
	void play();
	void stop();

	void update();
	void render(sf::RenderWindow& window);
private:
	void updateAnimation();
	void nextFrame();
	void setFrame(const unsigned int& frameNumber);
	sf::IntRect getFrameRect(const unsigned int& frameNumber);
};

