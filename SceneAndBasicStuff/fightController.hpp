#pragma once
#include <vector>
#include <string>

#include "gameObject.hpp"
#include "fightCharacter.hpp"
#include "turnDecider.hpp"
#include "move.hpp"
#include "subject.hpp"
#include "enemyAI.hpp"
#include "characterFactory.hpp"
#include "scoreKeeper.hpp"

class FightController : public GameObject, public Subject<std::string>
{
private:
	sf::Clock aiTimer;
	bool aiMovePending = false;
	sf::Time aiDelay = sf::seconds(0.5);

	std::shared_ptr <FightCharacter> _player;
	std::shared_ptr <FightCharacter> _enemy;

	EnemyAI _enemyAi;
	FightCharacter* _activeFighter = nullptr;
	TurnDecider _turnDecider;
	CharacterFactory _characterFactory;
	ScoreKeeper _scoreKeeper;

	unsigned int _currentDifficulty = 0;
	unsigned int _currentRound = 0;
public:
	FightController(std::string, FightCharacter player);
	~FightController();

	FightController(const FightController& other);
public:
	FightCharacter& getActiveFighter() const;
	FightCharacter& getEnemy() const;
	FightCharacter& getPlayer() const;

	void setPlayer(FightCharacter player);
	void setEnemy(FightCharacter enemy);

	void start() override;
	void update() override;

	void reset();
	void executeMove(Move* move);

private:
	void nextTurn();
	void nextFight();
	void win();
	void lose();
};
