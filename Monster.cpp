#include <iostream>
#include "Monster.h"
#include "vectorSplit.h"

using namespace std;

Monster::Monster() { //default constructor
    name = "Lv. 1 Mafia Boss";
    damage = 0;
    health = 0;
}

Monster::Monster(string filename) { //paramaterized constructor
    vector<string> data;
    vectorSplit(filename, '|', data);

    int numMonsters = data.size() / 3; // calculate number of monsters in the file
    int randNum = rand() % numMonsters; // generate random number between 0 and numMonsters-1

    //randomly pick a monster from the file
    name = data.at(randNum*3);
    health = stoi(data.at(randNum*3+1));
    damage = stoi(data.at(randNum*3+2));
}


void Monster::setName(string new_name) { //set name
    name = new_name;
}
void Monster::setHealth(int new_health) { //set health
    health = new_health;
}
void Monster::setDamage(int new_damage) { //set damage
    damage = new_damage;
}

string Monster::getName() { //get name
    return name;
}
int Monster::getHealth() { //get health
    return health;
}
int Monster::getDamage() { //get damage
    return damage;
}
