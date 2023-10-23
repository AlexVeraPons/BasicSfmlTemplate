#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>

#include "scoreFileIO.hpp"
#include "scoreEntry.hpp"

ScoreFileIO::ScoreFileIO(std::string scoreFilePath)
{
	_scoreFilePath = scoreFilePath;
	reloadScores();
}

ScoreFileIO::~ScoreFileIO()
{
}

void ScoreFileIO::reloadScores()
{
	clearScores();

	std::ifstream file(_scoreFilePath);

	std::string line;
	
	if (!file)
	{
		throw std::runtime_error("Something went wrong!");
	}

	while (std::getline(file, line)) {
		
		std::istringstream iss(line);

		std::string name;
		int score;  

		iss >> name >> score;

		_scoreEntries.push_back(new ScoreEntry(name, score));
	}

	orderScores();
}

void ScoreFileIO::addScore(ScoreEntry newScore)
{
	_scoreEntries.push_back(new ScoreEntry(newScore.Name, newScore.Score));
	orderScores();
	saveScores();
}

std::vector<ScoreEntry*> ScoreFileIO::getScoreList() const
{
	return std::vector<ScoreEntry*>();
}

std::vector<ScoreEntry*> ScoreFileIO::getTopScores(int amount) const
{
	if (int(_scoreEntries.size()) < amount) { return _scoreEntries; }

	std::vector<ScoreEntry*> topScores;

	for (int i = 0; i < amount; i++)
	{
		topScores.push_back(_scoreEntries[i]);
	}
}

ScoreEntry* ScoreFileIO::getTopScore() const
{
	return _scoreEntries[0];
}

void ScoreFileIO::orderScores()
{
	std::sort(_scoreEntries.begin(), _scoreEntries.end(),
		[](const ScoreEntry* a, const ScoreEntry* b) -> bool {
			return *a > *b;
		});
}


void ScoreFileIO::saveScores()
{
	orderScores();

	std::ofstream* _scoreFile = new std::ofstream(_scoreFilePath);

	for (int i = 0; i < _scoreEntries.size(); i++)
	{
		*_scoreFile << _scoreEntries[i]->Name << " " << _scoreEntries[i]->Score << std::endl;
	}
}

void ScoreFileIO::clearScores() //TODO: Make sure this is needed for garbage collection
{
	for (int i = 0; i < _scoreEntries.size(); i++)
	{
		delete _scoreEntries[i];
	}

	_scoreEntries.clear();
}
