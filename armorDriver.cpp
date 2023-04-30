#include <iomanip> //for spacing print statements - syntax obtained from stackexchange
#include <unistd.h> //for system and sleep functions - syntax obtained from stackexchange
#include <limits> //for correct input checking - syntax obtained from stackexchange
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

    //Testing Paramteritized Constructor
    Armor amror2 = Armor("DONKEH", 6, 600, "There is no story, there was major budget cuts");

    //Testing Paramteritized Constructor
    cout << "Armor Name" << amror2.getName() << endl;
    cout << "Armor Cost: " << amror2.getCost() << endl;
    cout << "Armor Protection: " << amror2.getProtection() << endl;
    cout << "Armor Story: " << amror2.getStory() << endl;

}
