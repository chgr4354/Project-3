#ifndef ARMOR_H
#define ARMOR_H

#include <iostream>

using namespace std;

class Armor {

    private:
        string name;
        string story;
        int protection;
        int cost;
    
    public:
        Armor();
        Armor(string name, int protection, int cost, string story);

        string getName();
        string getStory();
        int getProtection();
        int getCost();

        void setName(string name);
        void setStory(string story);
        void setProtection(int protection);
        void setCost(int cost);
        
};
#endif
