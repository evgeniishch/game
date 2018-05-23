//
// Created by Evgenii Shchagin on 23.05.18.
//
#pragma once

#include "Command.h"

class placeOnBttlfdCommand: public Command {
public:
    explicit placeOnBttlfdCommand(Game* _game);
    void execute() override;

private:
    Game *game;
};