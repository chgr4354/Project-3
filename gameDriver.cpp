#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include "Player.h"
#include "Monster.h"
#include "vectorSplit.h"
using namespace std;

void printStats(Player player) {

    cout << "\033[1;33m"
            "+-------------+\n"
            "|    STATS    |\n"
            "+-------------+\n"
            "| Levels Cleared: 1 | Keys: 0 | Anger Level: 12\n"
            "+-------------+\n"
            "|  INVENTORY  |\n"
            "+-------------+\n"
            "|        Gold | 32\n"
            "|        Food | 15 kg\n"
            "|     Weapons | C: 1 | S: 2 | R: 1 | B: 0 | L: 1\n"
            "|       Armor | 4"
            "+-------------+\n"
            "|    SCORE    |\n"
            "+-------------+" << "\033[0m\n";

            //ITEMS: have a file with cool items that can affect the players stats - beneficial or misfortune

}

/*
    This function prints out every past score of the user and uses a sorting algorithim to
    determine which order to print them
*/

void printLeaderBoard(string leaderboard_file) {
    vector<string> leaderboard;
    int lb_count = 1;

    vectorSplit(leaderboard_file, '|', leaderboard);
    
//***implement sorting algorithm here***

    cout << "\033[1;33m" << "   ---LEADERBOARD---" << "\033[0m\n"; //used stackoverflow for colored text syntax
    for(int i = 0; i < leaderboard.size(); i++) {
        cout << lb_count << ") " << leaderboard[i] << " " << "\033[1;33m" << leaderboard[i+1] << "\033[0m\n";
        i++;
        lb_count++;
    }
}

/*
    This function will print an art composed of ascii values to add some depth to the expierience
    and exit the player
*/

void printAsciiArt(string filename) {
    ifstream ascii(filename);
    if(!ascii.fail()) {
        string line;
        while(getline(ascii, line)) {
            cout << line << endl;
        }
    }
    else
        cout << "ascii art could not be printed\n";
}

/*
    1. This function prints the story of Color Crush and explains the motivations for the characters actions
    2. Than there will be instructions printed on how exactly the game works and how to play it
*/
void printStory(string filename) { //**redundant?**
    ifstream story(filename);
    if(!story.fail()) {
        string line;
        while(getline(story, line)) {
            cout << line << endl;
        }
    }
    else
        cout << "story could not be opened\n";    

}

void fight(Player player, Monster monster) {



}
void printBattleOptions(Player player, Monster monster) {

}

int main() {

    string username; //player username
    string input;
    int difficulty = 0;

//START GAME =============================================================================

    printAsciiArt("start_game.txt");
    
    cout << "\033[1;33m" << "                                        [Y / N]" << "\033[0m\n" << endl;
    cin >> input;

    while(input != "Y" && input != "N") {
        cout << "Enter a valid input: " << endl;
        cin >> input;
    }
    if(input == "N")
        return 0;
    else if(input == "Y")
        system("clear"); //clear screen

//LEADER BOARD ===========================================================================

    printLeaderBoard("mockLeaderboard.txt");
    
//STORY / INSTRUCTIONS ===================================================================

    //printStory();

//GET USERNAME ===========================================================================

    bool chooseNameAgain = true;

    do {
        cout << "\nWhat is your name, adventurer?" << endl;
        cin >> username;
        cout << "\nDo you wish for, " << "\033[1;33m" << username <<"\033[0m" << ", to be your name?\n";
        cout << "[Y/N] ";
        cin >> input;

        while(input != "Y" && input != "N") {
            cout << "Enter a valid input: \n";
            cout << "[Y/N] ";
            cin >> input;
        }

        if(input == "Y") {
            system("clear");
            cout << "Hello, " << username << endl;
            sleep(2); //check with TA
            system("clear");
            chooseNameAgain = false;
        }
        else if(input == "N")
            chooseNameAgain = true;

    } while(chooseNameAgain);


//Ask for difficulty =====================================================================
    
    cout << "What difficulty would you like to pursue?\n\n";
    cout << "1: " << "\033[1;32m" << "EASY" << "\033[0m\n";
    cout << "2: " << "\033[1;31;33m" << "MODERATE" << "\033[0m\n";
    cout << "3: " << "\033[1;31m" << "EXACERBATED PAIN" << "\033[0m\n\n";
    cout << "[1/2/3] ";
    cin >> difficulty;
    while (difficulty != 1 && difficulty != 2 && difficulty != 3)
    {
        cout << "That is not a choice. Choose again immediately, you're wasting time!\n";
        cout << "[1/2/3] ";
        cin >> difficulty;
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
