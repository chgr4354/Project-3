#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> //for spacing print statements - syntax obtained from stackexchange
#include <unistd.h> //for system and sleep functions - syntax obtained from stackexchange
#include <limits> //for correct input checking - syntax obtained from stackexchange
#include "Map.h"
#include "candyCrush.h"
#include "Player.h"
#include "Monster.h"
#include "Merchant.h"
#include "vectorSplit.h"

//ascii art from https://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20 unless otherwise noted

//up-to-date compile command
//g++ gameDriver.cpp Player.cpp Weapon.cpp Food.cpp Armor.cpp Merchant.cpp vectorSplit.cpp Map.cpp candy.cpp candyCrush.cpp Room.cpp Monster.cpp

using namespace std;

/*
 * Algorithm: Handles trading interface of Merchant
 * clear screen
 * print trading UI by reading from files passed into Merchant
 * player can buy weapons, armor, food or quit (menu requirements combined here and in monster fight menu)
 * player chooses options, then merchant's inventory, player's inventory are updated
 * Parameters: reference to Merchant, reference to Player
 * Return: nothing (void)
 */
void trade(Merchant &merchant, Player &player) {
    system("clear");
    string input;
    int choice;
    bool itemBought = false;
    bool cancelOrder = false;
    bool leaveShop = false;

    //print storefront
    cout << "==================================================================\n"
            "|                    \033[1;31mJared's Culinary Crusade\033[0m                    |\n"
            "==================================================================\n"
            "|                                                                |\n"
            "|          /| ___________________                                |\n"
            "|   [IIIII]|[ ][ ][ ][ ][ ][ ][ ][]>                             |\n"
            "|          ||                                                    |\n"
            "|                                                                |\n"
            "|  |____>===[_|_|_|_|_|_|_|_|_|====================-             |\n"
            "|   |__/   ' ' ' ' ' ' ' ' ' '                                   |\n"
            "|                                                                |\n"
            "==============================\033[1;33mWeapons\033[0m=============================\n"
            "|                                                                |\n";
        for (int i = 0; i < merchant.getWeaponInv().size(); i++) {
            if(i == 5) { //this limits the amount of items displayed
                break;
            }
    cout << "|    " << left << i+1 << ". " << setw(39) << merchant.getWeapon(i).getName()
         << "G-" << setw(4) << merchant.getWeapon(i).getCost() << " (Dmg: "
         << merchant.getWeapon(i).getDamage() << ")  |\n";
        }
    cout << "|                                                                |\n"
            "===============================\033[1;33mArmor\033[0m==============================\n"
            "|                                                                |\n";
        for (int i = 0; i < merchant.getArmorInv().size(); i++) {
            if(i == 5) {
                break;
            }
    cout << "|    " << left << i+1 << ". " << setw(39) << merchant.getArmor(i).getName()
         << "G-" << setw(4) << merchant.getArmor(i).getCost() << " (prot: "
         << merchant.getArmor(i).getProtection()<< ") |\n";
        }
    cout << "|                                                                |\n"
            "===============================\033[1;33mFood\033[0m===============================\n"
            "|                                                                |\n";
        for (int i = 0; i < merchant.getFoodInv().size(); i++) {
            if(i == 5) {
                break;
            }
    cout << "|    " << left << i+1 << ". " << setw(30) << merchant.getFood(i).getName()
         << "G-" << setw(7) << merchant.getFood(i).getCost() << " (Recovery: "
         << merchant.getFood(i).getRecover()<< ")   |\n";
        }
    cout << "|                                                                |\n"
            "=============================\033[1;33mInventory\033[0m============================\n"
            "|\n"
            "|  \033[1;33mGold\033[0m: " << left << setw(7) << player.getTotalMoney() << "\n"
            "|  Food:  "; player.printFoodInv(player.getFoodInv()); cout << "\n"
            "|  Weapon: \033[1;31m" << player.getCurrWeapon().getName() << "\033[0m (Dmg: " << player.getCurrWeapon().getDamage() << ")\n"
            "|  Armor: \033[1;31m" << player.getCurrArmor().getName() << "\033[0m (Prot: " << player.getCurrArmor().getProtection() << ")\n"
            "|\n"
            "==================================================================\n"
            "|                                                                |\n"
            "|  Type the item number to purchase, or \033[1;31m'Q' to leave shop.\033[0m       |\n"
            "|                                                                |\n"
            "==================================================================\n";


    do {
        cout << "Hello, " << player.getUsername() << ", welcome to "<<"\033[1;31m"<<"Jared's Culinary Crusade"<<"\033[0m"<<"! Weapons, armor, and food from the four corners of the world\n"
                    "What would you like to buy?\n\n"
                    "[(\033[1;31mW\033[0m)eapons/(\033[1;31mA\033[0m)rmor/(\033[1;31mF\033[0m)ood]: ";
        cin >> input;

        while(input.substr(0,1) != "W" && input.substr(0,1) != "A" && input.substr(0,1) != "F" && input.substr(0,1) != "Q") {
            cout << "I'm not sure I understand your request... \n";
            cout << "[(\033[1;31mW\033[0m)eapons/(\033[1;31mA\033[0m)rmor/(\033[1;31mF\033[0m)ood]: ";
            cin >> input;
        }

// BUY WEAPONS =================================================================================================================================================

        if(input.substr(0,1) == "W") {
            while(itemBought == false && cancelOrder == false) {
                cout << "\nWhich weapon would you like, " << player.getUsername() << "?\n";
                while (true) {
                    cin >> choice;
                    if (cin.fail() || choice < 1 || choice > 5) {
                        cout << "I'm not sure I understand your request...\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        //used stackechange to get cin functions, and functions from <limit> library
                        //This was necessary to stop infinite loop from occurring when string is inputted
                    }
                    else {
                        break;
                    }
                }
                Weapon weapon_choice = merchant.getWeapon(choice-1);

                cout << "Ah, the \033[1;31m" << weapon_choice.getName() << "\033[0m. An excellent choice surely.\n\n";
                cout << weapon_choice.getStory() << "\n\n";

                if(weapon_choice.getCost() <= player.getTotalMoney()) { //check if player has enough money, then confirm order
                    cout << "Would you like to buy the \033[1;31m"<< weapon_choice.getName() <<"\033[0m for \033[1;33m$" << weapon_choice.getCost() << "\033[0m?\n";
                    cout << "[Y/N]: ";
                    cin >> input;
                    while(input != "Y" && input != "N") {
                        cout << "I'm not sure I understand your request... \n";
                        cin >> input;
                    }
                    if(input == "Y") { 
                        cout << "Thank you for your patronage! ";
                        player.setCurrWeapon(weapon_choice);
                        player.setTotalMoney(player.getTotalMoney() - weapon_choice.getCost());
                        merchant.removeWeapon(choice-1);
                        itemBought = true;
                    }
                    else if(input == "N") {
                        cout << "Of course, " << player.getUsername() << ". ";
                        cancelOrder = true;
                    }
                }
                else {
                    cout << "However, you do not have enough money to buy the \033[1;31m" << weapon_choice.getName() << "\033[0m.\nWould you like to pick another weapon?\n";
                    cout << "[Y/N]: ";
                    cin >> input;
                    while(input != "Y" && input != "N") {
                        cout << "I'm not sure I understand your request... \n";
                        cin >> input;
                    }
                    if(input == "Y") { //Do not update shop and offer another weapon item
                        continue;
                    }
                    else if(input == "N") {
                        cancelOrder = true;
                    }
                }
            }
        }

// BUY ARMOR =================================================================================================================================================

        else if(input.substr(0,1) == "A") {
            while(itemBought == false && cancelOrder == false) {
                cout << "\nWhich armor set would you like, " << player.getUsername() << "?\n";
                while (true) {
                    cin >> choice;
                    if (cin.fail() || choice < 1 || choice > 5) {
                        cout << "I'm not sure I understand your request...\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    else {
                        break;
                    }
                }
                Armor armor_choice = merchant.getArmor(choice-1);

                cout << "Ah, the " << armor_choice.getName() << ". An excellent choice surely.\n\n";
                cout << armor_choice.getStory() << endl;

                if(armor_choice.getCost() <= player.getTotalMoney()) { //check if player has enough money, then confirm order
                    cout << "Would you like to buy the " << armor_choice.getName() << " for \033[1;33m$" << armor_choice.getCost() << "\033[0m?\n";
                    cout << "[Y/N]: ";
                    cin >> input;
                    while(input != "Y" && input != "N") {
                        cout << "I'm not sure I understand your request... \n";
                        cin >> input;
                    }
                    if(input == "Y") { 
                        cout << "Thank you for your patronage! ";
                        player.setCurrArmor(armor_choice);
                        player.setTotalMoney(player.getTotalMoney() - armor_choice.getCost());
                        merchant.removeArmor(choice-1);
                        itemBought = true;
                    }
                    else if(input == "N") {
                        cout << "Of course, " << player.getUsername() << ". ";
                        cancelOrder = true;
                    }
                }
                else {
                    cout << "However, you do not have enough money to buy the " << armor_choice.getName() << ".\nWould you like to pick another set of armor?\n";
                    cout << "[Y/N]: ";
                    cin >> input;
                    while(input != "Y" && input != "N") {
                        cout << "I'm not sure I understand your request... \n";
                        cin >> input;
                    }
                    if(input == "Y") { //Do not update shop and offer another armor item 
                        continue;
                    }
                    else if(input == "N") {
                        cancelOrder = true;
                    }
                }
            }
        }
// BUY FOOD =================================================================================================================================================
        else if(input.substr(0,1) == "F") {
            while(itemBought == false && cancelOrder == false) {
                cout << "\nWhat food would you like, " << player.getUsername() << "?\n";
                while (true) {
                    cin >> choice;
                    if (cin.fail() || choice < 1 || choice > 5) {
                        cout << "I'm not sure I understand your request...\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    else {
                        break;
                    }
                }
                Food food_choice = merchant.getFood(choice-1);

                cout << "Ah, the " << food_choice.getName() << ". An excellent choice surely.\n\n";

                if(food_choice.getCost() <= player.getTotalMoney()) { //check if player has enough money, then confirm order
                    cout << "Would you like to buy, "<< food_choice.getName() << ", for \033[1;33m$" << food_choice.getCost() << "\033[0m?\n";
                    cout << "[Y/N]: ";
                    cin >> input;
                    while(input != "Y" && input != "N") {
                        cout << "I'm not sure I understand your request... \n";
                        cin >> input;
                    }
                    if(input == "Y") { 
                        cout << "Thank you for your patronage! ";
                        player.addFood(food_choice);
                        player.setTotalMoney(player.getTotalMoney() - food_choice.getCost());
                        merchant.removeFood(choice-1);
                        itemBought = true;
                    }
                    else if(input == "N") {
                        cout << "Of course, " << player.getUsername() << ". ";
                        sleep(1);
                        cancelOrder = true;
                    }
                }
                else {
                    cout << "However, you do not have enough money to buy " << food_choice.getName() << ".\nWould you like to pick another food item?\n";
                    cout << "[Y/N]: ";
                    cin >> input;
                    while(input != "Y" && input != "N") {
                        cout << "I'm not sure I understand your request... \n";
                        cin >> input;
                    }
                    if(input == "Y") { //Do not update shop and offer another food item
                        continue;
                    }
                    else if(input == "N") {
                        cancelOrder = true;
                    }
                }
            }
        }
        else if(input.substr(0,1) == "Q") {
            leaveShop = true;
        }
    
        cout << "Would you like to pick another item to buy?\n"; //****change so this dialogue is skipped if Q is entered****
        cout << "[Y/N]: ";
        cin >> input;
        while(input != "Y" && input != "N") {
            cout << "I'm not sure I understand your request... \n";
            cin >> input;
        }
        if(input == "Y") {
            trade(merchant, player);
        }
        else if(input == "N") {
            cout << "Do you really want to leave my shop so soon?\n";
            cout << "[Y/N]: ";
            cin >> input;
            while(input != "Y" && input != "N") {
                cout << "I'm not sure I understand your request... \n";
                cin >> input;
            }
            if(input == "N") {
                cout << "Ah, wonderful!\n";
                sleep(1);
                trade(merchant, player);
            }
        }

    leaveShop = true;
    
    }while(!leaveShop);

}

