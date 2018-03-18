#include <iostream>
#include <vector>

#include "Player.h"
using namespace std;

int main() {
    int numberOfPlayers;

    cout << "Enter number of players: ";
    cin >> numberOfPlayers;

    vector<Player> players;

    for (int i = 0; i < numberOfPlayers; ++i) {
        string playerName;

        cout << "Player " << i + 1 <<", introduce yourself: ";
        cin >> playerName;

        Player newPlayer(playerName);

        players.push_back(newPlayer);
    }

    vector<bool> finished(players.size());
    int finishedPlayers = 0;

    while (finishedPlayers != players.size()) {
        for (int i = 0; i < players.size(); ++i) {
            if (!finished[i]) {
                string characterName;
                cout << players[i].name << ", choose a character or print finish"<<endl;
                cin >> characterName;

                if (characterName == "finish") {
                    finished[i] = true;
                    finishedPlayers++;
                } else {
                    players[i].chooseCharacter(characterName);
                }

            }
        }
    }


    cout << "And let the game begin!"<<endl;
    // to be continued

    return 0;
}