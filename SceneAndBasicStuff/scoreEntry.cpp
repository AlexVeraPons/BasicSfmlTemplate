#include "scoreEntry.hpp"

ScoreEntry::ScoreEntry(std::string name, unsigned int score)
{
	this->name = name;
	this->score= score;
}

std::ostream& operator<<(std::ostream& os, const ScoreEntry& scoreEntry)
{
	os << scoreEntry.name << " " << scoreEntry.score;
	return os;
}
