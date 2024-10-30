#pragma once

#include "move.hpp"
#include "fightCharacter.hpp"

class LifeStealMove : public Move
{
protected:
	FightCharacter* _dealer;
	FightCharacter* _target;

	float _moveCost = 20;
	float _effectValue = 10;
public:
	LifeStealMove();
	LifeStealMove(FightCharacter& dealer, FightCharacter& target);
	~LifeStealMove();

	void operator()() override;
	void execute() override;

	const std::string getName() override;
	const float getEffectValue() override;
	const float getCost() override;
	const Target getTarget() override;

};