#include "fightCharacter.hpp"

FightCharacter::FightCharacter(CharacterData characterData)
{
	_characterData = characterData;
	_queuePosition = 100 - _characterData.stats.speed;
	printf("%s's queue position is %f\n", _characterData.name.c_str(), _queuePosition);
}

FightCharacter::FightCharacter(const FightCharacter& other)
{
	_characterData = other._characterData;
	_queuePosition = other._queuePosition;
	_isActive = other._isActive;
}

bool FightCharacter::operator==(const FightCharacter& other)
{
	return _characterData == other._characterData;
}

FightCharacter::operator bool() const
{
	return isAlive();
}

FightCharacter::FightCharacter() : FightCharacter(CharacterData()) { }

FightCharacter::~FightCharacter() { }

int FightCharacter::getAttack() const
{
	return _characterData.stats.attack;
}

int FightCharacter::getSpeed() const
{
	return _characterData.stats.speed;
}

int FightCharacter::getHealth() const
{
	return _characterData.stats.health;
}

std::string FightCharacter::getName() const
{
	return _characterData.name;
}

bool FightCharacter::isActive() const
{
	return _isActive;
}

void FightCharacter::recieveDamage(float ammount)
{
	_characterData.stats.health -= ammount;
	notifyObservers(_characterData.name + " revieved " + std::to_string(ammount) + " damage!");
}

void FightCharacter::heal(float ammount)
{
	_characterData.stats.health += ammount;
	notifyObservers(_characterData.name + " healed " + std::to_string(ammount) + " health!");
}

void FightCharacter::startTurn()
{
	printf("%s's turn!\n", _characterData.name.c_str());
	_isActive = true;
}

void FightCharacter::endTurn()
{
	_isActive = false;
}

bool FightCharacter::isAlive() const
{
	return _characterData.stats.health >= 0;
}

void FightCharacter::setQueuePosition(float position)
{
	_queuePosition = position;
}

float FightCharacter::getQueuePosition() const
{
	return _queuePosition;
}

void FightCharacter::advanceQueuePosition(float amount)
{
	_queuePosition += amount;
}
