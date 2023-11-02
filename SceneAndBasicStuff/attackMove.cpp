#include <stdio.h>

#include "attackMove.hpp"

AttackMove::AttackMove(FightCharacter& dealer, FightCharacter& target) : _dealer(dealer), _target(target) { }
AttackMove::~AttackMove() { }

void AttackMove::operator()()
{
	execute();
}

const std::string AttackMove::getName()
{
	return "AttackMove";
}

const float AttackMove::getEffectValue()
{
	return _effectValue;
}

const float AttackMove::getCost()
{
	return _moveCost;
}

const Target AttackMove::getTarget()
{
	return Target::Enemy;
}

void AttackMove::execute()
{
	float totalDamage = _dealer.getAttack() + getEffectValue();
	_target.recieveDamage(totalDamage);

	_dealer.setQueuePosition(_dealer.getQueuePosition() + getCost());
}