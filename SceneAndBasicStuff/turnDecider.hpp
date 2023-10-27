#pragma once
#include "fightCharacter.hpp"

class TurnDecider
{
private:
	FightCharacter* _character1;
	FightCharacter* _character2;

	FightCharacter* _activeCharacter;
public:
	TurnDecider(FightCharacter& _character1, FightCharacter& _character2);
	~TurnDecider();

public:
	void setFighters(FightCharacter& _character1, FightCharacter& _character2);
	void nextTurn();
	FightCharacter& getTurnCharacter();
};

