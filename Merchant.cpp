#include <fstream>
#include "Merchant.h"
#include "vectorSplit.h"

using namespace std;

Merchant::Merchant() {
    // N/A
}

Merchant::Merchant(string weapons_file, string food_file, string armor_file) {
    vector<string> data;
    vectorSplit(weapons_file, '|', data);
    for(int i = 0; i < data.size(); i+3) {
        weapons_inv.push_back(Weapon(data[i], stoi(data[i+1]), data[i+2])); // fill merchant's weapons inventory
    }

    data.clear();
    vectorSplit(food_file, '|', data);
    for(int i = 0; i < data.size(); i+2) {
        food_inv.push_back(Food(data[i], stoi(data[i+1]))); //fill merchant's food inventory
    }

    data.clear();
    vectorSplit(armor_file, '|', data);
    for(int i = 0; i < data.size(); i+3) {
        armor_inv.push_back(Armor(data[i], stoi(data[i+1]), data[i+2])); // fill merchant's armor inventory
    }

}

//getters
Weapon Merchant::getWeapon(int index) {
    if(index < weapons_inv.size())
        return weapons_inv[index];
    else
        return;
}
Food Merchant::getFood(int index) {
    if(index < food_inv.size())
        return food_inv[index];
    else
        return;
}
Armor Merchant::getArmor(int index) {
    if(index < armor_inv.size())
        return armor_inv[index];
    else
        return;
}
string Merchant::getName() {
    return name;
}

//setters
void Merchant::addWeapon(Weapon weapon) {
    weapons_inv.push_back(weapon);
}
void Merchant::addFood(Food food) {
    food_inv.push_back(food);
}
void Merchant::addArmor(Armor armor) {
    armor_inv.push_back(armor);
}