
#pragma once
#include "gameObject.hpp"
#include "scoreFileIO.hpp"

class Scoreboard : GameObject
{
private:
	int const _scoreAmount = 5;
	ScoreFileIO& _scoreFileIO;
public:
	Scoreboard(ScoreFileIO scoreFileIO); 
	~Scoreboard();

public:
	// Inherited via GameObject
	void start() override;
	void update() override;
	void render(sf::RenderWindow& window) override;
};

