#include "doNothingMove.hpp"


DoNothingMove::DoNothingMove(FightCharacter& dealer) : _dealer(dealer) { }

DoNothingMove::~DoNothingMove() { }

void DoNothingMove::execute()
{
	_dealer.advanceQueuePosition(getCost());
}

void DoNothingMove::operator()()
{
	execute();
}

const std::string DoNothingMove::getName()
{
	return "Do Nothing";
}

const float DoNothingMove::getEffectValue()
{
	return 0.0f;
}

const float DoNothingMove::getCost()
{
	return 20;
}

const Target DoNothingMove::getTarget()
{
	return Target::Self;
}

