#include <iostream>
#include <cassert>
#include "Weapon.h"

int main()
{
    //Testing Default Constructor
    Weapon weapon1 = Weapon();

    //Testing member functions
    cout << "Weapon1 Name: " << weapon1.getName() << endl;
    cout << "Weapon1 Story: " << weapon1.getStory() << endl;
    cout << "Weapon1 Cost: " << weapon1.getCost() << endl;
    cout << "Weapon1 Damage: " << weapon1.getDamage() << endl;
    assert(weapon1.getName() == "butter knife");
    assert(weapon1.getStory() == "The butter knife you grabbed from your favorite Italian place before you began your journey. They'll never notice.");
    assert(weapon1.getCost() == 0);
    assert(weapon1.getDamage() == 1);


    //Testing Paramteterized Constructor
    Weapon weapon2 = Weapon("JOHNNY", 100, 50, "This weapon came out an Ice Cream Truck, sorry!");

    cout << "weapon2 Name: " << weapon2.getName() << endl;
    cout << "weapon2 Story: " << weapon2.getStory() << endl;
    cout << "weapon2 Cost: " << weapon2.getCost() << endl;
    cout << "weapon2 Damage: " << weapon2.getDamage() << endl;
    assert(weapon2.getName() == "JOHNNY");
    assert(weapon2.getStory() == "This weapon came out an Ice Cream Truck, sorry!");
    assert(weapon2.getCost() == 50);
    assert(weapon2.getDamage() == 100);

    weapon2.setCost(100);
    weapon2.setDamage(75);
    weapon2.setName("sword");
    weapon2.setStory("This is a story");
    assert(weapon2.getName() == "sword");
    assert(weapon2.getStory() == "This is a story");
    assert(weapon2.getCost() == 100);
    assert(weapon2.getDamage() == 75);

}
