#include <iostream>
#include <cassert>
#include "candy.h"
#include "candyCrush.h"
#include "Monster.h"
#include "Player.h"
#include "Map.h"

using namespace std;

int main() {
    srand(time(NULL));

//testing candyCrush class

    //default constructor always calls initializeBoard()

    candyCrush candyCrush1("testLevel.txt");
    candyCrush1.displayBoard();
    cout << "\n";

    assert(candyCrush1.getRows() == 11);
    assert(candyCrush1.getColumns() == 11);
    assert(candyCrush1.getScore() == 0);
    candyCrush1.setScore(5);
    assert(candyCrush1.getScore() == 5);

    assert(candyCrush1.isOnBoard(-1,-1) == false); //outside board
    assert(candyCrush1.isOnBoard(5,5) == true);    //inside board

    assert(candyCrush1.isSameColor(0,1,0,2) == true);  //blue vs. blue
    assert(candyCrush1.isSameColor(0,1,1,1) == false); //blue vs. yellow

    assert(candyCrush1.isStar(1, 8) == true);  //is star
    assert(candyCrush1.isStar(3,10) == false); //is not star

    assert(candyCrush1.isGift(2,5) == true);  //is gift
    assert(candyCrush1.isGift(6,7) == false); //is not gift


    //test swap() by swapping row 0 and 1, column "7" candies
    assert(candyCrush1.swap(0,7,1,7) == true);
    candyCrush1.displayBoard(); 
    cout << "\n";

    
    candyCrush1.removeMatches("🟦", 0, 3);
    candyCrush1.displayBoard();
    cout << "\n";

    candyCrush1.removeMatches("🟦", 4, 4);
    candyCrush1.displayBoard();
    cout << "\n";

    candyCrush testRemoveMatches("testRemoveMatches.txt");
    testRemoveMatches.displayBoard();
    cout << "Call removeMatches(\"🟦\", 4, 5)" << endl;
    testRemoveMatches.removeMatches("🟦", 4, 5);
    testRemoveMatches.displayBoard();
    cout << "\n";

    //test generate candies by generating random candies on row 0

    testRemoveMatches.generateCandy(4,8); //E8
    testRemoveMatches.displayBoard();
    cout << "\n";
    testRemoveMatches.generateCandy(0,5); //A5
    testRemoveMatches.displayBoard();
    cout << "\n";
    testRemoveMatches.generateCandy(6,4); //G4
    testRemoveMatches.displayBoard();
    cout << "\n";
    testRemoveMatches.generateCandy(0, -1); //no change, off board
    testRemoveMatches.displayBoard();
    cout << "\n";


//testing candy class

    //default constructor
    candy candy1;
    assert(candy1.getColor() == "-");
    assert(candy1.getRow() == 0);
    assert(candy1.getColumn() == 0);
    
    //parameterized constructor
    candy candy2("🟦", 5, 6);
    assert(candy2.getColor() == "🟦");
    assert(candy2.getColumn() == 6);
    assert(candy2.getRow() == 5);
    assert(candy2.isModifiableCandy() == true);
    assert(candy2.isSpecialCandy() == false);

    //test setters
    candy2.setColor("⭐");
    assert(candy2.getColor() == "⭐");
    assert(candy2.isSpecialCandy() == true);
    assert(candy2.isModifiableCandy() == true);

    candy2.setAll("🟨", 2, 3);
    assert(candy2.getRow() == 2);
    assert(candy2.getColumn() == 3);
    assert(candy2.getColor() == "🟨");

    candy2.setRow(8);
    assert(candy2.getRow() == 8);
    candy2.setColumn(1);
    assert(candy2.getColumn() == 1);

//testing monster class

    //default constructor
    Monster monster1;
    assert(monster1.getName() == "Lv. 1 Mafia Boss");
    assert(monster1.getDamage() == 0);
    assert(monster1.getHealth() == 0);

    //parameterized constructor
    Monster monster2("Level 98 Crime Lord", 30, 20);
    assert(monster2.getName() == "Level 98 Crime Lord");
    assert(monster2.getDamage() == 20);
    assert(monster2.getHealth() == 30);

    //testing setters
    monster2.setDamage(50);
    assert(monster2.getDamage() == 50);
    monster2.setHealth(40);
    assert(monster2.getHealth() == 40);
    monster2.setName("Level 130 Vladimir Putin");
    assert(monster2.getName() == "Level 130 Vladimir Putin");


//testing player class

    //Testing Default Constructor
    Player Player1;

    //Testing Default Constructor
    cout << "Player1 Name is: " << Player1.getUsername() << endl;
    cout << "Player1 Level is: " << Player1.getLevel() << endl;
    cout << "Player1 Money is: " << Player1.getTotalMoney() << endl;
    cout << "Player1 Score is: " << Player1.getTotalScore() << endl;

    Player Player2;

    //Testing Other Player Functions
    Player2.setUsername("Jimmy");
    Player2.setLevel(100);
    Player2.setTotalMoney(1000);
    Player2.setTotalScore(1000);

    //Testing Other Player Functions
    cout << "Player2 Name is: " << Player2.getUsername() << endl;
    cout << "Player2 Level is: " << Player2.getLevel() << endl;
    cout << "Player2 Money is: " << Player2.getTotalMoney() << endl;
    cout << "Player2 Score is: " << Player2.getTotalScore() << endl;

    Player2.setLevelMoney(100);
    Player2.setLevelMoney(100);

    //Testing Reset Functions
    Player2.resetLevelMoney();
    Player2.restLevelScore();

    cout << "Player2 level score is: " << Player2.getLevelScore() << endl;
    cout << "Player2 level money is: " << Player2.getLevelMoney() << endl;


//testing map class

    Map map;
    cout << "Initial map: " << endl;
    map.displayMap(); // starting point
    cout << "Default constructor: " << endl;
    cout << "Room #: " << map.getRoomCount() << endl;
    cout << "Let's add some rooms: " << endl;
    assert(map.addRoom(2, 3));
    assert(map.addRoom(8, 5));
    assert(map.addRoom(2, 7));
    //assert(map.addRoom(8, 2));
    assert(!map.addRoom(15, 15)); // should not show on map nor error out, out of bounds
    assert(!map.addRoom(2, 3));   // will not do anything since space is occupied
    //assert(map.addRoom(5, 7));
    assert(!map.addRoom(3, 7)); // will fail due to exceeding max_rooms_
    map.displayMap();
    cout << "Spawning some NPCs: " << endl;
    assert(map.addNPC(4, 4));
    assert(map.addNPC(1, 2));
    assert(map.addNPC(7, 2));
    assert(map.addNPC(10, 4));
    assert(!map.addNPC(2, 7)); // should fail due to space being occupied
    assert(map.addNPC(9, 0));
    assert(!map.addNPC(10, 0)); // should fail due to max number of NPCs == 5
    map.displayMap();
    cout << "Let's move a little. First, down:" << endl;
    map.move('s'); // go down
    map.displayMap();
    cout << "Now, right:" << endl;
    map.move('d'); // go right
    map.displayMap();
    cout << "On an NPC space? ..." << map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()) << endl;
    cout << "Moving onto an NPC space that was previously hidden:" << endl;
    map.move('d'); // go right
    map.displayMap();
    cout << "On NPC space now?..." << map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()) << endl;
    cout << "Let's move off it, should be updated as visible:" << endl;
    map.move('d'); // go right
    map.displayMap();
    cout << "On room right now?..." << map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()) << endl;
    cout << "Okay, let's move onto the room:" << endl;
    map.move('s');
    map.displayMap();
    cout << "On room right now? " << map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()) << endl;
    cout << "... and move left off" << endl;
    map.move('a');
    map.displayMap();
    cout << "Let's remove that room" << endl;
    assert(map.removeRoom(2, 3));
    map.displayMap();
    cout << "Let's explore the current space, then move down." << endl;
    map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
    map.move('s');
    map.displayMap();
    return 0;

}
