#include "Player.h"

using namespace std;

//Sets Default Values for Player Object
Player::Player() {

    Weapon default_weapon;
    Armor default_armor;
    curr_weapon = default_weapon;
    curr_armor = default_armor;
    username = "";
    level_score = 0;
    total_score = 0;
    level_money = 0;
    total_money = 500;
    total_level = 0; //Player Level
    health = 100;
    levels_cleared = 0;

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
//Sets the total player score
void Player::setTotalScore(int score)
{
    total_score = score;
}
//Adds to total player score
void Player::addTotalScore(int score)
{
    total_score += score;
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
    return level_score;
}
//Gets the players total Score
int Player::getTotalScore()
{
    return total_score;
}
//Sets amount of money gained from a specific level
void Player::setLevelMoney(int new_level_money)
{
    level_money = new_level_money;
}
//Gets specific money from level
int Player::getLevelMoney()
{
    return level_money;
}
//Resets Money Gained from level
void Player::resetLevelMoney()
{
    level_money = 0;
} 
//Sets the total amount of money a player has
void Player::setTotalMoney(int money)
{
    total_money = money;
}
//Adds money to total money a player has
void Player::addTotalMoney(int money)
{
    total_money += money;
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

//gets number of levels a player has cleared
int Player::getLevelsCleared() {
    return levels_cleared;
}
//increases the levels cleared by player
void Player::increaseLevelsCleared() {
    levels_cleared++;
}

//getters
Weapon Player::getCurrWeapon() { //get player's current weapon
    return curr_weapon;
}
Armor Player::getCurrArmor() { //get player's current armor
    return curr_armor;
}
vector<Food> Player::getFoodInv() { //get player's food inventory
    return food_inv;
}
Food Player::getFood(int index) { //get food from food inventory
    return food_inv.at(index);
}
void Player::addFood(Food food) { //add food to food inventory
    food_inv.push_back(food);
}
void Player::printFoodInv(vector<Food> vect) { //print the player's food inventory
    if(!vect.empty()) { //check if inventory is empty
        for(int i = 0; i < vect.size(); i++) { //loop through food inventory and print out the food item
            cout << vect.at(i).getName() << ": " << vect.at(i).getRecover() << "HP | ";
        }
    }
    else //food inventory is empty
        cout << "You have no food";
}

//setters
void Player::setCurrWeapon(Weapon weapon) { //set player's current weapon
    curr_weapon = weapon;
}
void Player::setCurrArmor(Armor armor) { //set player's current armor
    curr_armor = armor;
}



int Player::getHealth() { //get player's health
    return health;
}
void Player::setHealth(int new_health) { //set player's health
    health = new_health;
}
void Player::removeHealth(int remove_health) { //remove health from player
    health -= remove_health;
}

void Player::removeAllFood() { //remove all food from player's inventory
    food_inv.clear();
}

void Player::removeFood(int index) { //remove food from player's inventory
    food_inv.erase(food_inv.begin() + index - 1);
}
