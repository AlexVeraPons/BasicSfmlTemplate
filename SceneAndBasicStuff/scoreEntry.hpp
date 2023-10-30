#pragma once
#include <string>
#include <iostream>

struct ScoreEntry
{
	ScoreEntry(std::string name, unsigned int score);
	
	friend std::ostream& operator<<(std::ostream& os, const ScoreEntry& scoreEntry);

	bool operator<(const ScoreEntry& other) const
	{
		return score < other.score;
	}

	bool operator>(const ScoreEntry& other) const
	{
		return score > other.score;
	}

	std::string name;
	unsigned int score;
};


