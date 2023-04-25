#include "Armor.h"

using namespace std;

Armor::Armor() {
    name = "regular clothes";
    protection = 1;
    story = "The clothes you grabbed from your dirty laundry pile. Do the laundry!";
    cost = 0;
}
Armor::Armor(string new_name, int new_protection, int new_cost, string new_story) {
    name = new_name;
    protection = new_protection;
    story = new_story;
    cost = new_cost;
}

string Armor::getName() {
    return name;
}
string Armor::getStory() {
    return story;
}
int Armor::getProtection() {
    return protection;
}
int Armor::getCost() {
    return cost;
}

void Armor::setName(string new_name) {
    name = new_name;
}
void Armor::setStory(string new_story) {
    story = new_story;
}
void Armor::setProtection(int new_protection) {
    protection = new_protection;
}
void Armor::setCost(int new_cost) {
    cost = new_cost;
}
