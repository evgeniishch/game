//
// Created by Evgenii Shchagin on 23.05.18.
//
#pragma once

#include "Command.h"

class buyCommand: public Command {
public:
    explicit buyCommand(Game *_game);
    void execute() override;

private:
    Game *game;
};
