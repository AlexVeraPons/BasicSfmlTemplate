#pragma once
#include <string>

struct ScoreEntry
{
	ScoreEntry(std::string name, unsigned int score);

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

