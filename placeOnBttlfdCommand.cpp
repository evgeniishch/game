//
// Created by Evgenii Shchagin on 23.05.18.
//

#include "placeOnBttlfdCommand.h"

placeOnBttlfdCommand::placeOnBttlfdCommand(Game *_game): game(_game) {}

void placeOnBttlfdCommand::execute() {
    game->placeOnBattlefield();
}