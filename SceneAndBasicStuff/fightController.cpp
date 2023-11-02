#include <string>

#include "fightController.hpp"
#include "fightCharacter.hpp"
#include "turnDecider.hpp"
#include "move.hpp"



#include "fightController.hpp"
#include <memory> // for std::unique_ptr

FightController::FightController(std::string identifier, FightCharacter player, FightCharacter enemy) : _player(std::make_unique<FightCharacter>(player)), _enemy(std::make_unique<FightCharacter>(enemy)),
turnDecider(*_player, *_enemy), GameObject(identifier) { }

FightController::~FightController() { }

FightController::FightController(const FightController& other)
{
	_player = std::make_unique<FightCharacter>(*other._player);
	_enemy = std::make_unique<FightCharacter>(*other._enemy);
	turnDecider = other.turnDecider;
}

FightCharacter& FightController::getActiveFighter() const
{
	return *activeFighter;
}

FightCharacter& FightController::getEnemy() const
{
	return *_enemy;
}

FightCharacter& FightController::getPlayer() const
{
	return *_player;
}

void FightController::setPlayer(FightCharacter player)
{
	_player = std::make_unique<FightCharacter>(player);
}

void FightController::setEnemy(FightCharacter enemy)
{
	_enemy = std::make_unique<FightCharacter>(enemy);
}

void FightController::start()
{
	nextTurn();
}

void FightController::executeMove(Move* move)
{
	(*move)();
	delete move;

	activeFighter->endTurn();
	nextTurn();
}

void FightController::nextTurn()
{
	turnDecider.nextTurn();
	activeFighter = &turnDecider.getTurnCharacter();
	activeFighter->startTurn();
}

void FightController::win()
{
}

void FightController::lose()
{
}
