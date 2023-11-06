#include "BigHeal.hpp"

BigHeal::BigHeal() : _dealer(nullptr) { }

BigHeal::BigHeal(FightCharacter& dealer)
{
		_dealer = &dealer;
}

BigHeal::~BigHeal()
{
}

void BigHeal::operator()()
{
	execute();
}

void BigHeal::execute()
{
	_dealer->heal(getEffectValue());

	_dealer->setQueuePosition(getCost());
}

const std::string BigHeal::getName()
{
	return "BigHeal";
}

const float BigHeal::getEffectValue()
{
	return _effectValue;
}

const float BigHeal::getCost()
{
	return _moveCost;
}

const Target BigHeal::getTarget()
{
	return Target::Self;
}

