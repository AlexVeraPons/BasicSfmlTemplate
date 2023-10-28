#include "attackMove.hpp"
#include <stdio.h>

AttackMove::AttackMove() { }

AttackMove::~AttackMove() { }

const float AttackMove::getMoveCost()
{
	return _moveCost;
}

void AttackMove::operator()()
{
	printf("AttackMove");
}
