#include <string>
#include <memory> 
#include "fightController.hpp"
#include "fightCharacter.hpp"
#include "turnDecider.hpp"
#include "move.hpp"

FightController::FightController(std::string identifier, FightCharacter player)
	: _player(std::make_unique<FightCharacter>(player)),
	_enemy(std::make_unique<FightCharacter>(_characterFactory(1))),
	_turnDecider(*_player, *_enemy),
	GameObject(identifier),
	_enemyAi(_enemy, _player) { }

FightController::~FightController() { }

FightController::FightController(const FightController& other)
{
	_player = std::make_unique<FightCharacter>(*other._player);
	_enemy = std::make_unique<FightCharacter>(*other._enemy);
	_turnDecider = other._turnDecider;
}

FightCharacter& FightController::getActiveFighter() const
{
	return *_activeFighter;
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
		_enemyAi.executeMove(*this);
	}
}
void FightController::reset()
{
	_player->reset();
	_enemy->reset();
	_currentRound = 0;
	_currentDifficulty = 1;
	_scoreKeeper.resetScore();
	nextTurn();
}
void FightController::executeMove(Move* move)
{
	notifyObservers(_activeFighter->getName() + " used " + move->getName());

	(*move)();
	_activeFighter->endTurn();

	if (!_player->isAlive())
	{
		lose();
		return;
	}
	else if (!_enemy->isAlive())
	{
		win();
		return;
	}

	nextTurn();
}

void FightController::nextTurn()
{
	_turnDecider.nextTurn();
	_activeFighter = &_turnDecider.getTurnCharacter();
	_activeFighter->startTurn();

	if (_enemyAi.getFighterName() == _activeFighter->getName()) {
		aiMovePending = true;
		aiTimer.restart();
	}

}

void FightController::nextFight()
{
	notifyObservers("NEXT FIGHT");

	_currentRound++;
	_currentDifficulty = (_currentRound / 2) + 1;

	_enemy->setCharacterData(_characterFactory(_currentDifficulty));


	nextTurn();
}

void FightController::win()
{
	notifyObservers("YOU WON!");
	_scoreKeeper.addScore(_currentDifficulty * 10);
	nextFight();
}

void FightController::lose()
{
	notifyObservers("YOU LOST!");
	_scoreKeeper.saveScore();
	_scoreKeeper.resetScore();
}