/*
 * Algorithm: prints player statistics
 * print player's stats by calling player member functions
 * Parameters: player (Player)
 * Return: nothing (void)
 */
void printStats(Player player) {

cout << "\033[1;33m\
+---------------+ \n\
|     STATS     |\n\
+---------------+\n\
| Levels Cleared: " << player.getLevelsCleared() << "\n\
|    Total Score: " << player.getTotalScore() << "\n\
+---------------+\n\
|   INVENTORY   |\n\
+---------------+\n\
|          Gold | " << player.getTotalMoney() << "\n\
|          Food | "; player.printFoodInv(player.getFoodInv()); cout << "\n\
|        Weapon | " << player.getCurrWeapon().getName() << "\n\
|         Armor | " << player.getCurrArmor().getName() << "\n\
+---------------+ \033[0m\n\n";

}

/*
 * Algorithm: Prints out sorted leaderboard of previous attempts at game
 * call vectorsplit function and pass file items into new leaderboard vector
 * sort leaderboard vector using bubble sort
 * Parameters: leaderboard_file (string)
 * Return: nothing (void)
 */
void printLeaderBoard(string leaderboard_file) {
    vector<string> leaderboard;
    int count = 1; //numbering for output

    vectorSplit(leaderboard_file, '|', leaderboard); //save file data to leaderboard vector
    
//bubble sort algorithm:
//sort leaderboard vector 
    if(!leaderboard.empty()) {
        for(int i = 0; i < leaderboard.size(); i++) {
            for(int j = 1; j < leaderboard.size() - i - 1; j+=2) {
                if(stoi(leaderboard[j]) < stoi(leaderboard[j+2])) {
                    //swap scores
                    string tempScore = leaderboard[j];
                    leaderboard[j] = leaderboard[j+2];
                    leaderboard[j+2] = tempScore; 

                    //swap names
                    string tempName = leaderboard[j-1];
                    leaderboard[j-1] = leaderboard[j+1];
                    leaderboard[j+1] = tempName;
                }
            }
        }
    }

//print leaderboard vector
    cout << "\033[1;33m" << "---LEADERBOARD---" << "\033[0m\n"; //used stackoverflow for colored text syntax
    for(int i = 0; i < leaderboard.size(); i+=2) {
        cout << right << setw(4) << count << ". " << left << setw(25) << leaderboard[i] << " " << setw(3) << "\033[1;33m" << leaderboard[i+1] << "\033[0m\n";
        count++;
    }
}

