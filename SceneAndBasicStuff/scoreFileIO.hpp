#pragma once
#include <vector>
#include "scoreEntry.hpp"
#include <fstream>

class ScoreFileIO
{
private:
	std::vector<ScoreEntry*> _scoreEntries;
	std::string _scoreFilePath;

public:
	ScoreFileIO(std::string scoreFilePath);
	~ScoreFileIO();

public:
	void reloadScores();
	void addScore(ScoreEntry newScore);
	std::vector<ScoreEntry*> getScoreList() const;
	std::vector<ScoreEntry*> getTopScores(int amount) const;
	ScoreEntry* getTopScore() const;
private:
	void orderScores();
	void saveScores();
	void clearScores();
};


