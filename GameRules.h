//
// Created by Evgenii Shchagin on 05.05.18.
//
// Здесь прописаны все функции и константы, которые отвечают за правила игры
// т.е. функции, в которых они захардкожены
#pragma once

#include <vector>
#include "Character.h"
#include "Player.h"

const int MIN_DIFF = 1;
const int MIN_FEE = 10;

int calculateFee(std::vector<Character> troop);
bool won(int currentPlayerNumber);