#include "turnDecider.hpp"

TurnDecider::TurnDecider(FightCharacter& _character1, FightCharacter& _character2)
{
	this->_character1 = &_character1;
	this->_character2 = &_character2;
}

TurnDecider::~TurnDecider() { }

void TurnDecider::setFighters(FightCharacter& _character1, FightCharacter& _character2)
{
	this->_character1 = &_character1;
	this->_character2 = &_character2;
}

void TurnDecider::nextTurn()
{
	// get which character is closer to 0 on the queue and set it as the active character, 
	float position1 = _character1->getQueuePosition();
	float position2 = _character2->getQueuePosition();

	if (position1 < position2)
	{
		_activeCharacter = _character1;
		float distanceToZero = 0 - position1;
		_activeCharacter->setQueuePosition(0);
		_character2->advanceQueuePosition(distanceToZero);
	}
	else
	{
		_activeCharacter = _character2;
		float distanceToZero = 0 - position2;
		_activeCharacter->setQueuePosition(0);
		_character1->advanceQueuePosition(distanceToZero);
	}
}

FightCharacter& TurnDecider::getTurnCharacter()
{
	return *_activeCharacter;
}
