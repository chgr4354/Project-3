#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cassert>
#include "Players.h"
using namespace std;

int main()
{
    //Testing Default Constructor
    Player Player1 = Player();

    //Testing Default Constructor
    cout << "Player1 Name is: " << Player1.getUsername() << endl;
    cout << "Player1 Level is: " << Player1.getLevel() << endl;
    cout << "Player1 Money is: " << Player1.getTotalMoney() << endl;
    cout << "Player1 Score is: " << Player1.getTotalScore() << endl;

    Player Player2 = Player();

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


}
