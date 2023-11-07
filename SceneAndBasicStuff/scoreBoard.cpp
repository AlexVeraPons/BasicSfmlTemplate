#include "scoreboard.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>

Scoreboard::Scoreboard(std::string identifier, sf::Vector2f position, std::string scoreFilePath, sf::Font& font) : GameObject(identifier, position), _font(font), _scoreFileIO(scoreFilePath)
{
	refresh();
}

Scoreboard::~Scoreboard()
{
	for (unsigned int i = 0; i < _scoreEntries.size(); i++)
	{
		delete _scoreEntries[i];
	}
}

void Scoreboard::start()
{
	refresh();
}

void Scoreboard::update()
{
}

void Scoreboard::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{
	//if i press a add a score
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		printf("Adding score\n");
		_scoreFileIO.addScore("Test", 100);
		refresh();
	}
}

void Scoreboard::onDisable()
{
	_scoreFileIO.saveScores();
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
	_scoreFileIO.reloadScores();
	_scoreEntries = _scoreFileIO.getTopScores(_scoreAmount);
	fillRestWithPlaceholders();
}

void Scoreboard::clearScores()
{
	_scoreFileIO.clearScores();
	_scoreEntries.clear();
	refresh();
}

void Scoreboard::fillRestWithPlaceholders()
{
	if (_scoreAmount <= _scoreEntries.size()) return;

	unsigned int amountOfPlaceholders = _scoreAmount - _scoreEntries.size();
	for (unsigned int i = 0; i < amountOfPlaceholders; i++)
	{
		_scoreEntries.push_back(new ScoreEntry("N/A", 0));
	}
}