/*
 * Algorithm: writes player's score and username to leaderboard file
 * create ofstream object using leaderboard_file and append mode
 * add data to file if file can be opened
 * Parameters: leaderboard_file (string), player (Player)
 * Return: nothing (void)
 */
void writeToLeaderboard(string leaderboard_file, Player player) {
    ofstream leaderboard(leaderboard_file, ios::app); //ios::app opens the file in append mode, which will add new data to end of file - syntax from stackexchange

    if(!leaderboard.fail()) {
        int player_score = player.getTotalScore();
        string player_name = player.getUsername();
        leaderboard << "\n" << player_name << "|" << player_score;
    }
    
    else {
        cout << "leaderboard file, \"" << leaderboard_file << "\" could not be opened";
    }
    leaderboard.close();

}

/*
 * Algorithm: prints ascii art to console
 * pass in filename to ifstream object
 * read data from file if file can be opened
 * print out each line from file to console
 * Parameters: filename (string)
 * Return: nothing (void)
 */
void printAsciiArt(string filename) {
    ifstream ascii(filename);
    if(!ascii.fail()) { //check file can be opened
        string line;
        while(getline(ascii, line)) { //print each line from file
            cout << line << endl;
        }
    }
    else
        cout << "\"" << filename << "\" could not be printed\n";
}

/*
 * Algorithm: handles fight between player and monster after each candyCrush level
 * reset player health
 * print battle start sequence
 * while battle is not over
 * check if player is dead
 * print battle UI
 * player chooses option and stats are updated accordingly
 * game ends if player dies
 * player continues to next level if they defeat the monster
 * Parameters: reference to player, reference to monster
 * Return: int
 */
