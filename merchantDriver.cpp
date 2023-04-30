#include <iostream>
#include <vector>
#include "Food.h"
#include "Weapon.h"
#include "Armor.h"
#include "Merchant.h"
#include "vectorSplit.h"
//g++ -std=c++17 merchantDriver.cpp Merchant.cpp Armor.cpp Weapon.cpp Food.cpp vectorSplit.cpp
using namespace std;

int main()
{
    //Testing Parameterized Constructor
    Merchant merchant1 = Merchant("easy_weapons_file.txt","food_file.txt", "easy_armor_file.txt");

    //Testing Member Functions
    cout << "Name: " << merchant1.getName() << endl;
    cout << "\nWeapon Inventory: " << endl;
    for (int i = 0; i < merchant1.getWeaponInv().size(); i++)
    {
        cout << merchant1.getWeaponInv().at(i).getName() << " , ";
    }
    cout << endl;
    cout << "\nArmor Inventory: " << endl;
    for (int i = 0; i < merchant1.getArmorInv().size(); i++)
    {
        cout << merchant1.getArmorInv().at(i).getName() << " , ";
    }
    cout << endl;
    cout << "\nFood Inventory: " << endl;
    for (int i = 0; i < merchant1.getFoodInv().size(); i++)
    {
        cout << merchant1.getFoodInv().at(i).getName() << " , ";
    }


}
