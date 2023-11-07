#pragma once
#include <string>
#include "characterData.hpp"
#include "subject.hpp"
#include "queueManager.hpp"

class FightCharacter : public Subject<std::string>, public Subject<float>
{
private:
	QueueManager _queueManager;
	CharacterData _characterData;
	CharacterData _originalCharacterData;
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
	int getMaxHealth() const;
	std::string getName() const;
	bool isActive() const;
	bool isAlive() const;

	void setCharacterData(CharacterData characterData);

	void reset();
	void recieveDamage(float amount);
	void heal(float amount);

	void startTurn();
	void endTurn();
	void setQueuePosition(float position);
	float getQueuePosition() const;
	void advanceQueuePosition(float amount);
	void addObserverToQueueManager(Observer<float>& observer);

private:

	void updateHealth(float amount, const std::string message);

};
