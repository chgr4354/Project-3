#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cassert>
#include "Players.h"
using namespace std;

//How a Monster May Look Like

//Username
//Health
//Damage

class Monster
{
    private:

        string username;
        int health; //Monster Health
        int damage; //How much damage the monsters do

    public:

        Monster(); //Default Constructor

        void setUsername(string set_username);
        string getUsername();

        void setHealth(int health); //Sets The Health of the Monster
        int getHealth(); //Gets Health of Monster
        
};
