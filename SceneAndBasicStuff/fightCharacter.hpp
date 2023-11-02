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
	
	bool operator==(const FightCharacter& other);

	/*
	Returns true if the character is alive,
	else returns false.
	*/
	explicit operator bool() const;

	~FightCharacter();
public:
	int getAttack() const;
	int getSpeed() const;
	int getHealth() const;
	std::string getName() const;
	bool isActive() const;
	bool isAlive() const;

	void dealDamage(float ammount);
	void heal(float ammount);

	void startTurn();
	void endTurn();
	void setQueuePosition(float position);
	float getQueuePosition() const;
	void advanceQueuePosition(float amount);

private:

};
