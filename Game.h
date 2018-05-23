//
// Created by Evgenii Shchagin on 20.05.18.
//
#pragma once

#include "Player.h"
#include "GameRules.h"
#include "CharacterOnField.h"

class Game {
public:
    Game() = default;

    void startGame();
    void initializePlayers();
    void initiallyChooseCharacters();
    void runGame();

    void placeOnBattlefield();
    void attack();
    void updateTroops();
    void buyCharacter();

    void printCommands();

    std::vector<Player> players;
    std::vector<CharacterOnField> battlefield;
    int currentPlayerNumber;

private:

};

