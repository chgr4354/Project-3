#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

class Monster
{
    private:
        string name; //Monster name
        int health;  //Monster Health
        int damage;  //How much damage the monsters do

    public:
        Monster();                  //Default Constructor
        Monster(string filename);   //parameterized constructor

        void setName(string set_name);  //set name of monster
        void setHealth(int health);     //Sets The Health of the Monster
        void setDamage(int damage);     //set damage for monster

        int getDamage();  //get damage of monster
        int getHealth();  //Gets Health of Monster
        string getName(); //get name of monster
        
};
