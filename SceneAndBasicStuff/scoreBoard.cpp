#include "scoreboard.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>

Scoreboard::Scoreboard(std::string identifier, sf::Vector2f position, sf::Font& font) : GameObject(identifier, position), _font(font), _scoreFileIO()
{
	refresh();
}

Scoreboard::~Scoreboard()
{
	for (unsigned int i = 0; i < _scoreEntityEntries.size(); i++)
	{
		delete _scoreEntityEntries[i];
	}
}

void Scoreboard::start()
{
	refresh();
}

void Scoreboard::render(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < _scoreEntityEntries.size(); i++)
	{
		sf::Text text;
		text.setFont(_font);
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::Black);
		text.setPosition(sf::Vector2f(position.x, position.y + i * _scoreboardTextOffset));
		text.setString(_scoreEntityEntries[i]->name + " " + std::to_string(_scoreEntityEntries[i]->score));
		window.draw(text);
	}
}

void Scoreboard::refresh()
{
	_scoreFileIO.reloadScores();
	_scoreEntityEntries = _scoreFileIO.getTopScores(_scoreAmount);
	fillRestWithPlaceholders();
}

void Scoreboard::clearScores()
{
	_scoreFileIO.clearScores();
	_scoreEntityEntries.clear();
	refresh();
}

void Scoreboard::fillRestWithPlaceholders()
{
	if (_scoreAmount <= _scoreEntityEntries.size()) return;

	unsigned int amountOfPlaceholders = _scoreAmount - _scoreEntityEntries.size();
	for (unsigned int i = 0; i < amountOfPlaceholders; i++)
	{
		_scoreEntityEntries.push_back(new ScoreEntry("N/A", 0));
	}
}
