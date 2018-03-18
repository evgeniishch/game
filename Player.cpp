#include <string>
#include "Player.h"

Player::Player(std::string name) :
        name(std::move(name)), gold(1000) {};

void Player::chooseCharacter(const std::string characterName) {
    Character wantedCharacter = database.characters.at(characterName);
    if (wantedCharacter.price <= gold) {
        gold -= wantedCharacter.price;
        characters.push_back(wantedCharacter);
    } else {
        std::cout << "Not enough gold" << std::endl;
    }
}

