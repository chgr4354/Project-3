#include <iostream>
#include <cassert>
#include "Food.h"

int main()
{
    //Default Contructor
    Food food1 = Food();

    //Testing member functions
    cout << "Name: " << food1.getName() << endl;
    cout << "Cost: " << food1.getCost() << endl;
    cout << "Recover: " << food1.getRecover() << endl;
    assert(food1.getName() == "");
    assert(food1.getCost() == 0);
    assert(food1.getRecover() == 0);

    //Paramterized Contructor
    Food food2 = Food("LETTUCE", 100, 2000);

    //Testing Member Functions
    cout << "Name: " << food2.getName() << endl;
    cout << "Cost: " << food2.getCost() << endl;
    cout << "Recover: " << food2.getRecover() << endl;
    assert(food2.getName() == "LETTUCE");
    assert(food2.getCost() == 2000);
    assert(food2.getRecover() == 100);
    
}
