#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cassert>
#include "Players.h"
using namespace std;

/*
    This function prints out every past score of the user and uses a sorting algorithim to
    determine which order to print them
*/

void printLeaderBoard()
{

}

/*
    This function will print an art composed of ascii values to add some depth to the expierience
    and exit the player
*/

void printAsciiArt()
{

}

/*
    1. This function prints the story of Color Crush and explains the motivations for the characters actions
    2. Than there will be instructions printed on how exactly the game works and how to play it
*/
void printStory()
{

}

int main()
{
    //This is the username for the player
    string username = "";

    int difficulty = 0;

    cout << "Start Game" << endl;

    //Display Leader Board
    printLeaderBoard();
    
    //Some ascii art
    printAsciiArt();
    
    //Story or Summary
    //Instructions
    printStory();

    //Ask For Username
    cout << "What is your name adventurer?" << endl;
    cin >> username;

    //Ask for difficulty
    while (difficulty != 1 && difficulty != 2 && difficulty != 3)
    {
        cout << "Choice 1 is Easy" << endl;
        cout << "Choice 2 is Moderate" << endl;
        cout << "Choice 3 is Exacerbated Pain" << endl;
        cout << "What difficulty would you like to pursue?" << endl;

        cin >> difficulty;

        //Checks if difficulty is invalid
        if (difficulty > 3 || difficulty < 0)
        {
            cout << "That is not a choice, choose again immediately, your wasting Time!" << endl;
        }
    }


    //Go to speficic diffulty area
    //Higher Difficulties include more obstacles
    //Levels Designed By Us
    //Set Amount of Turns per level
    //For each difficulty objects go up and turns go down
    if (difficulty == 1)
    {

    }
    else if (difficulty == 2)
    {

    }
    else if (difficulty == 3)
    {

    }

}
