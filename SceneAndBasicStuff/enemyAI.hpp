#pragma once

#include <string>
#include "fightCharacter.hpp"
#include "move.hpp"

class FightController;  // Forward declaration

class EnemyAI
{
private:
    Move* _moves[4];
    std::shared_ptr<FightCharacter> _controlledFighter;
    std::shared_ptr<FightCharacter> _target;


public:
    EnemyAI();
    EnemyAI(std::shared_ptr<FightCharacter> fighter, std::shared_ptr<FightCharacter> target);
    ~EnemyAI();

    std::string getFighterName() const;
    void executeMove(FightController& fightController);  // Corrected parameter name

private:
    Move* decideMove();
};
