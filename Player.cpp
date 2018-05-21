//
// Created by Evgenii Shchagin on 20.05.18.
//
#include "Player.h"

Player::Player(std::string name):
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

void Player::formTroop() {
    std::vector<Character> newTroop;
    std::cout << "Вводите сначала имя персонажа, а затем желаемое количество. " << std::endl;
    std::cout << "Для завершения введите finish " << std::endl;

    std::string characterName = "";
    int quantity = 0;
    int totalPrice = 0;
    int tempBalance = gold;

    while (characterName != "finish") {
        std::cin >> characterName >> quantity;

        Character wantedCharacter = database.characters.at(characterName);
        int charactersPrice = wantedCharacter.price * quantity;

        if (charactersPrice > tempBalance) {
            std::cout << "Недостаточно золота" << std::endl;
        } else {
            tempBalance -= charactersPrice;
            totalPrice += charactersPrice;
            std::vector<Character> new_characters(quantity, wantedCharacter);
            newTroop.insert(newTroop.end(), new_characters.begin(), new_characters.end());
        }
    }

    int fee = calculateFee(newTroop);
    if (tempBalance < fee) {
        std::cout << "Недостаточно золота" << std::endl;
    } else {
        gold -= totalPrice + fee;
        troops.emplace_back(newTroop);
        std::cout << "Отряд успешно сформирован" << std::endl;
    }

}
