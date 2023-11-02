#pragma once
#include "fightCharacter.hpp"

class TurnDecider
{
private:
	FightCharacter* _character1;
	FightCharacter* _character2;

	FightCharacter* _activeCharacter;
public:
	TurnDecider();
	TurnDecider(FightCharacter& _character1, FightCharacter& _character2);
	~TurnDecider();

	TurnDecider(const TurnDecider& other);

public:
	void setFighters(FightCharacter& _character1, FightCharacter& _character2);
	void nextTurn();
	FightCharacter& getTurnCharacter();

private:
	void updateQueuePositions(float distance);
};

