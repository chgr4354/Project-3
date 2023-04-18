#include "Food.h"

using namespace std;

Food::Food() {
    name = "";
    recover = 0;
}
Food::Food(string new_name = "", int new_recover = 0) {
    name = new_name;
    recover = new_recover;
}

string Food::getName() {
    return name;
}
int Food::getRecover() {
    return recover;
}

void Food::setName(string new_name) {
    name = new_name;
}
void Food::setRecover(int new_recover) {
    recover = new_recover;
}