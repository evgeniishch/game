//
// Created by Evgenii Shchagin on 20.05.18.
//
#include "Data.h"

Data::Data() {
    characters.insert(std::pair<std::string, Character>("Wizard", Character("Wizard", 550, 250, 150, 50)));
    characters.insert(std::pair<std::string, Character>("Dwarf", Character("Dwarf", 200, 200, 250, 30)));
    // and so on ...
}



