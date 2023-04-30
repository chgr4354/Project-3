#include <iostream>
#include "Food.h"

int main()
{
    //Default Contructor
    Food food1 = Food();

    //Testing member functions
    cout << "Name: " << food1.getName() << endl;
    cout << "Cost: " << food1.getCost() << endl;
    cout << "Recover: " << food1.getRecover() << endl;

    //Paramterized Contructor
    Food food2 = Food("STINKY LETTUCE(LOW CARB)", 100, 2000);

    //Testing Member Functions
    cout << "Name: " << food2.getName() << endl;
    cout << "Cost: " << food2.getCost() << endl;
    cout << "Recover: " << food2.getRecover() << endl;
}
