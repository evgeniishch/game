//
// Created by Evgenii Shchagin on 23.05.18.
//
#pragma once

#include "Command.h"

class attackCommand: public Command {
public:
    explicit attackCommand(Game *_game);
    void execute() override;

private:
    Game * game;
};

