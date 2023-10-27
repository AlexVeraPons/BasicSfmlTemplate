#pragma once
#include <string>
#include "characterData.hpp"


class FightCharacter
{
private:
	CharacterData _characterData;
	float _queuePosition = 0.0f;
public:
	FightCharacter(CharacterData characterData);
	~FightCharacter();
public:
	int getAttack() const;
	int getSpeed() const;
	int getHealth() const;

	void receiveDamage(unsigned int damage);
	void heal(unsigned int health);
	bool isAlive();
	void setQueuePosition(float position);
	float getQueuePosition() const;
	void advanceQueuePosition(float amount);
};
