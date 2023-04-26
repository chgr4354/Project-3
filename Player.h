#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "Food.h"
#include "Weapon.h"
#include "Armor.h"

using namespace std;

//How a Player May Look

//Username
//Score
//Money
//Level
//Hunger

class Player
{
    private:

        int levels_cleared;

        Weapon curr_weapon;
        Armor curr_armor;
        vector<Food> food_inv;
        string username; //The name of the player
        
        //Score Counters
        int level_score; //The score that the user has at a specific level
        int total_score; //The total score of the specific user

        //Money Counters
        int level_money; //How much money has been earned in a specific level
        int total_money; //Amount of user money

        //Level Counters
        int total_level; //The level of the user as decided by algorithim

        int health;

    public:

        //Default Constructor
        Player();

        //Setters and Getters for username
        void setUsername(string set_username);
        string getUsername();

        //Setters and Getters for Level Score
        void setLevelScore(int level_score);
        int getLevelScore();
        void restLevelScore(); 

        //Setters and Getters for Total Score
        void setTotalScore(int score);
        int getTotalScore();
        void addTotalScore(int score);

        //Setters and Getters for Level Money
        void setLevelMoney(int money);
        int getLevelMoney();
        void resetLevelMoney();

        //Setters and Getters for Total Money
        void setTotalMoney(int money);
        int getTotalMoney();
        void addTotalMoney(int money);

        //Setters and Getters for Level
        void setLevel(int level);
        int getLevel();

        int getLevelsCleared();
        void increaseLevelsCleared();

        //getters for weapons and armor
        Weapon getCurrWeapon();
        //inspect weapon option in main()
        Armor getCurrArmor();
        void setCurrWeapon(Weapon weapon);
        void setCurrArmor(Armor armor);

        Food getFood(int index);
        void addFood(Food food);
        void printFoodInv(vector<Food> vect);
        vector<Food> getFoodInv();

        int getHealth();
        void setHealth(int health);

        void removeFood(int index);
        void removeAllFood(Player &player);

};
#endif
