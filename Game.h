//
// Created by Evgenii Shchagin on 20.05.18.
//
#pragma once

#include "Player.h"
#include "GameRules.h"

class Game {
public:
    Game() = default;

    void startGame();


protected:
    void initializePlayers();
    void initiallyChooseCharacters();
    void runGame();
    void makeMove();
    void placeOnBattlefield();
    void attack();

    std::vector<Player> players;
    std::vector<std::pair<int, Character>> battlefield;
    int currentPlayerNumber;
};

