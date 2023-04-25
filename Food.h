#ifndef FOOD_H
#define FOOD_H

#include <iostream>

using namespace std;

class Food {

    private:
        string name;
        int recover;
        int cost;

    public:
        Food();
        Food(string name, int recover, int cost);

        string getName();
        int getRecover();
        int getCost();

        void setName(string name);
        void setRecover(int points);
        void setCost(int cost);

};
#endif
