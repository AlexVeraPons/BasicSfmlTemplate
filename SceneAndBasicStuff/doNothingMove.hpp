#pragma once
#include "move.hpp"
#include "fightCharacter.hpp"

class DoNothingMove :public Move
{
protected:
	FightCharacter& _dealer;
public:
	DoNothingMove(FightCharacter& dealer);
	~DoNothingMove();

	void operator()();

	void execute() override;

	const std::string getName() override;
	const float getEffectValue() override;
	const float getCost() override;
	const Target getTarget() override;
};