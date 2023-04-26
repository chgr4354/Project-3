#include <iostream>
#include "Monster.h"
#include "vectorSplit.h"

using namespace std;

Monster::Monster() {
    name = "Lv. 1 Mafia Boss";
    damage = 0;
    health = 0;
}

Monster::Monster(string filename) {
    vector<string> data;
    vectorSplit(filename, '|', data);

    int numMonsters = data.size() / 3; // calculate number of monsters in the file
    int randNum = rand() % numMonsters; // generate random number between 0 and numMonsters-1

    name = data.at(randNum*3);
    health = stoi(data.at(randNum*3+1));
    damage = stoi(data.at(randNum*3+2));
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
