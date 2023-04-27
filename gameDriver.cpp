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

//up-to-date compile command
//g++ gameDriver.cpp Player.cpp Weapon.cpp Food.cpp Armor.cpp Merchant.cpp vectorSplit.cpp Map.cpp candy.cpp candyCrush.cpp Room.cpp Monster.cpp

using namespace std;

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
            "==================================================================\n"
            "|                                                                |\n";
    cout << "|  Weapons:                                                      |\n";
        for (int i = 0; i < merchant.getWeaponInv().size(); i++) {
            if(i == 5) { //this limits the amount of items displayed
                break;
            }
    cout << "|    " << left << i+1 << ". " << setw(39) << merchant.getWeapon(i).getName()
         << "G-" << setw(4) << merchant.getWeapon(i).getCost() << " (Dmg: "
         << merchant.getWeapon(i).getDamage() << ")  |\n";
        }
    cout << "|                                                                |\n"
            "==================================================================\n"
            "|                                                                |\n"
            "|  Armor:                                                        |\n";
        for (int i = 0; i < merchant.getArmorInv().size(); i++) {
            if(i == 5) {
                break;
            }
    cout << "|    " << left << i+1 << ". " << setw(39) << merchant.getArmor(i).getName()
         << "G-" << setw(4) << merchant.getArmor(i).getCost() << " (prot: "
         << merchant.getArmor(i).getProtection()<< ") |\n";
        }
    cout << "|                                                                |\n"
            "==================================================================\n"
            "|                                                                |\n"
            "|  Food:                                                         |\n";
        for (int i = 0; i < merchant.getFoodInv().size(); i++) {
            if(i == 5) {
                break;
            }
    cout << "|    " << left << i+1 << ". " << setw(30) << merchant.getFood(i).getName()
         << "G-" << setw(7) << merchant.getFood(i).getCost() << " (Recovery: "
         << merchant.getFood(i).getRecover()<< ")   |\n";
        }
    cout << "|                                                                |\n"
            "==================================================================\n"
            "|                                                                |\n"
            "|  \033[1;33mGold\033[0m: "<< left << setw(7) <<player.getTotalMoney() <<
            "                                                 |\n"
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


