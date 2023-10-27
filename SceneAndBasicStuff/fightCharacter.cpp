#include "fightCharacter.hpp"

FightCharacter::FightCharacter(CharacterData characterData)
{
	_characterData = characterData;
	_queuePosition = 100-_characterData.stats.speed;
}

FightCharacter::FightCharacter(CharacterData characterData)
{
}

FightCharacter::~FightCharacter()
{
}

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
	_queuePosition -= amount;
}
