#include <iostream>
#include "Weapon.h"

int main()
{
    //Testing Default Constructor
    Weapon weapon1 = Weapon();

    //Testing member functions
    cout << "Name: " << weapon1.getName() << endl;
    cout << "Story: " << weapon1.getStory() << endl;
    cout << "Cost: " << weapon1.getCost() << endl;
    cout << "Damage: " << weapon1.getDamage() << endl;

    //Testing Paramteterized Constructor
    Weapon weapon2 = Weapon("JOHHNY", 100, 50, "This weapon came out an Ice Cream Truck, sorry!");

    cout << "Name: " << weapon2.getName() << endl;
    cout << "Story: " << weapon2.getStory() << endl;
    cout << "Cost: " << weapon2.getCost() << endl;
    cout << "Damage: " << weapon2.getDamage() << endl;

}
