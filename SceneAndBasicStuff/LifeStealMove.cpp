#include "LifeStealMove.hpp"

LifeStealMove::LifeStealMove(){}

LifeStealMove::LifeStealMove(FightCharacter& dealer, FightCharacter& target) : _dealer(&dealer), _target(&target) {}

LifeStealMove::~LifeStealMove() {}

void LifeStealMove::operator()() {execute();}

void LifeStealMove::execute()
{
	float totalDamage = _dealer->getAttack() + getEffectValue();
	_target->recieveDamage(totalDamage);
	_dealer->heal(totalDamage / 4);

	_dealer->setQueuePosition(getCost());
}

const std::string LifeStealMove::getName()
{
	return "LifeStealMove";
}

const float LifeStealMove::getEffectValue()
{
	return this->_effectValue;
}

const float LifeStealMove::getCost()
{
	return this->_moveCost;
}

const Target LifeStealMove::getTarget()
{
	return Target::Enemy;
}
