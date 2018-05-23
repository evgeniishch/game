//
// Created by Evgenii Shchagin on 23.05.18.
//

#include "attackCommand.h"

attackCommand::attackCommand(Game *_game): game(_game) {}

void attackCommand::execute() {
    game->attack();
}