#pragma once
#include <string>
#include "characterData.hpp"


class FightCharacter
{
private:
	CharacterData _characterData;
	float _queuePosition = 0.0f;
	bool _isActive = false;
public:
	FightCharacter();
	FightCharacter(CharacterData characterData);
	FightCharacter(const FightCharacter& other);
	~FightCharacter();
public:
	int getAttack() const;
	int getSpeed() const;
	int getHealth() const;
	std::string getName() const;
	bool isActive() const;

	void startTurn();
	void endTurn();
	void receiveDamage(unsigned int damage);
	void heal(unsigned int health);
	bool isAlive();
	void setQueuePosition(float position);
	float getQueuePosition() const;
	void advanceQueuePosition(float amount);
};
