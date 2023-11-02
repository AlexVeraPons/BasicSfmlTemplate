#pragma once
#include <vector>
#include <string>

#include "gameObject.hpp"
#include "fightCharacter.hpp"
#include "turnDecider.hpp"
#include "move.hpp"
#include "subject.hpp"

class FightController : public GameObject, public Subject<std::string>
{
private:
	std::unique_ptr <FightCharacter> _player;
	std::unique_ptr <FightCharacter> _enemy;

	FightCharacter* activeFighter = nullptr;
	TurnDecider turnDecider;
public:
	FightController(std::string, FightCharacter player, FightCharacter enemy);
	~FightController();

	FightController(const FightController& other);
public:
	FightCharacter& getActiveFighter() const;
	FightCharacter& getEnemy() const;
	FightCharacter& getPlayer() const;
	
	void setPlayer(FightCharacter player);
	void setEnemy(FightCharacter enemy);
	
	void start();
	void executeMove(Move* move);
	void nextTurn();

private:
	void win();
	void lose();
};
