#include "scoreboard.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

Scoreboard::Scoreboard(std::string identifier, sf::Vector2f position, std::string scoreFilePath, sf::Font& font) : GameObject(identifier, position), _font(font)
{
	_scoreFileIO = new ScoreFileIO(scoreFilePath);
	_scoreEntries = _scoreFileIO->getTopScores(_scoreAmount);
}

Scoreboard::~Scoreboard()
{
	delete _scoreFileIO;
}

void Scoreboard::start()
{
	_scoreFileIO->reloadScores();
	_scoreEntries = _scoreFileIO->getTopScores(_scoreAmount);
}

void Scoreboard::update()
{
}

void Scoreboard::render(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < _scoreEntries.size(); i++)
	{
		sf::Text text;
		text.setFont(_font);
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::Black);
		text.setPosition(sf::Vector2f(position.x, position.y + i * _scoreboardTextOffset));
		text.setString(_scoreEntries[i]->name + " " + std::to_string(_scoreEntries[i]->score));
		window.draw(text);
	}
}

void Scoreboard::refresh()
{
	_scoreFileIO->reloadScores();
	_scoreEntries = _scoreFileIO->getTopScores(_scoreAmount);
}

void Scoreboard::clearScores()
{
	_scoreFileIO->clearScores();
	_scoreEntries = _scoreFileIO->getTopScores(_scoreAmount);
}
