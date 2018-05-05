#pragma once

#include <string>

class Character {
public:
    std::string name;
    int price;
    int health;
    int armour;
    int damage;
    int experience;
    int troopExperience;

    // vector<Armour> armour;
    // vector<Abilities> abilities;

    Character (std::string name, int price, int health, int armour, int damage);
};
