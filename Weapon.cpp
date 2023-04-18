#include "Weapon.h"

using namespace std;

Weapon::Weapon() {
    name = "";
    damage = 0;
    story = "";
}
Weapon::Weapon(string new_name, int new_damage, string new_story) {
    name = new_name;
    damage = new_damage;
    story = new_story;
}

int Weapon::getDamage() {
    return damage;
}
string Weapon::getName() {
    return name;
}
string Weapon::getStory() {
    return story;
}

void Weapon::setDamage(int new_damage) {
    damage = new_damage;
}
void Weapon::setName(string new_name) {
    name = new_name;
}
void Weapon::setStory(string new_story) {
    story = new_story;
}