#include <string>
#include <memory> 
#include "fightController.hpp"
#include "fightCharacter.hpp"
#include "turnDecider.hpp"
#include "move.hpp"

FightController::FightController(std::string identifier, FightCharacter player, FightCharacter enemy)
	: _player(std::make_unique<FightCharacter>(player)),
	_enemy(std::make_unique<FightCharacter>(enemy)),
	turnDecider(*_player, *_enemy),
	GameObject(identifier),
	enemyAi(_enemy, _player) { }

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
	reset();
}

void FightController::update()
{
	if (aiMovePending && aiTimer.getElapsedTime() >= aiDelay) {
		aiMovePending = false; // Reset the flag
		enemyAi.executeMove(*this);
	}
}
void FightController::reset()
{
	_player->reset();
	_enemy->reset();
	nextTurn();
}
void FightController::executeMove(Move* move)
{
	notifyObservers(activeFighter->getName() + " used " + move->getName());

	(*move)();
	activeFighter->endTurn();

	if (!_player->isAlive())
	{
		printf("you lost");
		lose();
		return;
	}
	else if (!_enemy->isAlive())
	{
		printf("you won");
		win();
		return;
	}

	nextTurn();

}

void FightController::nextTurn()
{
	turnDecider.nextTurn();
	activeFighter = &turnDecider.getTurnCharacter();
	activeFighter->startTurn();

	printf("%s's turn\n", activeFighter->getName().c_str());

	if (enemyAi.getFighterName() == activeFighter->getName()) {
		aiMovePending = true;
		aiTimer.restart();
	}
}

void FightController::win()
{
	notifyObservers("YOU WON!");
}

void FightController::lose()
{
	notifyObservers("YOU WON!");
}
