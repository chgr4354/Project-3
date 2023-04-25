#ifndef WEAPON_H
#define WEAPON_H

#include <string>

using namespace std;

class Weapon {

    private:
        string name;
        int damage;
        int cost;
        string story;

    public:
        Weapon();
        Weapon(string name, int damage, int cost, string story);

        string getName();
        string getStory();
        int getDamage();
        int getCost();

        void setName(string new_name);
        void setStory(string new_story);
        void setDamage(int new_damage);
        void setCost(int new_cost);

};
#endif
