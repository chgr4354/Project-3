#include "Food.h"

using namespace std;

//constructors
Food::Food() {
    name = "";
    recover = 0;
    cost = 0;
}
Food::Food(string new_name, int new_recover, int new_cost) {
    name = new_name;
    recover = new_recover;
    cost = new_cost;
}

//getters
string Food::getName() {
    return name;
}
int Food::getRecover() {
    return recover;
}
int Food::getCost() {
    return cost;
}

//setters
void Food::setName(string new_name) {
    name = new_name;
}
void Food::setRecover(int new_recover) {
    recover = new_recover;
}
void Food::setCost(int new_cost) {
    cost = new_cost;
}
