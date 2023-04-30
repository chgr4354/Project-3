#include <cassert>
#include "Player.h"

int main () {

    //Testing Default Constructor
    Player Player1;

    //Testing Default Constructor
    cout << "Player1 Name is: " << Player1.getUsername() << endl;
    cout << "Player1 Level is: " << Player1.getLevel() << endl;
    cout << "Player1 Total Money is: " << Player1.getTotalMoney() << endl;
    cout << "Player1 Total Score is: " << Player1.getTotalScore() << endl;
    cout << "Player1 current weapon: " << Player1.getCurrWeapon().getName() << endl;
    cout << "Player1 current armor: " << Player1.getCurrArmor().getName() << endl;
    cout << "Player1 food inventory: "; Player1.printFoodInv(Player1.getFoodInv());
    cout << "\nPlayer1 health is: " << Player1.getHealth() << endl;
    assert(Player1.getUsername() == "");
    assert(Player1.getLevel() == 0);
    assert(Player1.getTotalMoney() == 500);
    assert(Player1.getTotalScore() == 0);
    assert(Player1.getCurrWeapon().getName() == "butter knife");
    assert(Player1.getCurrArmor().getName() == "regular clothes");
    assert(Player1.getHealth() == 100);

    

    cout << "\n\nPlayer2: \n";
    Player Player2;
    Weapon weapon2 = Weapon("sword", 50, 200, "this is a story");
    Armor armor2 = Armor("light armor", 30, 150, "this is another story");

    //Testing Other Player Functions
    Player2.setUsername("Jimmy");
    Player2.setLevel(100);
    Player2.setTotalMoney(1000);
    Player2.setTotalScore(1200);
    Player2.setHealth(200);
    Player2.setCurrArmor(armor2);
    Player2.setCurrWeapon(weapon2);


    //Testing Other Player Functions
    cout << "Player2 Name is: " << Player2.getUsername() << endl;
    cout << "Player2 Level is: " << Player2.getLevel() << endl;
    cout << "Player2 Money is: " << Player2.getTotalMoney() << endl;
    cout << "Player2 Score is: " << Player2.getTotalScore() << endl;
    cout << "Player2 levels cleared: " << Player2.getLevelsCleared() << endl;
    cout << "Player2 current weapon: " << Player2.getCurrWeapon().getName() << endl;
    cout << "Player2 current armor: " << Player2.getCurrArmor().getName() << endl;
    cout << "Player2 health is: " << Player2.getHealth() << endl;
    assert(Player2.getUsername() == "Jimmy");
    assert(Player2.getLevel() == 100);
    assert(Player2.getTotalMoney() == 1000);
    assert(Player2.getTotalScore() == 1200);
    assert(Player2.getCurrWeapon().getName() == "sword");
    assert(Player2.getCurrArmor().getName() == "light armor");
    assert(Player2.getHealth() == 200);
    Player2.removeHealth(50);
    cout << "\nPlayer2 remove 50 health: " << Player2.getHealth() << endl;
    
    Player2.setLevelMoney(100);
    Player2.setLevelMoney(100);

    //Testing Reset Functions
    Player2.resetLevelMoney();
    Player2.restLevelScore();

    cout << "Player2 level score is: " << Player2.getLevelScore() << endl;
    cout << "Player2 level money is: " << Player2.getLevelMoney() << endl;
    assert(Player2.getLevelScore() == 0);
    assert(Player2.getLevelMoney() == 0);

//addFood():
    cout << "Player2 food inventory: ";
    Food food = Food("Carrot", 10, 5);
    Player2.addFood(food);
    Player2.printFoodInv(Player2.getFoodInv());

//removeFood():
    cout << "\nPlayer2 Remove food: ";
    Player2.removeFood(1);
    Player2.printFoodInv(Player2.getFoodInv());

//removeAllFood():
    cout << "\nPlayer2 add two foods: ";
    Player2.addFood(food);
    Player2.addFood(food);
    Player2.printFoodInv(Player2.getFoodInv());
    cout << "\nPlayer2 remove all food: ";
    Player2.removeAllFood();
    Player2.printFoodInv(Player2.getFoodInv());
    cout << "\n";

}