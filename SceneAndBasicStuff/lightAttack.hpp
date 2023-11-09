#pragma once
#include <string>

#include "attackMove.hpp"

class LightAttack : public AttackMove
{
public:
	LightAttack();
	LightAttack(FightCharacter& dealer, FightCharacter& target);

	const std::string getName() override;
	const float getEffectValue() override;
	const float getCost() override;
};

