#include <cassert>
#include "Monster.h"
#include "vectorSplit.h"

int main() {
    srand(time(NULL));
        
    //default constructor
    Monster monster1;
    assert(monster1.getName() == "Lv. 1 Mafia Boss");
    assert(monster1.getDamage() == 0);
    assert(monster1.getHealth() == 0);

    //parameterized constructor
    //*** cannot use assert statements here, because monster is chosen at random from file
    Monster monster2 = Monster("monsters.txt");
    cout << "Monster2 name: " << monster2.getName() << endl;
    cout << "Monster2 health: " << monster2.getHealth() << endl;
    cout << "Monster2 damage: " << monster2.getDamage() << endl;

    //testing setters
    monster2.setDamage(50);
    assert(monster2.getDamage() == 50);
    monster2.setHealth(40);
    assert(monster2.getHealth() == 40);
    monster2.setName("Lv. 300 gangster");
    assert(monster2.getName() == "Lv. 300 gangster");

}