void printStats(Player player) {

//**do not indent**

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
+---------------+\n\
+---------------+ \033[0m\n\n";

    //ITEMS: have a file with cool items that can affect the players stats - beneficial or misfortune

}

/*
    1. This function prints out every attempt from players and uses a sorting algorithim to determine which order to print them
*/
void printLeaderBoard(string leaderboard_file) {
    vector<string> leaderboard;
    int lb_count = 1;

    vectorSplit(leaderboard_file, '|', leaderboard);
    
//***implement sorting algorithm here***

    cout << "\033[1;33m" << "   ---LEADERBOARD---" << "\033[0m\n"; //used stackoverflow for colored text syntax
    for(int i = 0; i < leaderboard.size(); i++) {
        cout << left << setw(4) << lb_count + ". " << setw(25) << leaderboard[i] << " " << setw(3) << "\033[1;33m" << leaderboard[i+1] << "\033[0m\n";
        i++;
        lb_count++;
    }
}

/*
    1. This function writes to the leaderboard file
*/
void writeToLeaderboard(string leaderboard_file, Player player) {
    ofstream leaderboard(leaderboard_file);

    if(!leaderboard.fail()) {
        int player_score = player.getTotalScore();
        string player_name = player.getUsername();
        leaderboard << player_name << "|" << player_score << "\n";
    }
    else
        cout << "leaderboard file, \"" << leaderboard_file << "\" could not be opened";

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


int fight(Player &player, Monster &monster) { //returns int to make it easy to add alternate endings

    player.setHealth(100);

    int num_turns = 0; //used to calculate player's score at end of battle
    int choice;
    bool endBattle = false;
    int randNum;

    string player_weapon = player.getCurrWeapon().getName();
    string player_armor = player.getCurrArmor().getName();
    const int player_max_health = 100;  
    const int monster_max_health = monster.getHealth();

//Initialize battle=========
    system("clear");
    cout << "Watch out! It looks like \033[1;31m" << monster.getName() << "\033[0m has appeared!\n";
    cout << "It looks like you have to fight... get ready, " << player.getUsername() << endl;
    sleep(5);

    while(!endBattle) {

        //player stats
        int player_protection = player.getCurrArmor().getProtection();
        int player_num_hashtags = static_cast<int>((player.getHealth() / static_cast<double>(player_max_health)) * 25);
        int monster_num_hashtags = static_cast<int>((monster.getHealth() / static_cast<double>(monster_max_health)) * 25);


        system("clear");
        num_turns++;

        if(player.getHealth() <= 0) {
            cout << "You were killed by " << monster.getName() << "! You lasted " << num_turns << " turns against the monster.\n";
            return -1; //player killed
        }

        printAsciiArt("monster_battle.txt");
        cout << ".----------------------------------------------------.\n"
                "|                   BATTLE MENU                      |\n"
                "|----------------------------------------------------|\n"
                "| \033[1;33m" << left << setw(25) << monster.getName() +"'s Health:\033[0m [\033[1;31m";
            for (int i = 0; i < monster_num_hashtags; i++) {
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
            for (int i = 0; i < player_num_hashtags; i++) {
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
            monster.setHealth(monster.getHealth() - player.getCurrWeapon().getDamage());
            sleep(2);
            cout << "You dealt " << player.getCurrWeapon().getDamage() << " points of damage!\n";
            sleep(2);
            if(monster.getHealth() <= 0) {
                cout << "Your attack was fatal! " << monster.getName() << " was defeated in " << num_turns << " turns\n";
                sleep(3);
                endBattle = true;
                return 1; //player continues game
            }
            cout << monster.getName() << " attacked you and did " << (monster.getDamage() - monster.getDamage() * (static_cast<double>(player_protection) / 100.0)) << "pts of damage!\n";
            player.removeHealth(monster.getDamage() - monster.getDamage() * (static_cast<double>(player_protection) / 100.0));
            sleep(4);
        }
        else if(choice == 2) { //block
            cout << "You choose to block " << monster.getName() << "'s incoming attack!\n";
            sleep(2);
            randNum = rand() % 10;
            if(randNum >= 5) {
                cout << "You blocked the attack!\n";
                sleep(2);
                continue;
            }
            else {
                cout << "You failed to block the attack!\n";
            }
            cout << monster.getName() << " attacked you and did " << (monster.getDamage() - monster.getDamage() * (static_cast<double>(player_protection) / 100.0)) << "pts of damage!\n";
            player.removeHealth(monster.getDamage() - monster.getDamage() * (static_cast<double>(player_protection) / 100.0));
            sleep(4);
        }
        else if(choice == 3) //Consume food
        {
            int food_choice = 0; 

            cout << "You chose to consume\n";
            sleep(1);
            if(!player.getFoodInv().empty()) {
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
                player.setHealth(player.getHealth() + food.getRecover());
                cout << "food_choice: " << food_choice << endl;
                cout << "food_choice-1: " << food_choice-1 << endl;
                player.removeFood(food_choice);
            }
            else {
                cout << "You have no food in your inventory!\n";
                num_turns--; //do not increment turns in this case
                sleep(2);
            }
            cout << monster.getName() << " attacked you and did " << (monster.getDamage() - monster.getDamage() * (static_cast<double>(player_protection) / 100.0)) << "pts of damage!\n";
            player.removeHealth(monster.getDamage() - monster.getDamage() * (static_cast<double>(player_protection) / 100.0));
            sleep(4);
        }
        else if(choice == 4) //Special Attack
        {
            cout << "You use your special attack on " << monster.getName() << "!\n";
            monster.setHealth(monster.getHealth() - (player.getCurrWeapon().getDamage() * 2));
            sleep(2);
            cout << "You did " << (player.getCurrWeapon().getDamage() * 2) << " points of damage!\n";
            sleep(2);
            cout << "You also did " << (static_cast<double>(player.getCurrWeapon().getDamage()) / 2.0) << " against yourself...\n";
            player.removeHealth(static_cast<int>(static_cast<double>(player.getCurrWeapon().getDamage()) / 2.0));

            if(monster.getHealth() <= 0) {
                cout << "Your attack was fatal! " << monster.getName() << " was defeated in " << num_turns << " turns\n";
                sleep(3);
                endBattle = true;
                return 1; //player continues game
            }
            cout << monster.getName() << " attacked you and did " << (monster.getDamage() - monster.getDamage() * (static_cast<double>(player_protection) / 100.0)) / 2.0 << "pts of damage!\n";
            player.removeHealth(monster.getDamage() - monster.getDamage() * (static_cast<double>(player_protection) / 100.0));
            sleep(4);
        }
        else if(choice == 5) //if you run away the monster steals all your food
        { 
            cout << "You decided to run away!\n";
            sleep(1);
            player.removeAllFood();
            cout << "As you were running away you left all of your food behind.\n";
            sleep(4);
            endBattle = true;
            return 1; //player continues game
        }
    }
}

void playCandyCrush(Player &player, string level_name, const int max_turns, const int target_score) {
    int num_turns = 0;
    // max_turns sets turn limit for player
    // target_score sets minimum score threshold for player
    char row_input;
    int row = 0;
    int col_input = 0;
    string direction;
    string input;
    bool endGame = false;
    bool promptContinueGame = false;

    candyCrush candy_crush(level_name);

    while(!endGame) {
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
        candy_crush.displayBoard();

        if(num_turns == max_turns) {
            cout << "You have no more turns!\n";
            sleep(2);
            endGame = true;
            if(candy_crush.getScore() < target_score) {
    //game ending scenario
            }
        }

//===begin prompting player========================================================
        cout << "Enter row [A-J]: ";    //FIX ROW INPUT - multiple input error
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
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
        if(direction == "w") {
            if(candy_crush.swap(row, col_input, row-1, col_input)) {
                candy_crush.removeMatches(candy_crush.getCandy(row-1, col_input).getColor(), row-1, col_input);
                candy_crush.removeMatches(candy_crush.getCandy(row, col_input).getColor(), row, col_input);
                candy_crush.generateCandy();
                num_turns++;
            }
        }
        else if (direction == "a") {
            if(candy_crush.swap(row, col_input, row, col_input-1)) {
                candy_crush.removeMatches(candy_crush.getCandy(row, col_input-1).getColor(), row, col_input-1);
                candy_crush.removeMatches(candy_crush.getCandy(row, col_input).getColor(), row, col_input);
                candy_crush.generateCandy();
                num_turns++;
            }
        }
        else if(direction == "s") {
            if(candy_crush.swap(row, col_input, row+1, col_input)) {
                candy_crush.removeMatches(candy_crush.getCandy(row+1, col_input).getColor(), row+1, col_input);
                candy_crush.removeMatches(candy_crush.getCandy(row, col_input).getColor(), row, col_input);
                candy_crush.generateCandy();
                num_turns++;
            }
        }
        else if(direction == "d") {
            if(candy_crush.swap(row, col_input, row, col_input+1)) {
                candy_crush.removeMatches(candy_crush.getCandy(row, col_input+1).getColor(), row, col_input+1);
                candy_crush.removeMatches(candy_crush.getCandy(row, col_input).getColor(), row, col_input);
                candy_crush.generateCandy();
                num_turns++;
            }

        }
        else if(direction == "Q123") { //This can skip the level for testing purposes
            endGame = true;
        }

        if(candy_crush.getScore() >= target_score && !promptContinueGame) {
            cout << "You have reached the target score for this level!\n";
            cout << "Would you like to keep playing for a higher score?\n[Y/N]: ";
            cin >> input;
                while(input != "Y" && input != "N") {
                    cout << "Enter a valid choice:  \n";
                    cin >> input;
                }
            if(input == "Y") {
                cout << "Good luck!\n";
                sleep(1); 
                player.setLevelScore(candy_crush.getScore());
                promptContinueGame = true;
                continue;
            }
            else if(input == "N") {
                cout << "You continue on your journey...\n";
                sleep(1.5);
                endGame = true;
            }
        }

        player.setLevelScore(candy_crush.getScore());

    }
    player.addTotalScore(candy_crush.getScore()); //adds level score to total player score (total_score = total_score + level_score)
    player.setLevelScore(0); //reset level score when player exits level
    player.addTotalMoney(300); //***change to reflect difficulty*** - gives more money to player
    player.increaseLevelsCleared();

    //***add game ending scenarios***

}

/**
 * This function loops through the vector of rooms in the map class, and
 * it returns true if it found the room with the same coordinates as the player
**/
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

/**
 * This function loops through the vector of rooms in the map class, and
 * checks which room has the same coordinates as the player.
 * Then it returns the level of that room if the player is allowed to access it, and returns -1 otherwise
**/
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

int main() {

    srand(time(NULL));

    Player player; //initialize player
    Merchant merchant; //initialize merchant
    Monster monster;
    string username; //player username
    string input;
    char direction;
    int difficulty = 0;
    bool endGame = false;
    string level_1;
    string level_2;
    string level_3;
    int max_turns = 0; //determines how many tries a player gets to complete a candycrush level
    int target_points = 0; //determines how many points a player needs to meet in order to pass a level
    int fight_return = 0; //records outcome of player's fight with monster (0 = default)

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

    printLeaderBoard("leaderboard.txt");
    
//STORY / INSTRUCTIONS ===================================================================

    //printStory(); (can instead happen directly after the player chooses difficulty)

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
            cout << "Hello, " <<"\033[1;33m"<< username <<"\033[0m"<< endl;
            sleep(1.5);
            system("clear");
            chooseNameAgain = false;
            player.setUsername(username);
        }
        else if(input == "N") {
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
    if (difficulty == 1) {
        merchant = Merchant("easy_weapons_file.txt", "food_file.txt", "easy_armor_file.txt"); //initialize merchant
        monster = Monster("monsters.txt"); //initialize monster
        level_1 = "testLevel.txt";
        level_2 = "easy_level_3.txt";
        level_3 = "easy_level_2.txt";
        max_turns = 10; //max number of candycrush level turns
        target_points = 40; //minimum score for candycrush levels
        //printStory("easy_story.txt");
    }
    else if (difficulty == 2) {
        merchant = Merchant("moderate_weapons_file.txt", "food_file.txt", "moderate_armor_file.txt");
        monster = Monster("monsters.txt");
        level_1 = "moderate_level_1.txt";
        level_2 = "moderate_level_2.txt";
        level_3 = "moderate_level_3.txt";
        max_turns = 8;
        target_points = 50;
        //printStory("moderate_story.txt");
    }
    else if (difficulty == 3) {
        merchant = Merchant("hard_weapons_file.txt", "food_file.txt", "hard_armor_file.txt");
        monster = Monster("monsters.txt");
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

    trade(merchant, player); //First instance of trading options
    system("clear");

    do {
        cout << "\033[2J\033[1;1H"; //clears screen much faster than system("clear")
        printStats(player);
        levelMap.displayMap();

        cout << "\n[w/a/s/d]: \n";
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

        if(enterLevel(levelMap, player)) {

            cout << "\033[2J\033[1;1H"; //clear screen very quickly
            printStats(player);
            levelMap.displayMap();

            int room_level = roomLevel(levelMap, player);
            switch (room_level) {
                case 1:
                    cout << "Do you want to enter this level?\n[Y/N]: ";
                    cin >> input;
                    while(input != "Y" && input != "N") {
                        cout << "Enter a valid input: \n";
                        cout << "[Y/N] ";
                        cin >> input;
                    }
                    if(input == "Y") {
                        playCandyCrush(player, level_1, max_turns, target_points); //play level one
                        fight_return = fight(player, monster);
                        sleep(2);
                        if(fight_return == -2) { //player runs away
                            trade(merchant, player);
                        }
                        else if(fight_return == -1) { //player dies from monster
                            endGame = true;
                            continue;
                        }
                        else if(fight_return == 1) { //player kills monster
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
                    fight_return = 0;
                    break;
                case 2:
                    cout << "Do you want to enter this level?\n[Y/N]: ";
                    cin >> input;
                    while(input != "Y" && input != "N") {
                        cout << "Enter a valid input: \n";
                        cout << "[Y/N] ";
                        cin >> input;
                    }
                    if(input == "Y") {
                        playCandyCrush(player, level_2, max_turns, target_points); //play level two
                        fight_return = fight(player, monster);
                        sleep(2);
                        if(fight_return == -2) { //player runs away
                            trade(merchant, player);
                        }
                        else if(fight_return == -1) { //player dies from monster
                            endGame = true;
                            continue;
                        }
                        else if(fight_return == 1) { //player kills monster
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
                    fight_return = 0;
                    break;
                case 3:
                    cout << "Do you want to enter this level?\n[Y/N]: ";
                    cin >> input;
                    while(input != "Y" && input != "N") {
                        cout << "Enter a valid input: \n";
                        cout << "[Y/N] ";
                        cin >> input;
                    }
                    if(input == "Y") {
                        playCandyCrush(player, level_3, max_turns, target_points); //play level three
                        fight_return = fight(player, monster);
                        sleep(3);
                        endGame = true;
                        if(fight_return == -2) { //player runs away
                            endGame = true;
                        }
                        else if(fight_return == -1) { //player dies from monster
                            endGame = true;
                        }
                        else if(fight_return == 1) { //player kills monster
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
                    fight_return = 0;
                    break;
                default:
                    cout << "This level is locked.\n";
                    sleep(1.5);
                    break;
            }
        }

    } while(endGame == false);

    system("clear");
    printAsciiArt("the_end.txt");
    writeToLeaderboard("leaderboard.txt", player);
    printLeaderBoard("leaderboard.txt");

/*I am obsessed with bars now
    cout << "[\033[1;33m";
    for(int i = 0; i < 60; i++) { //60 second bar until game shuts down
        cout << "#";
        sleep(1);
    }
    cout << "\033[0m";
*/

        //implement gifts and stars
        //balance trading
        //add option to buy multiple food items at a time
        //add player's inventories to shop
        //add command options under stats (?)
        //add misfortunes
        //protect against wrong inputs
        //finalize design of game
        //***change to reflect difficulty*** - gives more money to player - addTotalMoney() after candycrush level
        //***game ending scenarios***
        //design levels and create files
        //final boss (?)

}
