#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cassert>
using namespace std;

//How a Player May Look

//Username
//Score
//Money
//Level


class Player
{
    private:

        string username; //The name of the user
        
        //Score Counters
        int level_score; //The score that the user has at a specific level
        int total_score; //The total score of the specific user

        //Money Counters
        int level_money; //How much money has been earned in a specific level
        int total_money; //Amount of user money

        //Level Counters
        int levels_done; //How many levels have been completed by user
        int total_level; //The level of the user as decided by algorithim

    public:

        //Default Constructor
        Player();

        //Setters and Getters for username
        void setUsername(string set_username);
        string getUsername();

        //Setters and Getters for Level Score
        void setLevelScore(int level_score);
        int getLevelScore();

        //Setters and Getters for Total Score
        void setTotalScore(int score);
        int getTotalScore();

        //Setters and Getters for Level Money
        void setLevelMoney(int money);
        int getLevelMoney();

        //Setters and Getters for Total Money
        void setTotalMoney(int money);
        int getTotalMoney();

        //Setters and Getters for Level
        void setLevel(int level);
        int getLevel();
};
