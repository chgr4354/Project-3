#include <cassert>
#include "Armor.h"

using namespace std;

int main()
{
    //Testing default constructor
    Armor armor1 = Armor();

    //Testing data members for default constructor
    cout << "Armor Name: " << armor1.getName() << endl;
    cout << "Armor Cost: " << armor1.getCost() << endl;
    cout << "Armor Protection: " << armor1.getProtection() << endl;
    cout << "Armor Story: " << armor1.getStory() << endl;
    assert(armor1.getName() == "regular clothes");
    assert(armor1.getCost() == 0);
    assert(armor1.getProtection() == 1);
    assert(armor1.getStory() == "The clothes you grabbed from your dirty laundry pile. Do the laundry!");

    //Testing Paramterized Constructor
    Armor armor2 = Armor("DONKEH", 6, 600, "There is no story, there was major budget cuts");

    //Testing Paramterized Constructor
    cout << "Armor Name: " << armor2.getName() << endl;
    cout << "Armor Cost: " << armor2.getCost() << endl;
    cout << "Armor Protection: " << armor2.getProtection() << endl;
    cout << "Armor Story: " << armor2.getStory() << endl;
    assert(armor2.getName() == "DONKEH");
    assert(armor2.getCost() == 600);
    assert(armor2.getProtection() == 6);
    assert(armor2.getStory() == "There is no story, there was major budget cuts");

    //testing setters
    armor2.setCost(50);
    armor2.setName("Hello");
    armor2.setProtection(100);
    armor2.setStory("This is a story");
    assert(armor2.getName() == "Hello");
    assert(armor2.getCost() == 50);
    assert(armor2.getProtection() == 100);
    assert(armor2.getStory() == "This is a story");

}
