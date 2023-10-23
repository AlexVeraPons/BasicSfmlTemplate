#pragma once
#include <string>

struct ScoreEntry
{
	ScoreEntry(std::string name, unsigned int score);

	bool operator<(const ScoreEntry& other) const
	{
		return Score < other.Score;
	}

	bool operator>(const ScoreEntry& other) const
	{
		return Score > other.Score;
	}

	std::string Name;
	unsigned int Score;
};

