#include "fightController.hpp"
#include "fightCharacter.hpp"
#include "turnDecider.hpp"
#include "move.hpp"



#include "fightController.hpp"
#include <memory> // for std::unique_ptr

FightController::FightController(FightCharacter player, FightCharacter enemy) : _player(std::make_unique<FightCharacter>(player)), _enemy(std::make_unique<FightCharacter>(enemy)),
turnDecider(*_player, *_enemy) { }


FightController::~FightController() { }

void FightController::start()
{
	nextTurn();
}

void FightController::executeMove(Move* move)
{
	move->execute();
	nextTurn();
}

void FightController::nextTurn()
{
	turnDecider.nextTurn();
	activeFighter = &turnDecider.getTurnCharacter();
	printf("Next turn: %s\n", activeFighter->getName().c_str());
}

void FightController::win()
{
}

void FightController::lose()
{
}
