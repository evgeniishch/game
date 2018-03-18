#include "Character.h"
#include <string>

Character::Character(std::string name, int price, int health, int armour, int damage) :
        name(name),
        price(price),
        health(health),
        armour(armour),
        damage(damage) {};

