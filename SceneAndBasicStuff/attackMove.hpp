#pragma once
#include "move.hpp"

class AttackMove : public Move
{
private:
	float _moveCost = 20;
public:
	AttackMove();
	void operator()();
	~AttackMove();
	const float getMoveCost() override;
};