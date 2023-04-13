#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cassert>
#include "Players.h"
using namespace std;
//Most Recent Players.cpp
//Sets Default Values for Player Object
Player::Player()
{
    //Player Username
    username = "";

    //Player Level Scores
    level_score = 0;
    total_score = 0;

    //Player Money
    level_money = 0;
    total_money = 0;
    
    //Player Level
    total_level = 0;
}
//This Sets users name
void Player::setUsername(string set_username)
{
    username = set_username;
}
//This gets the name
string Player::getUsername()
{
    return username;
}
//Sets the specific level score
void Player::setLevelScore(int set_level)
{
    level_score = set_level;
}
//Resets level_score
void Player::restLevelScore()
{
    level_score = 0;
} 
//Obtains Level Score
int Player::getLevelScore()
{
    return total_level;
}
//Sets amount of money gained from a specific level
void Player::setLevelMoney(int level_money)
{
    total_money = total_money + level_money;
}
//Gets specific money from level
int Player::getLevelMoney()
{
    return total_money;
}
//Resets Money Gained from level
void Player::resetLevelMoney()
{
    level_money = 0;
} 
//Sets the total amount of money a player has
void Player::setTotalMoney(int money)
{
    total_money = total_money + money;
}
//Gets how much money a player has at that moment
int Player::getTotalMoney()
{
    return total_money;
}
//Sets a players level based on how many levels a player has completed total
void Player::setLevel(int level_complete)
{
    total_level = total_level + level_complete;
}
//Gets player level at a given point
int Player::getLevel()
{
    return total_level;
}
 