int fight(Player &player, Monster &monster) { //returns int to make it easy to add alternate endings

    player.setHealth(100);

    int num_turns = 0; //used to calculate player's score at end of battle
    int choice; //player's battle choice
    bool endBattle = false;
    int randNum;

    string player_weapon = player.getCurrWeapon().getName(); //name of player's weapon
    string player_armor = player.getCurrArmor().getName(); //name of player's armor
    const int player_max_health = 100;  
    const int monster_max_health = monster.getHealth();

//Initialize battle
    system("clear");
    cout << "Watch out! It looks like \033[1;31m" << monster.getName() << "\033[0m has appeared!\n";
    sleep(2);
    cout << "\033[1;34m";
    printAsciiArt("battle_start.txt");
    cout << "\033[0m";
    cout << "\033[1;31m";
    printAsciiArt("monster_battle.txt"); //credit - https://www.asciiart.eu/video-games/pokemon
    cout << "\033[0m\n";
    cout << "\033[1;33m";
    for(int i = 0; i < 75; i++) {
        cout << "#";
        cout.flush(); //from cpluplus.com forum
        usleep(50000); //uses microseconds instead of seconds to make a really cool bar
    }
    cout << "\033[0m";

    while(!endBattle) { //keep looping until player or monster dies
        int randNum = rand() % 3 + 1;

        //stats
        int player_protection = player.getCurrArmor().getProtection();
        int player_num_hashtags = static_cast<int>((player.getHealth() / static_cast<double>(player_max_health)) * 25);
        int monster_num_hashtags = static_cast<int>((monster.getHealth() / static_cast<double>(monster_max_health)) * 25);


        system("clear");
        num_turns++;

        //check if player is dead
        if(player.getHealth() <= 0) {
            cout << "You were killed by " << monster.getName() << "! You lasted " << num_turns << " turns against the monster.\n";
            return -1; //player killed
        }

        //print battle UI
        cout << ".----------------------------------------------------.\n"
                "|                   BATTLE MENU                      |\n"
                "|----------------------------------------------------|\n"
                "| \033[1;33m" << left << setw(25) << monster.getName() +"'s Health:\033[0m [\033[1;31m";
            for (int i = 0; i < monster_num_hashtags; i++) { //monster healthbar
                cout << "#";
            }
            for (int i = monster_num_hashtags; i < 25; i++) {
                cout << " ";
            }
        cout << "\033[0m]\n"
                "|----------------------------------------------------|\n"
                "|                \033[1;33m" << setw(25) << player.getUsername() + "'s STATS" << "\033[0m           |\n"
                "|----------------------------------------------------|\n"
                "| Health:    " << right << setw(3) << player.getHealth() << "/" << player_max_health << "     "; 
        cout << "[\033[1;31m";
            for (int i = 0; i < player_num_hashtags; i++) { //player healthbar
                cout << "#";
            }
            for (int i = player_num_hashtags; i < 25; i++) {
                cout << " ";
            }
        cout << "\033[0m]\n"
                "|\n"
                "| Weapon:  " << player_weapon << "  [DMG: " << player.getCurrWeapon().getDamage() << "]\n"
                "|\n"
                "| Armor:  " << player_armor << "  [PROT: " << player.getCurrArmor().getProtection() << "]\n"
                "|\n"
                "| Food: "; player.printFoodInv(player.getFoodInv());
        cout << "\n|----------------------------------------------------|\n"
                "| [1] Attack                 [4] Special Attack      |\n"
                "| [2] Block                  [5] Run Away            |\n"
                "| [3] Consume food                                   |\n";        
        cout << "|----------------------------------------------------|\n"
                "|                \033[1;34mTurn Number: " << setw(3) << num_turns << "\033[0m                    |\n"
                "'----------------------------------------------------'\n\n";
        
        
        cout << "What would you like to do?\n[1-5]: ";
            while (true) {
                cin >> choice;
                if (cin.fail() || choice < 1 || choice > 5) {
                    cout << "Enter a valid choice [1-5]: \n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else {
                    break;
                }
            }
        
        if(choice == 1) { //attack
            cout << "You attack " << monster.getName() << " with the " << player_weapon << endl;
            monster.setHealth(monster.getHealth() - player.getCurrWeapon().getDamage()); //update monster health
            sleep(2);
            cout << "You dealt " << player.getCurrWeapon().getDamage() << " points of damage!\n";
            sleep(2);
            if(monster.getHealth() <= 0) { //monster dies
                cout << "Your attack was fatal! " << monster.getName() << " was defeated in " << num_turns << " turns\n";
                sleep(3);
                endBattle = true;
                return num_turns; //player continues to next level
            }
            cout << monster.getName() << " attacked you and did " << (monster.getDamage() - monster.getDamage() * (static_cast<double>(player_protection) / 100.0)) << "pts of damage!\n";
            player.removeHealth(monster.getDamage() - monster.getDamage() * (static_cast<double>(player_protection) / 100.0)); //update player health
            sleep(4);
        }
        else if(choice == 2) { //block //random menu requirement 1
            cout << "You choose to block " << monster.getName() << "'s incoming attack!\n"; 
            sleep(2);
            randNum = rand() % 10;
            //50% chance of player blocking attack
            if(randNum >= 5) {
                cout << "You blocked the attack!\n";
                sleep(2);
                continue;
            }
            else {
                cout << "You failed to block the attack!\n";
            }
            cout << monster.getName() << " attacked you and did " << (monster.getDamage() - monster.getDamage() * (static_cast<double>(player_protection) / 100.0)) << "pts of damage!\n";
            player.removeHealth(monster.getDamage() - monster.getDamage() * (static_cast<double>(player_protection) / 100.0)); //update player health
            sleep(4);
        }
        else if(choice == 3) //Consume food
        {
            int food_choice = 0; 

            cout << "You chose to consume\n";
            sleep(1);
            if(!player.getFoodInv().empty()) { //check that player's food inventory is not empty (do not increment turns if empty)
                for (int i = 0; i < player.getFoodInv().size(); i++) { //print out food inventory
                    cout << "" << left << i+1 << ". " << setw(20) << player.getFood(i).getName()
                        << " (Recovery: " << player.getFood(i).getRecover()<< ")\n";
                }
                cout << "Which food would you like to eat?\n";
                    while (true) {
                        cin >> food_choice;
                        if (cin.fail() || food_choice < 1 || food_choice > player.getFoodInv().size()) {
                            cout << "Enter a valid choice: \n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        else {
                            break;
                        }
                    }
                Food food = player.getFood(food_choice-1);
                cout << "You chose " << food.getName() << endl;
                sleep(1);
                cout << "You have gained " << food.getRecover() << " health!\n";
                sleep(2);
                player.setHealth(player.getHealth() + food.getRecover()); //update player health
                cout << "food_choice: " << food_choice << endl;
                cout << "food_choice-1: " << food_choice-1 << endl;
                player.removeFood(food_choice); //remove food from player's inventory
            }
            else {
                cout << "You have no food in your inventory!\n";
                num_turns--; //do not increment turns in this case
                sleep(2);
            }
            cout << monster.getName() << " attacked you and did " << (monster.getDamage() - monster.getDamage() * (static_cast<double>(player_protection) / 100.0)) << "pts of damage!\n";
            player.removeHealth(monster.getDamage() - monster.getDamage() * (static_cast<double>(player_protection) / 100.0)); //update player health
            sleep(4);
        }
        else if(choice == 4) //Special Attack //random menu requirement 2
        {
            cout << "You use your special attack on " << monster.getName() << "!\n";
            monster.setHealth(monster.getHealth() - (player.getCurrWeapon().getDamage() * randNum)); //update monster health
            sleep(2);
            cout << "You did " << (player.getCurrWeapon().getDamage() * randNum) << " points of damage!\n";
            sleep(2);
            cout << "You also did " << (static_cast<double>(player.getCurrWeapon().getDamage()) / 2.0) << " against yourself...\n";
            player.removeHealth(static_cast<int>(static_cast<double>(player.getCurrWeapon().getDamage()) / 2.0)); //update player health

            if(monster.getHealth() <= 0) { //monster dies from attack
                cout << "Your attack was fatal! " << monster.getName() << " was defeated in " << num_turns << " turns\n";
                sleep(3);
                endBattle = true;
                return num_turns; //player continues game
            }
            cout << monster.getName() << " attacked you and did " << (monster.getDamage() - monster.getDamage() * (static_cast<double>(player_protection) / 100.0)) / 2.0 << "pts of damage!\n";
            player.removeHealth(monster.getDamage() - monster.getDamage() * (static_cast<double>(player_protection) / 100.0)); //update player health
            sleep(4);
        }
        else if(choice == 5) //run away 
        { 
            cout << "You decided to run away!\n";
            sleep(1);
            player.removeAllFood(); //if you run away the monster steals all your food
            cout << "As you were running away you left all of your food behind.\n";
            sleep(4);
            endBattle = true;
            return -2; //player continues game
        }
    }
    return 0; //base case
}

