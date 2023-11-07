#include "fightCharacter.hpp"
#include <string>

FightCharacter::FightCharacter() : FightCharacter(CharacterData()) { }

FightCharacter::FightCharacter(CharacterData characterData)
{
	_characterData = characterData;
	_originalCharacterData = characterData;
	_queueManager = QueueManager(100 - _characterData.stats.speed);
}

FightCharacter::FightCharacter(const FightCharacter& other)
{
	_characterData = other._characterData;
	_originalCharacterData = other._originalCharacterData;
	_queueManager = other._queueManager;
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

int FightCharacter::getMaxHealth() const
{
	return _characterData.stats.maxHealth;
}

std::string FightCharacter::getName() const
{
	return _characterData.name;
}

bool FightCharacter::isActive() const
{
	return _isActive;
}

void FightCharacter::updateHealth(float amount, const std::string message)
{
	_characterData.stats.health += amount;

	if (_characterData.stats.health < 0)
	{
		_characterData.stats.health = 0;
	}
	else if (_characterData.stats.health > _characterData.stats.maxHealth)
	{
		_characterData.stats.health = _characterData.stats.maxHealth;
	}

	Subject<float>::notifyObservers(_characterData.stats.health);
	Subject<std::string>::notifyObservers(_characterData.name + message);
}

void FightCharacter::reset()
{
	_characterData = _originalCharacterData;
	_queueManager.setQueuePosition(100 - _characterData.stats.speed);
	_isActive = false;
	Subject<float>::notifyObservers(_characterData.stats.health);
}

void FightCharacter::recieveDamage(float amount)
{
	updateHealth(-amount, " took " + std::to_string(static_cast<int>(amount)) + " damage");
}

void FightCharacter::heal(float amount)
{
	updateHealth(amount, " healed " + std::to_string(static_cast<int>(amount)) + " health");
}

void FightCharacter::startTurn()
{
	_isActive = true;
}

void FightCharacter::endTurn()
{
	_isActive = false;
}

bool FightCharacter::isAlive() const
{
	return _characterData.stats.health > 0;
}

void FightCharacter::setCharacterData(CharacterData characterData)
{
	_characterData = characterData;
	_originalCharacterData = characterData;
	_queueManager.setQueuePosition(100 - _characterData.stats.speed);
	Subject<float>::notifyObservers(_characterData.stats.health);
}

void FightCharacter::setQueuePosition(float position)
{
	_queueManager.setQueuePosition(position);
}

float FightCharacter::getQueuePosition() const
{
	return _queueManager.getQueuePosition();
}

void FightCharacter::advanceQueuePosition(float amount)
{
	_queueManager.advanceQueuePosition(amount);
}

void FightCharacter::addObserverToQueueManager(Observer<float>& observer)
{
	_queueManager.addObserver(observer);
}
