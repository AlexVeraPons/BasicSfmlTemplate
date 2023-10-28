#include "fightController.hpp"
#include "fightCharacter.hpp"
#include "turnDecider.hpp"


FightController::FightController() : turnDecider(fighters[0], fighters[1]), GameObject() { }

FightController::~FightController() { }

void FightController::start()
{
	nextTurn();
}

void FightController::setupFight(FightCharacter fighterA, FightCharacter fighterB)
{

	turnDecider.setFighters(fighters[0], fighters[1]);
}

void FightController::executeMove()
{
	//MoveExecuter(move, target);

	//if (target.isDead() && target is npc)
	//{
	//	Win();
	//}
	//else if (target.isDead() && target is player)
	//{
	//	Lose();
	//}

	nextTurn();
}


void FightController::nextTurn()
{
	turnDecider.nextTurn();
	activeFighter = &turnDecider.getTurnCharacter();
	printf("Next turn: %s\n", activeFighter->getName().c_str());
}

void FightController::win()
{
}

void FightController::lose()
{
}
