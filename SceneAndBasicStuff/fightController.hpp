#pragma once
#include <vector>
#include "gameObject.hpp"
#include "fightCharacter.hpp"

class FightController
{
private:
	FightCharacter fighters[2];
	FightCharacter* activeFighter;
public:
	FightController();
	~FightController();

public:
	void setupFight(FightCharacter& fighterA, FightCharacter& fighterB);
	void executeMove();
	void nextTurn();

private:
	void win();
	void lose();
};
