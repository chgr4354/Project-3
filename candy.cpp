#include "candy.h"

using namespace std;

candy::candy(char new_color = '-', int new_row, int new_column) { //initialize a new candy object with default color '-'
    color = new_color;
    if(new_color == '⭐' || new_color == '🎁')
        isSpecial = true;
    else
        isSpecial = false;
    rowLocation = new_row;
    columnLocation = new_column;
}

//getters
char candy::getColor() {
    return color;
}

int candy::getRow() {
    return rowLocation;
}

int candy::getColumn() {
    return columnLocation;
}

//setters
void candy::setRow(int new_row) {
    rowLocation = new_row;
}
void candy::setColumn(int new_column) {
    columnLocation = new_column;
}

//other
bool candy::isSpecialCandy() {
    if(isSpecial) {
        return true;
    }
    else
        return false;
}