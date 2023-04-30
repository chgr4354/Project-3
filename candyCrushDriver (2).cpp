#include <cassert>
#include "candyCrush.h"
#include "candy.h"

int main() {
    srand(time(0));

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

    testRemoveMatches.generateCandy();
    testRemoveMatches.displayBoard();
    cout << "\n\n";
    candyCrush1.generateCandy();
    candyCrush1.displayBoard();
    cout << "\ncandyCrush1 board score: "<< candyCrush1.getScore();
    cout << "\ntestRemoveMatches board score: "<< testRemoveMatches.getScore() << "\n\n";
    assert(candyCrush1.getScore() == 13);
    assert(testRemoveMatches.getScore() == 100);

}