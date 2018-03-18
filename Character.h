#pragma once

#include <string>

class Character {
public:
    std::string name;
    int price;
    int health;
    int armour;
    int damage;

    // vector<Armour> armour;
    // vector<Abilities> abilities;

    Character (std::string name, int price, int health, int armour, int damage);
};