/*
 * Algorithm: handles player interactions with candy crush level
 * While player has not completed level or lost level
 * print candyCrush UI
 * check if player has more turns
 * if yes, prompt player to swap candies
 * swap candies and update the board and player's score
 * exit level when player has no more turns
 * exit game if player has no more turns and has not met level threshold
 * Parameters: reference to player, level_name (string), max_turns (const int), target_score (const int)
 * Return: int
 */
int playCandyCrush(Player &player, string level_name, const int max_turns, const int target_score) {
    int num_turns = 0;
    // max_turns sets turn limit for player
    // target_score sets minimum score threshold for player
    char row_input;
    int row = 0;
    int col_input = 0;
    string direction;
    string input;
    bool endGame = false;
    bool promptContinueGame = false; //do not ask player to continue each turn if they choose to continue playing for highscore

    candyCrush candy_crush(level_name); //initialize candyCrush object

    while(!endGame) {
        //initialize board and candyCrush/player stats
        system("clear");
        cout << " _________________________________________\n"
                "/ \\                                       \\ \n"
                "|o||              CANDY CRUSH              |\n"
                "\\_/| _____________________________________ |\n"
                "   |                                       |\n"
                "   |     \033[1;33mLEVEL " << left << player.getLevelsCleared()+1 << "\033[0m     SCORE: " << setw(15) << player.getLevelScore() << "|\n"
                "   | _____________________________________ |\n"
                "   |     ___________________               |\n"
                "   |    |  Swaps Left: " << setw(5) << max_turns - num_turns << "|              |\n"
                "   |    |___________________|              |\n"
                "   |    Minimum score to pass: \033[1;33m" << left << setw(3) << target_score << "\033[0m         |\n"
                "   |                                       |\n"
                "   |        ###  INSTRUCTIONS  ###         |\n"
                "   |                                       |\n"
                "   | - Swap adjacent candies to form lines |\n"
                "   |     of identical candies              |\n"
                "   |                                       |\n"
                "   | - Match candies to earn points        |\n"
                "   |                                       |\n"
                "   | - Reach the target score within the   |\n"
                "   |     given number of turns to pass     |\n"
                "   |                                       |\n"
                "    \\______________________________________/\n\n";
        candy_crush.displayBoard(); //print board to console

        if(num_turns == max_turns) { //player has no more turns and must continue to next level
            cout << "You have no more turns!\n";
            sleep(2);
            endGame = true;
            if(candy_crush.getScore() < target_score) { //player has no more turns and has not met score threshold
                player.addTotalScore(candy_crush.getScore()); //adds level score to total player score (total_score = total_score + level_score)
                player.setLevelScore(0); //reset level score when player exits level
                player.increaseLevelsCleared();
                return -2; //player does not reach target score and game ends
            }
            player.addTotalScore(candy_crush.getScore()); //adds level score to total player score
            player.setLevelScore(0); //reset level score when player exits level
            player.addTotalMoney(300); //give money to player for the next merchant encounter
            player.increaseLevelsCleared(); //increment levels cleared by player by one
            return -1; //player reaches target score and level ends; game continues
        }

//===begin prompting player========================================================
        cout << "Enter row [A-J]: ";
        cin >> row_input;
        row = int(row_input) - 65;
            while(row < 0  || row > 9 ) {
                cout << "Enter a valid row [A-J]: ";
                cin >> row_input;
                row = int(row_input) - 65;
            }
        cout << "Enter column [1-10]: ";
            while (true) {
                cin >> col_input;
                if (cin.fail() || col_input < 1 || col_input > 10) {
                    cout << "Enter a valid column [1-10]: \n";
                    cin.clear(); //clears error
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //syntax from stackexchange - ignores characters up to delimiter
                }
                else {
                    break;
                }
            }
        cout << "Direction [w/a/s/d]: ";
        cin >> direction;
            while(direction != "w" && direction != "a" && direction != "s" && direction != "d" && direction != "Q123") {
                cout << "Enter a valid direction [w/a/s/d]: ";
                cin >> direction;
            }
        if(direction == "w") { //swap candy with candy above
            if(candy_crush.swap(row, col_input, row-1, col_input)) { //only remove matching candies if swap returns true - swap returns true when candies are on the board and are modifiable
                candy_crush.removeMatches(candy_crush.getCandy(row-1, col_input).getColor(), row-1, col_input); //call remove matches on player's selected candy after it has been swapped
                candy_crush.removeMatches(candy_crush.getCandy(row, col_input).getColor(), row, col_input); // call remove matches on previous location of player's selected candy
                candy_crush.generateCandy(); //generate candies at every location that removeMatches has affected
                num_turns++; //increment number of turns
            }
        }
        else if (direction == "a") { //swap candy with candy to the left
            if(candy_crush.swap(row, col_input, row, col_input-1)) {
                candy_crush.removeMatches(candy_crush.getCandy(row, col_input-1).getColor(), row, col_input-1);
                candy_crush.removeMatches(candy_crush.getCandy(row, col_input).getColor(), row, col_input);
                candy_crush.generateCandy();
                num_turns++;
            }
        }
        else if(direction == "s") { //swap candy with candy below
            if(candy_crush.swap(row, col_input, row+1, col_input)) {
                candy_crush.removeMatches(candy_crush.getCandy(row+1, col_input).getColor(), row+1, col_input);
                candy_crush.removeMatches(candy_crush.getCandy(row, col_input).getColor(), row, col_input);
                candy_crush.generateCandy();
                num_turns++;
            }
        }
        else if(direction == "d") { //swap candy with candy to the right
            if(candy_crush.swap(row, col_input, row, col_input+1)) {
                candy_crush.removeMatches(candy_crush.getCandy(row, col_input+1).getColor(), row, col_input+1);
                candy_crush.removeMatches(candy_crush.getCandy(row, col_input).getColor(), row, col_input);
                candy_crush.generateCandy();
                num_turns++;
            }

        }
        else if(direction == "Q123") { //This can skip the level for testing purposes
            endGame = true;
            player.addTotalScore(candy_crush.getScore()); //adds level score to total player score
            player.setLevelScore(0); //reset level score when player exits level
            player.addTotalMoney(300);
            player.increaseLevelsCleared();
            return -3; //quitting level for testing other features
        }

        if(candy_crush.getScore() >= target_score && !promptContinueGame) { //player reaches target score and can choose to continue playing for higher score or continue game
            cout << "You have reached the target score for this level!\n";
            cout << "Would you like to keep playing for a higher score?\n[Y/N]: ";
            cin >> input;
                while(input != "Y" && input != "N") {
                    cout << "Enter a valid choice:  \n";
                    cin >> input;
                }
            if(input == "Y") { //player chooses to play for higher score
                cout << "Good luck!\n";
                sleep(1); 
                player.setLevelScore(candy_crush.getScore());
                promptContinueGame = true;
                continue;
            }
            else if(input == "N") { //player chooses to continue to monster fight
                cout << "You continue on your journey...\n";
                sleep(1.5);
                endGame = true;
                player.addTotalScore(candy_crush.getScore()); //adds level score to total player score
                player.setLevelScore(0); //reset level score when player exits level
                player.addTotalMoney(300);
                player.increaseLevelsCleared();
                return 1; //player finishes level after reaching target score
            }
        }

        player.setLevelScore(candy_crush.getScore()); //update player's level score

    }
    player.addTotalScore(candy_crush.getScore()); //adds level score to total player score
    player.setLevelScore(0); //reset level score when player exits level
    player.addTotalMoney(300);
    player.increaseLevelsCleared();

    return 0; //default return case

}

