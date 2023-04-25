#include "Weapon.h"

using namespace std;

//constructors
Weapon::Weapon() {
    name = "butter knife";
    damage = 1;
    cost = 0;
    story = "The butter knife you grabbed from your favorite Italian place before you began your journey. They'll never notice.";
}
Weapon::Weapon(string new_name, int new_damage, int new_cost, string new_story) {
    name = new_name;
    damage = new_damage;
    cost = new_cost;
    story = new_story;
}

//getters
int Weapon::getDamage() {
    return damage;
}
int Weapon::getCost() {
    return cost;
}
string Weapon::getName() {
    return name;
}
string Weapon::getStory() {
    return story;
}

//setters
void Weapon::setDamage(int new_damage) {
    damage = new_damage;
}
void Weapon::setCost(int new_cost) {
    cost = new_cost;
}
void Weapon::setName(string new_name) {
    name = new_name;
}
void Weapon::setStory(string new_story) {
    story = new_story;
}
