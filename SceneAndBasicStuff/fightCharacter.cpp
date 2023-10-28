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

void FightCharacter::startTurn()
{
	printf("%s's turn!\n", _characterData.name.c_str());
	_isActive = true;
}

void FightCharacter::endTurn()
{
	_isActive = false;
}

void FightCharacter::receiveDamage(unsigned int damage)
{
	_characterData.stats.health -= damage;
}

void FightCharacter::heal(unsigned int health)
{
	_characterData.stats.health += health;
}

bool FightCharacter::isAlive()
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