/*
 * Algorithm: check if player can enter candyCrush level
 * check if player is stepping on room
 * loop through vector of rooms created when addRoom() is called in main function
 * return true if player is stepping on a room in the vector
 * Parameters: map (Map), player (Player)
 * Return: bool
 */
bool enterLevel(Map map, Player player) { //check if player is able to enter the level
    if(map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol())) {
        for(int i = 0; i < map.getRoomCount(); i++) {
            if (map.getRoom(i).getRoomRow() == map.getPlayerRow() && map.getRoom(i).getRoomCol() == map.getPlayerCol()) {
                return true;
            }
        }
    }
    return false;
}

/*
 * Algorithm: returns level of the room that the player is stepping on
 * exactly the same as enterLevel(), but checks is player's level is high enough to enter room
 * returns room level if player's level is high enough, and returns -1 if not high enough
 * Parameters: map (Map), player (Player)
 * Return: int
 */
int roomLevel(Map map, Player player) { //return level of the room the player stepped on (maybe change enterLevel to return type int and get rid of this)
    if(map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol())) {
        for(int i = 0; i < map.getRoomCount(); i++) {
            if (map.getRoom(i).getRoomRow() == map.getPlayerRow() && map.getRoom(i).getRoomCol() == map.getPlayerCol()) {
                if (player.getLevelsCleared() == map.getRoom(i).getLevelNumber() - 1) {
                    return map.getRoom(i).getLevelNumber();
                }
                else {
                    return -1;
                }
            }
        }
    }
    return -1;
}


