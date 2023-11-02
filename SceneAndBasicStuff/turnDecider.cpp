#include "turnDecider.hpp"

TurnDecider::TurnDecider(FightCharacter& _character1, FightCharacter& _character2)
{
	this->_character1 = &_character1;
	this->_character2 = &_character2;
	_activeCharacter  = &getTurnCharacter();
}

TurnDecider::TurnDecider(): _character1(nullptr), _character2(nullptr), _activeCharacter(nullptr) { }

TurnDecider::~TurnDecider() { }

TurnDecider::TurnDecider(const TurnDecider& other)
{
    _character1 = other._character1;
	_character2 = other._character2;
	_activeCharacter = other._activeCharacter;
}

void TurnDecider::setFighters(FightCharacter& _character1, FightCharacter& _character2)
{
	this->_character1 = &_character1;
	this->_character2 = &_character2;
}

void TurnDecider::nextTurn()
{
    // Determine the active character based on queue positions
    float position1 = _character1->getQueuePosition();
    float position2 = _character2->getQueuePosition();
    _activeCharacter = (position1 < position2) ? _character1 : _character2;

    // Update queue positions
    float distanceToZero = 0 - _activeCharacter->getQueuePosition();
    updateQueuePositions(distanceToZero);

    // Start the active character's turn
    _activeCharacter->startTurn();
}

FightCharacter& TurnDecider::getTurnCharacter()
{
	return *_activeCharacter;
}

void TurnDecider::updateQueuePositions(float distanceToZero) {
    _activeCharacter->setQueuePosition(0);
    if (_activeCharacter == _character1) {
        _character2->advanceQueuePosition(distanceToZero);
    }
    else {
        _character1->advanceQueuePosition(distanceToZero);
    }

    printf("Queue positions: %f, %f\n", _character1->getQueuePosition(), _character2->getQueuePosition());
}

