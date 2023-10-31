#pragma once
#include "move.hpp"
#include "fightCharacter.hpp"

class MoveExecutor
{
public:
	MoveExecutor();
	~MoveExecutor();

	void operator()(FightCharacter& dealer, FightCharacter& receiver, Move move);

public:
	void execute(Move& move, FightCharacter& dealer, FightCharacter& reciever);

private:
};