//main funciton handles order of operations for game
int main() {

    srand(time(NULL));

    Player player; //initialize player
    Merchant merchant; //initialize merchant
    Monster monster1; //initialize monsters for each of the three candyCrush levels
    Monster monster2;
    Monster monster3;
    string username; //player username
    string input; //user input
    char direction; //directin player chooses to move
    int difficulty = 0; //player's difficulty selection
    bool endGame = false; //determines if game should end
    string level_1; //names of candyCrush levels
    string level_2;
    string level_3;
    int max_turns = 0; //determines how many tries a player gets to complete a candycrush level
    int target_points = 0; //determines how many points a player needs to meet in order to pass a level
    int fight_return = 0; //records outcome of player's fight with monster (0 = default)
    int candy_return = 0; //records outcome of player's candy crush level
    int fight_score = 0; //calculates score player achieved from fighting monster

//START GAME =============================================================================

    printAsciiArt("start_game.txt");
    
    cout << "\033[1;33m" << "                                        [Y / N]" << "\033[0m\n" << endl;
    cin >> input;
        while(input != "Y" && input != "N") {
            cout << "Enter a valid input: " << endl;
            cin >> input;
        }
        if(input == "N") {
            return 0;
        }   
        else if(input == "Y") {
            system("clear"); //clear screen
        }

    system("clear");
    printLeaderBoard("leaderboard.txt");
    
//STORY / INSTRUCTIONS ===================================================================

    //this is where the story behind the game would be printed
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
        if(input == "Y") { //player confirms username
            system("clear");
            cout << "Hello, " <<"\033[1;33m"<< username <<"\033[0m"<< endl;
            sleep(1.5);
            system("clear");
            chooseNameAgain = false;
            player.setUsername(username);
        }
        else if(input == "N") { //player wants a different name
            chooseNameAgain = true;
        }

    } while(chooseNameAgain);

