#include <iostream>

using namespace std;

class Weapon {

    private:
        string name;
        int damage;
        string story;

    public:
        Weapon();
        Weapon(string name, int damage, string story);

        string getName();
        string getStory();
        int getDamage();

        void setName(string new_name);
        void setStory(string new_story);
        void setDamage(int new_damage);


};