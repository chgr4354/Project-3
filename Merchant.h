#ifndef MERCHANT_H
#define MERCHANT_H

#include <iostream>
#include <vector>
#include "Food.h"
#include "Weapon.h"
#include "Armor.h"

using namespace std;

class Merchant {

    private:
        string name = "Jared";
        vector<Weapon> weapon_inv;
        vector<Food> food_inv;
        vector<Armor> armor_inv;

    public:
        Merchant();
        Merchant(string weapon_file, string food_file, string armor_file);

        //getters
        Weapon getWeapon(int index);
        Food getFood(int index);
        Armor getArmor(int index);
        string getName();

        vector<Weapon> getWeaponInv();
        vector<Armor> getArmorInv();
        vector<Food> getFoodInv();

        //mutators
        void addWeapon(Weapon weapon);
        void addArmor(Armor armor);
        void addFood(Food food);
        bool removeWeapon(int index);
        bool removeArmor(int index);
        bool removeFood(int index);

};
#endif
