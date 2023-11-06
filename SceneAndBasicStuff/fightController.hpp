#pragma once
#include <vector>
#include <string>

#include "gameObject.hpp"
#include "fightCharacter.hpp"
#include "turnDecider.hpp"
#include "move.hpp"
#include "subject.hpp"
#include "enemyAI.hpp"
#include "scene.hpp"

class FightController : public GameObject, public Subject<std::string>
{
private:
	sf::Clock aiTimer;
	bool aiMovePending = false;
	sf::Time aiDelay = sf::seconds(0.5);

	std::shared_ptr <FightCharacter> _player;
	std::shared_ptr <FightCharacter> _enemy;

	EnemyAI enemyAi;
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
	
	void start() override;
	void update() override;
	void reset();
	void executeMove(Move* move);
	void nextTurn();

private:
	void win();
	void lose();
};
