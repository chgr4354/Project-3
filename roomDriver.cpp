#include <iostream>
#include "Room.h"
using namespace std;

int main()
{
    //Testing Default Constructor
    Room room1 = Room();

    //Testing Member Functions
    cout << "Get Level Number: " << room1.getLevelNumber() << endl;
    cout << "Get Room Column: " << room1.getRoomCol() << endl;
    cout << "Get Room Row: " <<  room1.getRoomRow() << endl;

    //Testing Paramterzied Constructor
    Room room2 = Room(685, 8, 4);

    //Testing Member Functions
    cout << "Get Level Number: " << room2.getLevelNumber() << endl;
    cout << "Get Room Column: " << room2.getRoomCol() << endl;
    cout << "Get Room Row: " <<  room2.getRoomRow() << endl;

}
