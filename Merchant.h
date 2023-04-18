#include <iostream>
#include <vector>
#include "Food.h"
#include "Weapon.h"
#include "Armor.h"

using namespace std;

class Merchant {

    private:

        string name = "Jared";
        vector<Weapon> weapons_inv;
        vector<Food> food_inv;
        vector<Armor> armor_inv;

    public:
        Merchant();
        Merchant(string weapons_file, string food_file, string armor_file);

        //getters
        Weapon getWeapon(int index);
        Food getFood(int index);
        Armor getArmor(int index);
        string getName();

        //mutators
        void addWeapon(Weapon weapon);
        void addFood(Food food);
        void addArmor(Armor armor);

};