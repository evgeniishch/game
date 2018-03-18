#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "Character.h"
#include "Data.h"

class Player {
public:
    std::string name;
    int gold;
    std::vector<Character> characters;

    Player(std::string name);

    void chooseCharacter(std::string characterName);

private:
    Data database;
};