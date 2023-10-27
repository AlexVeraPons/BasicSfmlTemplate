#include "fightController.hpp"
#include "fightCharacter.hpp"


FightController::FightController(): activeFighter(nullptr)
{
}

FightController::~FightController()
{
}


void FightController::setupFight(FightCharacter& fighterA, FightCharacter& fighterB)
{
	/*
		* fighters[0] = fighterA;
			* fighters[1] = fighterB;
				* 
					* turnDecider.setFighters(fighters[0],fighters[1]);
						* 
							* nextTurn();
								*/
}

void FightController::executeMove()
{
	/*
	* has a reference to the move done
	* MoveExecuter(move,target);
	*
	* if(target.isDead() && target is npc)
	* {
	*	Win();
	* }
	* else if(target.isDead() && target is player)
	* {
	*	Lose();
	* }
	* 
	* nextTurn();
	*/
}


void FightController::nextTurn()
{
	/*
	* turnDecider.nextTurn();
	* activeFighter= turnDecider.getTurnCharacter();
	* activeFighter->turnStart();
	*/
}

void FightController::win()
{
}

void FightController::lose()
{
}
