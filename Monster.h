#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

class Monster
{
    private:
        string name;
        int health; //Monster Health
        int damage; //How much damage the monsters do

    public:

        Monster(); //Default Constructor
        Monster(string filename);

        void setName(string set_name);
        void setHealth(int health); //Sets The Health of the Monster
        void setDamage(int damage);

        int getDamage();
        int getHealth(); //Gets Health of Monster
        string getName();
};
