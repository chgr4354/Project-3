#include "candy.h"

using namespace std;

candy::candy(char new_color = '-', int new_row = 0, int new_column = 0) { //initialize a new candy object with default values
    color = new_color;
    if(new_color == '⭐' || new_color == '🎁')
        isSpecial = true;
    else
        isSpecial = false;
    if(new_color == '🟦'|| new_color == '🟩' || new_color == '🟥' || new_color == '⬜' || new_color == '-' || new_color == isSpecial)
        isModifiable = true;
    else
        isModifiable = false;
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
bool candy::isSpecialCandy() { //check if candy is a special candy
    return isSpecial;
}
bool candy::isModifiableCandy() { //check if candy is a "candy" or a coordinate emoji
    return isModifiable;
}

//setters
void candy::setColor(char new_color) {
    color = new_color;
}
void candy::setRow(int new_row) {
    rowLocation = new_row;
}
void candy::setColumn(int new_column) {
    columnLocation = new_column;
}
void candy::setAll(char new_color, int new_row, int new_column) {
    color = new_color;
    rowLocation = new_row;
    columnLocation = new_column;
}
