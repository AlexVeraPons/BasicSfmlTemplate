#include "scoreKeeper.hpp"

ScoreKeeper::ScoreKeeper() : _currentScore(0), _scoreFileIO() {}
ScoreKeeper::ScoreKeeper(int const initialScore) : _currentScore(initialScore), _scoreFileIO() {}
ScoreKeeper::~ScoreKeeper() {}

unsigned int const ScoreKeeper::getScore()
{
	return _currentScore;
}

void ScoreKeeper::addScore(int const score)
{
	_currentScore += score;
}

void ScoreKeeper::setScore(int const score)
{
	_currentScore = score;
}

void ScoreKeeper::resetScore()
{
	_currentScore = 0;
}

void ScoreKeeper::saveScore()
{
	_scoreFileIO.addScore("Player" , _currentScore);
}
