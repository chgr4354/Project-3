#include <iostream>
#include <cassert>
#include "Room.h"
using namespace std;

int main()
{
    //Testing Default Constructor
    Room room1 = Room();

    //Testing Member Functions
    cout << "Get Level Number: " << room1.getLevelNumber() << endl;
    cout << "Get Room Row: " <<  room1.getRoomRow() << endl;
    cout << "Get Room Column: " << room1.getRoomCol() << endl;
    assert(room1.getLevelNumber() == 0);
    assert(room1.getRoomRow() == 0);
    assert(room1.getRoomCol() == 0);

    //Testing Paramterzied Constructor
    Room room2 = Room(685, 8, 4);

    //Testing Member Functions
    cout << "Get Level Number: " << room2.getLevelNumber() << endl;
    cout << "Get Room Row: " <<  room2.getRoomRow() << endl;
    cout << "Get Room Column: " << room2.getRoomCol() << endl;
    assert(room2.getLevelNumber() == 685);
    assert(room2.getRoomRow() == 8);
    assert(room2.getRoomCol() == 4);

    //testing setters
    room2.setLevelNumber(2872);
    room2.setRoomPosition(7,5);
    assert(room2.getLevelNumber() == 2872);
    assert(room2.getRoomRow() == 7);
    assert(room2.getRoomCol() == 5);

}
