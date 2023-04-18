#include "Armor.h"

using namespace std;

Armor::Armor() {
    name = "";
    protection = 0;
    story = "";
}
Armor::Armor(string new_name, int new_protection, string new_story) {
    name = new_name;
    protection = new_protection;
    story = new_story;
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

void Armor::setName(string new_name) {
    name = new_name;
}
void Armor::setStory(string new_story) {
    story = new_story;
}
void Armor::setProtection(int new_protection) {
    protection = new_protection;
}