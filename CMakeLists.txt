cmake_minimum_required(VERSION 3.8)
project(BoardGame)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Character.cpp Character.h Data.cpp Data.h Player.cpp Player.h Game.cpp Game.h GameRules.h GameRules.cpp Command.cpp Command.h attackCommand.cpp attackCommand.h buyCommand.cpp buyCommand.h formTroopCommand.cpp formTroopCommand.h placeOnBttlfdCommand.cpp placeOnBttlfdCommand.h CharacterOnField.cpp CharacterOnField.h)
add_executable(BoardGame ${SOURCE_FILES})