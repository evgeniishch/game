#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "Character.h"
#include "Data.h"
#include "GameRules.h"

class Player {
public:
    std::string name;
    int gold;
    std::vector<Character> characters;
    std::vector<std::vector<Character>> troops;

    Player(std::string name);

    void chooseCharacter(std::string characterName);
    void formTroop();

private:
    Data database;
};