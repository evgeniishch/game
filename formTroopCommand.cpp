//
// Created by Evgenii Shchagin on 23.05.18.
//

#include "formTroopCommand.h"

formTroopCommand::formTroopCommand(Game *_game): game(_game) {}

void formTroopCommand::execute() {
    game->players[game->currentPlayerNumber].formTroop();
}