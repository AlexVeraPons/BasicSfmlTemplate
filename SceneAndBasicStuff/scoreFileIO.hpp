#pragma once
#include <vector>
#include "scoreEntry.hpp"
#include <fstream>

class ScoreFileIO
{
private:
	std::vector<ScoreEntry*> _scoreEntries; //update when i get the next lesson to smart pointers
	std::string _scoreFilePath;

public:
	ScoreFileIO();
	ScoreFileIO(std::string scoreFilePath);
	~ScoreFileIO();

public:
	void reloadScores();
	void addScore(std::string name, unsigned int score);
	void addScore(ScoreEntry newScore);
	std::vector<ScoreEntry*> getScoreList() const;
	std::vector<ScoreEntry*> getTopScores(int amount) const;
	ScoreEntry* getTopScore() const;
	void clearScores();
	void saveScores();
private:
	void orderScores();
	void clearScoreList();
};


