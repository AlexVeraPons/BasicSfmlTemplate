#pragma once
#include "ScoreFileIO.hpp"

class ScoreKeeper
{
private:
	unsigned int _currentScore;
	ScoreFileIO _scoreFileIO;
public:
	ScoreKeeper();
	ScoreKeeper(int const initialScore);
	~ScoreKeeper();

	unsigned int const getScore();
	void addScore(int const score);
	void setScore(int const score);
	void resetScore();
	void saveScore();
};

