//
// Created by Evgenii Shchagin on 20.05.18.
//

#include "Game.h"
#include "buyCommand.h"
#include "formTroopCommand.h"
#include "placeOnBttlfdCommand.h"
#include "attackCommand.h"

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

void Game::buyCharacter() {
    std::cout << "Введите имя персонажа, которого хотите купить: ";
    std::string characterName;
    std::cin >> characterName;
    players[currentPlayerNumber].chooseCharacter(characterName);
}

void Game::updateTroops() {
    // обновляем экономику отрядов каждого персонажа
}

void Game::startGame() {
    initializePlayers();
    initiallyChooseCharacters();
    runGame();
}

void Game::runGame() {
    std::cout << "Да начнется битва!" << std::endl;

    currentPlayerNumber = 0;

    while (true) {
        if (won(currentPlayerNumber)) {
            std::cout << players[currentPlayerNumber].name << " won!" << std::endl;
            break;
        } else {
            std::cout << "Now it's " << players[currentPlayerNumber].name <<"'s turn!" << std::endl;
            printCommands();
            int command = 0;
            const int buy = 1, form_troop = 2, place_on_bttlf = 3, attack = 4, finish = 5;

            while(command != finish) {
                std::cin >> command;
                switch (command) {
                    case buy: {
                        buyCommand buy_cmd(this);
                        buy_cmd.execute();
                    }
                    case form_troop: {
                        formTroopCommand formTroop_cmd(this);
                        formTroop_cmd.execute();
                    }
                    case place_on_bttlf: {
                        placeOnBttlfdCommand placeOnBf_cmd(this);
                        placeOnBf_cmd.execute();
                    }
                    case attack: {
                        attackCommand attack_cmd(this);
                        attack_cmd.execute();
                    }
                    default: {
                        std::cout << "Неверная команда" << std::endl;
                    }
                }
            }
            updateTroops();
            currentPlayerNumber = (currentPlayerNumber + 1) % players.size();
        }
    }
}

void Game::printCommands() {
    std::cout << "Команды: 1 - купить персонажа, 2 - сформировать отряд, 3 - выставить на поле, 4 - атаковать, 5 - finish" << std::endl;
}