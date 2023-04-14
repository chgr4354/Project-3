#include <iostream>
#include "Monster.h"

using namespace std;

Monster::Monster() {
    name = "Lv. 1 Mafia Boss";
    damage = 0;
    health = 0;
}

Monster::Monster(string new_name, int new_health, int new_damage) {
    name = new_name;
    health = new_health;
    damage = new_damage;
}

void Monster::setName(string new_name) {
    name = new_name;
}
void Monster::setHealth(int new_health) {
    health = new_health;
}
void Monster::setDamage(int new_damage) {
    damage = new_damage;
}

string Monster::getName() {
    return name;
}
int Monster::getHealth() {
    return health;
}
int Monster::getDamage() {
    return damage;
}
