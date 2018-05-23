//
// Created by Evgenii Shchagin on 23.05.18.
//

#include "buyCommand.h"

buyCommand::buyCommand(Game *_game): game(_game) {}

void buyCommand::execute() {
    game->buyCharacter();
}