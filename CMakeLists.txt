cmake_minimum_required(VERSION 3.8)
project(BoardGame)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Character.h Player.h Player.cpp Data.cpp Data.h Character.cpp Game.cpp Game.h GameRules.h)
add_executable(BoardGame ${SOURCE_FILES})