//Ask for difficulty =====================================================================
    
    cout << "What difficulty would you like to pursue?\n\n";
    cout << "1: " << "\033[1;32m" << "EASY" << "\033[0m\n";
    cout << "2: " << "\033[1;31;33m" << "MODERATE" << "\033[0m\n";
    cout << "3: " << "\033[1;31m" << "EXTREME PAIN" << "\033[0m\n\n";
    cout << "[1/2/3]: ";
        while (true) { //check for valid difficulty input
            cin >> difficulty;
            if (cin.fail() || difficulty < 1 || difficulty > 3) {
                cout << "\nChoose a valid difficulty: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                break;
            }
        }
    if (difficulty == 1) { //player chooses easy difficulty
        merchant = Merchant("easy_weapons_file.txt", "food_file.txt", "easy_armor_file.txt"); //initialize merchant
        monster1 = Monster("monsters.txt"); //initialize monster

        level_1 = "easy_level_1.txt"; //set levels according to difficulty
        level_2 = "easy_level_2.txt";
        level_3 = "easy_level_3.txt";
        max_turns = 10; //max number of candycrush level turns
        target_points = 40; //minimum score for candycrush levels
        //printStory("easy_story.txt");
    }
    else if (difficulty == 2) { //player chooses moderate difficulty
        merchant = Merchant("moderate_weapons_file.txt", "food_file.txt", "moderate_armor_file.txt");
        monster2 = Monster("monsters.txt");
        level_1 = "moderate_level_1.txt";
        level_2 = "moderate_level_2.txt";
        level_3 = "moderate_level_3.txt";
        max_turns = 8;
        target_points = 50;
        //printStory("moderate_story.txt");
    }
    else if (difficulty == 3) { //player chooses hard difficulty
        merchant = Merchant("hard_weapons_file.txt", "food_file.txt", "hard_armor_file.txt");
        monster3 = Monster("monsters.txt");
        level_1 = "hard_level_1.txt";
        level_2 = "hard_level_2.txt";
        level_3 = "hard_level_3.txt";
        max_turns = 5;
        target_points = 60;
        //printStory("hard_story.txt");
    }

    //create Level Map
    Map levelMap;
    levelMap.addRoom(1,2,3);
    levelMap.addRoom(2,4,8);
    levelMap.addRoom(3,9,6);

    trade(merchant, player); //player can trade with merchant for the first time
    system("clear");

    do {
        cout << "\033[2J\033[1;1H"; //clears screen much faster than system("clear")
        printStats(player); //print stats of player
        levelMap.displayMap(); //display level map where player can enter candyCrush levels

        cout << "\n[w/a/s/d]: \n"; //player chooses which directin to move
        cin >> direction;
        levelMap.move(direction); 

/*=====testing=====

        cout << "player levels cleared: " << player.getLevelsCleared() << endl;
        cout << "player col: "<< levelMap.getPlayerCol() << endl;
        cout << "player row: "<< levelMap.getPlayerRow() << endl;
        for(int i = 0; i < levelMap.getRoomCount(); i++) {

            cout << "room row:" << levelMap.getRoom(i).getRoomRow() << endl;
            cout << "room col:" << levelMap.getRoom(i).getRoomCol() << endl;

            if (levelMap.getRoom(i).getRoomRow() == levelMap.getPlayerRow() && levelMap.getRoom(i).getRoomCol() == levelMap.getPlayerCol())
            {
                cout << "I am the correct room\n";
                cout << "This is my level number: " << levelMap.getRoom(i).getLevelNumber() << endl;
                if (player.getLevelsCleared() >= levelMap.getRoom(i).getLevelNumber() - 1) {
                    cout << "I can enter this room\n";
                }
                else {
                    cout << "I cannot enter this room\n";
                }
            }
        }

================*/

        if(enterLevel(levelMap, player)) { //check if player is stepping on a level

            cout << "\033[2J\033[1;1H"; //clear screen very quickly
            printStats(player); //display stats and map so it looks like player is actually stepping on level
            levelMap.displayMap();

            int room_level = roomLevel(levelMap, player); //get level of room player is stepping on
            switch (room_level) { //determine whether player can enter the room or not
                case 1: //room one
                    cout << "Do you want to enter this level?\n[Y/N]: ";
                    cin >> input;
                    while(input != "Y" && input != "N") {
                        cout << "Enter a valid input: \n";
                        cout << "[Y/N] ";
                        cin >> input;
                    }
                    if(input == "Y") { //player enter first candyCrush level
                        candy_return = playCandyCrush(player, level_1, max_turns, target_points); //play level one
                        if(candy_return == -2) { //player fails level and game ends
                            endGame = true;
                            continue;
                        }
                        else if(candy_return == -1) { //player reaches target score and continues level until they run out of turns
                            fight_return = fight(player, monster1); //player fights monster
                        }
                        else if(candy_return == 1) { //player reaches target score and does not continue level
                            fight_return = fight(player, monster1);
                        }
                        else if(candy_return == -3) { //skip level for testing
                            fight_return = fight(player, monster1);
                        }
                        else { //debugging
                            cout << "candy_return returns wrong value: " << candy_return << endl;
                            sleep(10);
                        }
                        sleep(2);
                        if(fight_return == -2) { //player runs away
                            trade(merchant, player); //player trades with merchant
                        }
                        else if(fight_return == -1) { //player dies from monster
                            endGame = true;
                            continue; //game ends
                        }
                        else if(fight_return >= 1) { //player kills monster
                            fight_score = 100 - (fight_return * 10); //calculate score from fighting monster
                            player.addTotalScore(fight_score);
                            trade(merchant, player); //trade with merchant after battle
                        }
                        else { //debugging
                            cout << "fight returns wrong value: " << fight_return << endl;
                            sleep(10);
                        }
                    }
                    else if(input == "N") {
                        continue;
                    }
                    candy_return = 0; //reset values for next run through
                    fight_return = 0;
                    fight_score = 0;
                    break;
                case 2: //room two
                    cout << "Do you want to enter this level?\n[Y/N]: ";
                    cin >> input;
                    while(input != "Y" && input != "N") {
                        cout << "Enter a valid input: \n";
                        cout << "[Y/N] ";
                        cin >> input;
                    }
                    if(input == "Y") {
                        candy_return = playCandyCrush(player, level_2, max_turns, target_points); //play level two
                        if(candy_return == -2) { //player fails level
                            endGame = true;
                            continue;
                        }
                        else if(candy_return == -1) { //player reaches target score and continues level until they run out of turns
                            fight_return = fight(player, monster2);
                        }
                        else if(candy_return == 1) { //player reaches target score and does not continue level
                            fight_return = fight(player, monster2);
                        }
                        else if(candy_return == -3) { //skip level for testing
                            fight_return = fight(player, monster2);
                        }
                        else { //debugging
                            cout << "candy_return returns wrong value: " << candy_return << endl;
                            sleep(10);
                        }
                        sleep(2);
                        if(fight_return == -2) { //player runs away
                            trade(merchant, player);
                        }
                        else if(fight_return == -1) { //player dies from monster
                            endGame = true;
                            continue;
                        }
                        else if(fight_return >= 1) { //player kills monster
                            fight_score = 100 - (fight_return * 10); //calculate score from fighting monster
                            player.addTotalScore(fight_score);
                            trade(merchant, player);
                        }
                        else { //debugging
                            cout << "fight returns wrong value: " << fight_return << endl;
                            sleep(10);
                        }
                    }
                    else if(input == "N") {
                        continue;
                    }
                    candy_return = 0;
                    fight_return = 0;
                    fight_score = 0;
                    break;
                case 3: //room three
                    cout << "Do you want to enter this level?\n[Y/N]: ";
                    cin >> input;
                    while(input != "Y" && input != "N") {
                        cout << "Enter a valid input: \n";
                        cout << "[Y/N] ";
                        cin >> input;
                    }
                    if(input == "Y") {
                        candy_return = playCandyCrush(player, level_3, max_turns, target_points); //play level three
                        if(candy_return == -2) { //player fails level
                            endGame = true;
                            continue;
                        }
                        else if(candy_return == -1) { //player reaches target score and continues level until they run out of turns
                            fight_return = fight(player, monster3);
                        }
                        else if(candy_return == 1) { //player reaches target score and does not continue level
                            fight_return = fight(player, monster3);
                        }
                        else if(candy_return == -3) { //skip level for testing
                            fight_return = fight(player, monster3);
                        }
                        else { //debugging
                            cout << "candy_return returns wrong value: " << candy_return << endl;
                            sleep(10);
                        }
                        sleep(3);
                        endGame = true;
                        if(fight_return == -2) { //player runs away
                            endGame = true;
                        }
                        else if(fight_return == -1) { //player dies from monster
                            endGame = true;
                        }
                        else if(fight_return >= 1) { //player kills monster
                            fight_score = 100 - (fight_return * 10); //calculate score from fighting monster
                            player.addTotalScore(fight_score);
                            cout << "You beat the game!\n";
                            sleep(3);
                            endGame = true;
                        }
                        else { //debugging
                            cout << "fight returns wrong value: " << fight_return << endl;
                            sleep(10);
                        }
                    }
                    else if(input == "N") {
                        continue;
                    }
                    candy_return = 0;
                    fight_return = 0;
                    fight_score = 0;
                    break;
                default: //player cannot enter room
                    cout << "This level is locked.\n";
                    sleep(1.5);
                    break;
            }
        }

    } while(endGame == false);

    //game ends
    system("clear");
    printAsciiArt("the_end.txt"); //The End art
    writeToLeaderboard("leaderboard.txt", player); //write player's name and score to leaderboard
    printLeaderBoard("leaderboard.txt"); //print out sorted leaderboard

    //balance trading
    //design levels and create files
    //printStory()

}
