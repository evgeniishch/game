//
// Created by Evgenii Shchagin on 21.05.18.
//

#include "GameRules.h"
#include "Player.h"

int calculateFee(std::vector<Character> troop) {
    double fee = MIN_FEE;
    for (auto &character: troop) {
        double add = static_cast<double>(character.damage - MIN_DIFF) / static_cast<double>(character.damage);
        fee += add;
    }
    return static_cast<int>(fee);
}

bool won(int currentPlayerNumber) {
    // Здесь обсчитывается, победил ли игрок в игре.
    // Расписывать критерии победы я, конечно, не буду.
    // Поэтому пока игра будет продолжаться бесконечно
    return false;
}
