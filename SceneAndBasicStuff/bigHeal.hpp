#pragma once
#include "move.hpp"
#include "fightCharacter.hpp"

class BigHeal : public Move
{
	private:
	FightCharacter* _dealer;

	float _moveCost = 30;
	float _effectValue = 30;
	public:
		BigHeal();
		BigHeal(FightCharacter& dealer);
		~BigHeal();

		void operator()() override;

		void execute() override;

		const std::string getName() override;
		const float getEffectValue() override;
		const float getCost() override;
		const Target getTarget() override;
};

