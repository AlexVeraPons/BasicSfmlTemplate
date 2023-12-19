#include <iostream>
#include <string>

#include "enemyAI.hpp"
#include "attackMove.hpp"
#include "move.hpp"
#include "fightController.hpp"
#include "doNothingMove.hpp"
#include "lightAttack.hpp"
#include "bigHeal.hpp"
EnemyAI::EnemyAI() : _controlledFighter(), _target()
{
	_moves[0] = new AttackMove(*_controlledFighter, *_target);
	_moves[1] = new BigHeal(*_controlledFighter);
	_moves[2] = new DoNothingMove(*_controlledFighter);
	_moves[3] = new LightAttack(*_controlledFighter, *_target);
}
EnemyAI::EnemyAI(std::shared_ptr<FightCharacter> fighter, std::shared_ptr<FightCharacter> target) : _controlledFighter(fighter), _target(target)
{
	_moves[0] = new AttackMove(*_controlledFighter, *_target);
	_moves[1] = new BigHeal(*_controlledFighter);
	_moves[2] = new DoNothingMove(*_controlledFighter);
	_moves[3] = new LightAttack(*_controlledFighter, *_target);
}

EnemyAI::~EnemyAI()
{
	for (int i = 0; i < std::size(_moves); i++)
	{
		delete _moves[i];
	}
}

void EnemyAI::executeMove(FightController& fightController)
{
	fightController.executeMove(decideMove());
}

std::string EnemyAI::getFighterName() const
{
	return _controlledFighter->getName();
}

Move* EnemyAI::decideMove()
{
	return _moves[rand() % std::size(_moves)];
}


