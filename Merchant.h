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
        string name = "Jared";      //name of merchant (const)
        vector<Weapon> weapon_inv;  //weapon inventory
        vector<Food> food_inv;      //food inventory
        vector<Armor> armor_inv;    //armor inventory

    public:
        Merchant(); //default constructor
        Merchant(string weapon_file, string food_file, string armor_file); //parameterized constructor

        //getters
        Weapon getWeapon(int index);    //get weapon from inventory
        Food getFood(int index);        //get food from inventory
        Armor getArmor(int index);      //get armor from inventory
        string getName();               //get name

        vector<Weapon> getWeaponInv();  //return weapon inventory
        vector<Armor> getArmorInv();    //return armor inventory
        vector<Food> getFoodInv();      //return food inventory

        //mutators
        void addWeapon(Weapon weapon);  //add weapon to weapon inventory
        void addArmor(Armor armor);     //add armor to armor inventory
        void addFood(Food food);        //add food to food inventory
        bool removeWeapon(int index);   //remove weapon from weapon inventory
        bool removeArmor(int index);    //remove armor from armor inventory
        bool removeFood(int index);     //remove food from food inventory

};
#endif
