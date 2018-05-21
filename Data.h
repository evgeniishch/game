//
// Created by Evgenii Shchagin on 20.05.18.
//
#pragma once

#include <vector>
#include <map>
#include "Character.h"

class Data {
public:
    Data();
    std::map <std::string, Character> characters;
};
