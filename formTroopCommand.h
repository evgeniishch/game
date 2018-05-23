//
// Created by Evgenii Shchagin on 23.05.18.
//
#pragma once

#include "Command.h"

class formTroopCommand: public Command {
public:
    explicit formTroopCommand(Game *_game);
    void execute() override;

private:
    Game *game;
};

