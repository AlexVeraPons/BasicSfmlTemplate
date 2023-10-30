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

ScoreFileIO::~ScoreFileIO() { }

void ScoreFileIO::reloadScores()
{
	clearScoreList();

	std::ifstream file("Savedata/score.txt"); //TODO: Make this go back to _scoreFilePath and check while the second time it gets called its empty
	std::string line;

	if (!file.is_open()) {
		std::cout << "Could not open file: " << _scoreFilePath << std::endl;
		return;
	}

	while (std::getline(file, line)) {

		std::istringstream iss(line);

		std::string name;
		int score;

		iss >> name >> score;

		_scoreEntries.push_back(new ScoreEntry(name, score));
	}

	file.close();

	orderScores();
}

//check if this works when i know how to use the new pointer stuff
void ScoreFileIO::addScore(std::string name, unsigned int score)
{
	_scoreEntries.push_back(new ScoreEntry(name, score));
	orderScores();
	saveScores();
}


void ScoreFileIO::addScore(ScoreEntry newScore)
{
	_scoreEntries.push_back(new ScoreEntry(newScore.name, newScore.score));
	orderScores();
	saveScores();
}

std::vector<ScoreEntry*> ScoreFileIO::getScoreList() const
{
	return _scoreEntries;
}

std::vector<ScoreEntry*> ScoreFileIO::getTopScores(int amount) const
{
	if (int(_scoreEntries.size()) < amount) {
		return _scoreEntries;
	}

	std::vector<ScoreEntry*> topScores;

	for (int i = 0; i < amount; i++)
	{
		printf("%d\n", i);
		topScores.push_back(_scoreEntries[i]);
	}

	return topScores;
}

ScoreEntry* ScoreFileIO::getTopScore() const
{
	return _scoreEntries[0];
}

void ScoreFileIO::clearScores()
{
	clearScoreList();
	saveScores();
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
		std::cout << "Saving score: " << *_scoreEntries[i] << std::endl;
		*_scoreFile << *_scoreEntries[i] << std::endl;
	}
}

void ScoreFileIO::clearScoreList() //TODO: Make sure this is needed for garbage collection
{
	_scoreEntries.clear();
}
