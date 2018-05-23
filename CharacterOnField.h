//
// Created by Evgenii Shchagin on 23.05.18.
//
#pragma once


#include "Character.h"

struct CharacterOnField {
    Character character;
    int playerNumber;

    CharacterOnField(int playerNum, Character _char);
    CharacterOnField() = default;
};