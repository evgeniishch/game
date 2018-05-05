//
// Created by Evgenii Shchagin on 05.05.18.
//
// Здесь прописаны все функции и константы, которые отвечают за правила игры
// т.е. функции, в которых они захардкожены

#include <math.h>

const int MIN_DIFF = 1;
const int MIN_FEE = 10;

int calculateFee(std::vector<Character> troop) {
    double fee = MIN_FEE;
    for (auto &character: troop) {
        double add = static_cast<double>(character.damage - MIN_DIFF) / static_cast<double>(character.damage);
        fee += add;
    }
    return static_cast<int>(fee);
}


