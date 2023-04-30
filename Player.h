#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "Food.h"
#include "Weapon.h"
#include "Armor.h"

using namespace std;

class Player
{
    private:

        int levels_cleared; //number of levels cleared by player

        Weapon curr_weapon;     //current weapon of player
        Armor curr_armor;       //current armor of player
        vector<Food> food_inv;  //food inventory of player
        string username;        //The name of the player
        int level_score;        //The score that the user has at a specific level
        int total_score;        //The total score of the specific user
        int level_money;        //How much money has been earned in a specific level
        int total_money;        //Amount of user money
        int total_level;        //The level of the user as decided by algorithim
        int health;             //health of the player

    public:

        Player(); //Default Constructor

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

        //getters and setters for weapons and armor
        Weapon getCurrWeapon();
        Armor getCurrArmor();
        void setCurrWeapon(Weapon weapon);
        void setCurrArmor(Armor armor);

        //getters and setters for food
        Food getFood(int index);
        void addFood(Food food);
        void printFoodInv(vector<Food> vect);
        vector<Food> getFoodInv();
        void removeFood(int index);
        void removeAllFood();

        //getters and setters for health
        int getHealth();
        void setHealth(int health);
        void removeHealth(int remove_health);

};
#endif
