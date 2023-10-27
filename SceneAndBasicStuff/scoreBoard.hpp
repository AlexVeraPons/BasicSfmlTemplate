
#pragma once
#include "gameObject.hpp"
#include "scoreFileIO.hpp"

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

class Scoreboard : public GameObject
{
private:
	unsigned int const _scoreAmount = 5;
	float const _scoreboardTextOffset = 50;
	sf::Font& _font;
	ScoreFileIO* _scoreFileIO; //update when i get the next lesson on smart pointers
	std::vector<ScoreEntry*> _scoreEntries;
public:
	Scoreboard(std::string identifier, sf::Vector2f position, std::string scoreFilePath,sf::Font& font); 
	~Scoreboard();

public:
	// Inherited via GameObject
	void start() override;
	void update() override;
	void render(sf::RenderWindow& window) override;
	void refresh();
	void clearScores();
};

