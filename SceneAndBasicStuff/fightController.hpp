#pragma once
#include <vector>
#include "gameObject.hpp"
#include "fightCharacter.hpp"
#include "turnDecider.hpp"

class FightController : public GameObject
{
private:
	FightCharacter fighters[2];
	FightCharacter* activeFighter = nullptr;
	TurnDecider turnDecider;
public:
	FightController();
	~FightController();

public:
	void start();
	void setupFight(FightCharacter fighterA, FightCharacter fighterB);
	void executeMove();
	void nextTurn();

private:
	void win();
	void lose();
};
