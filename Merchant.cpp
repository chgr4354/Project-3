#include <iostream>
#include <fstream>
#include "Merchant.h"
#include "vectorSplit.h"

using namespace std;

Merchant::Merchant() {
    // N/A
}


Merchant::Merchant(string weapon_file, string food_file, string armor_file) { //initialize merchant constructor
    vector<string> data;
    vectorSplit(weapon_file, '|', data);
    for(int i = 0; i < data.size(); i+=4) {
        weapon_inv.push_back(Weapon(data[i], stoi(data[i+1]), stoi(data[i+2]), data[i+3])); // fill merchant's weapons inventory
        //                            name         damage           cost          story
    }

    data.clear();
    vectorSplit(food_file, '|', data);
    for(int i = 0; i < data.size(); i+=3) {
        food_inv.push_back(Food(data[i], stoi(data[i+1]), stoi(data[i+2]))); //fill merchant's food inventory
        //                       name        recovery           cost
    }

    data.clear();
    vectorSplit(armor_file, '|', data);
    for(int i = 0; i < data.size(); i+=4) {
        armor_inv.push_back(Armor(data[i], stoi(data[i+1]), stoi(data[i+2]), data[i+3])); // fill merchant's armor inventory
        //                         name       protection         cost          story
    }

}

//getters
Weapon Merchant::getWeapon(int index) { //get weapon from weapon inventory
    if(index < weapon_inv.size()) //check for bounds
        return weapon_inv[index];
    else {
        Weapon weapon;
        return weapon;
    }
}
Food Merchant::getFood(int index) { //get food from food inventory
    if(index < food_inv.size()) //check for bounds
        return food_inv[index];
    else {
        Food food;
        return food;
    }
}
Armor Merchant::getArmor(int index) { //get armor from armor inventory
    if(index < armor_inv.size()) //check for bounds
        return armor_inv[index];
    else {
        Armor armor;
        return armor;
    }
}
string Merchant::getName() { //get name
    return name;
}
vector<Weapon> Merchant::getWeaponInv() { //get weapon
    return weapon_inv;
}
vector<Armor> Merchant::getArmorInv() { //get armor
    return armor_inv;
}
vector<Food> Merchant::getFoodInv() { //get food
    return food_inv;
}

//setters
void Merchant::addWeapon(Weapon weapon) { //add weapon to weapon weapon
    weapon_inv.push_back(weapon);
}
void Merchant::addFood(Food food) { //add food to food inventory
    food_inv.push_back(food);
}
void Merchant::addArmor(Armor armor) { //add armor to armor inventory
    armor_inv.push_back(armor);
}
bool Merchant::removeWeapon(int index) { //remove weapon from weapon inventory
    if(index < weapon_inv.size()) { //check for bounds
        weapon_inv.erase(weapon_inv.begin() + index);
        return true;
    }
    else
        return false;
}
bool Merchant::removeArmor(int index) { //remove armor from armor inventory
    if(index < armor_inv.size()) { //check for bounds
        armor_inv.erase(armor_inv.begin() + index);
        return true;
    }
    else
        return false;
}
bool Merchant::removeFood(int index) { //remove food from food inventory
    if(index < food_inv.size()) { //check for bounds
        food_inv.erase(food_inv.begin() + index);
        return true;
    }
    else
        return false;
}
