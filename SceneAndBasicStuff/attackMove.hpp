#pragma once
#include <string>

#include "move.hpp"
#include "fightCharacter.hpp"


class AttackMove : public Move
{
private:
	FightCharacter* _dealer;
	FightCharacter* _target;

	float _moveCost = 20;
	float _effectValue = 10;
public:
	AttackMove();
	AttackMove(FightCharacter& dealer, FightCharacter& target);
	~AttackMove();

	void operator()() override;

	void execute() override;

	const std::string getName() override;
	const float getEffectValue() override;
	const float getCost() override;
	const Target getTarget() override;

};