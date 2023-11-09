#pragma once
#include <string>

#include "attackMove.hpp"

class HeavyAttack : public AttackMove
{
public:
	HeavyAttack();
	HeavyAttack(FightCharacter& dealer, FightCharacter& target);

	const std::string getName() override;
	const float getEffectValue() override;
	const float getCost() override;
};

