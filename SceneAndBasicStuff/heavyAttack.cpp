#include "heavyAttack.hpp"

HeavyAttack::HeavyAttack() : AttackMove() { }
HeavyAttack::HeavyAttack(FightCharacter& dealer, FightCharacter& target) :AttackMove(dealer, target) { }

const std::string HeavyAttack::getName()
{
	return "HeavyAttack";
}

const float HeavyAttack::getEffectValue()
{
	return _dealer.getAttack() * 1.5 + 10;
}

const float HeavyAttack::getCost()
{
	return 30;
}


