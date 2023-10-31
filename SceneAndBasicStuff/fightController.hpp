#pragma once
#include <vector>
#include "gameObject.hpp"
#include "fightCharacter.hpp"
#include "turnDecider.hpp"
#include "move.hpp"

class FightController : public GameObject
{
private:
	std::unique_ptr <FightCharacter> _player;
	std::unique_ptr <FightCharacter> _enemy;

	FightCharacter* activeFighter = nullptr;
	TurnDecider turnDecider;
public:
	FightController(FightCharacter player, FightCharacter enemy);
	~FightController();

public:
	void start();
	void executeMove(Move* move);
	void nextTurn();

private:
	void win();
	void lose();
};
