#include "lightAttack.hpp"

LightAttack::LightAttack() : AttackMove() { }

LightAttack::LightAttack(FightCharacter& dealer, FightCharacter& target) : AttackMove(dealer,target) { }

const std::string LightAttack::getName()
{
	return "Light Attack";
}

const float LightAttack::getEffectValue()
{
	return _dealer->getAttack() * 0.5 + 5;
}

const float LightAttack::getCost()
{
	return 13;
}
