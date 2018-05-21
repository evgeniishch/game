//
// Created by Evgenii Shchagin on 20.05.18.
//

#include "Game.h"

void Game::initializePlayers() {
    int numberOfPlayers;

    std::cout << "Введите количество игроков: ";
    std::cin >> numberOfPlayers;

    for (int i = 0; i < numberOfPlayers; ++i) {
        std::string playerName;

        std::cout << "Игрок " << i + 1 << ", представься: ";
        std::cin >> playerName;

        Player newPlayer(playerName);

        players.push_back(newPlayer);
    }
}

void Game::initiallyChooseCharacters() {
//    std::cout<< "Im here"<<std::endl;
    std::cout<<players.size();
    std::vector<bool> finished(players.size(), false);
    int finishedPlayers = 0;

    while (finishedPlayers != players.size()) {
        for (int i = 0; i < players.size(); ++i) {
            if (!finished[i]) {
                std::string characterName;
                std::cout << players[i].name << ", выберите персонажа или введите finish" << std::endl;
                std::cin >> characterName;

                if (characterName == "finish") {
                    finished[i] = true;
                    finishedPlayers++;
                } else {
                    players[i].chooseCharacter(characterName);
                }
            }
        }
    }
}


void Game::placeOnBattlefield() {
    std::string command = "";
    std::cout << "Выберите troop или single" << std::endl;
    std::cin >> command;
    if(command == "troop") {
        if (players[currentPlayerNumber].troops.size() == 0) {
            std::cout << "У вас еще нет отрядов" << std::endl;
        } else {
            std::cout << "У вас " << players[currentPlayerNumber].troops.size() << " отрядов." << std::endl;
            std::cout << "Введите номер отряда, который хотите выставить: ";
            int troopNumber = 0;
            std::cin >> troopNumber;

            std::vector<Character> chosenTroop = players[currentPlayerNumber].troops[troopNumber];

            for (auto &character : chosenTroop) {
                battlefield.emplace_back(std::make_pair(currentPlayerNumber, character));
            }

            players[currentPlayerNumber].troops.erase(players[currentPlayerNumber].troops.begin(),
                                                      players[currentPlayerNumber].troops.begin() + troopNumber);
        }
    }
    if (command == "single") {
        std::cout << "У вас " << players[currentPlayerNumber].characters.size() << " персонажей." << std::endl;
        std::cout << "Введите номер персонажа, которого хотите выставить: ";
        int characterNumber = 0;
        std::cin >> characterNumber;



        battlefield.push_back(std::make_pair(currentPlayerNumber, players[currentPlayerNumber].characters[characterNumber]));
        players[currentPlayerNumber].characters.erase(players[currentPlayerNumber].characters.begin(),
                                                      players[currentPlayerNumber].characters.begin() + characterNumber);
    }
}

void Game::attack() {
    std::cout << "Введите номер персонажа, которым вы хотите атаковать: ";
    int attacker = 0;
    std::cin >> attacker;

    std::cout << "Введите номер персонажа которого вы хотите атаковать: ";
    int victim = 0;
    std::cin >> victim;

    battlefield[victim].second.health = std::max(0, battlefield[victim].second.health - battlefield[attacker].second.damage);
    if (battlefield[victim].second.health == 0) {
        battlefield[attacker].second.experience += 20;
        battlefield.erase(battlefield.begin(), battlefield.begin() + victim);
    } else {
        battlefield[attacker].second.experience += 10;
    }
}

void Game::makeMove() {
    std::cout << "Команды: 1 - купить персонажа, 2 - сформировать отряд, 3 - выставить на поле, 4 - атаковать, 5 - finish" << std::endl;
    const int buy = 1, form_troop = 2, place_on_bttlf = 3, interact = 4, finish = 5;
    int command = 0;

    while (command != finish) {
        std::cin >> command;
        switch (command) {
            case buy: {

                std::string characterName = "";
                std::cin >> characterName;
                players[currentPlayerNumber].chooseCharacter(characterName);
            }
            case form_troop: {
                players[currentPlayerNumber].formTroop();
            }
            case place_on_bttlf: {
                placeOnBattlefield();
            }
            case interact : {
                attack();
            }
        }
    }

}

void Game::startGame() {
    initializePlayers();
    initiallyChooseCharacters();
    runGame();
}

void Game::runGame() {
    std::cout << "And let the game begin!" << std::endl;

    currentPlayerNumber = 0;

    while (true) {
        if (currentPlayerNumber) {
            std::cout<< players[currentPlayerNumber].name << " won!" << std::endl;
            break;
        } else {
            makeMove();
            currentPlayerNumber = (currentPlayerNumber + 1) % players.size();
        }
    }
}