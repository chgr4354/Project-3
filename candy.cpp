#include "candy.h"

using namespace std;

candy::candy() { //default candy constructor
    color = "-";
    rowLocation = 0;
    columnLocation = 0;
}

candy::candy(string new_color = "-", int new_row = 0, int new_column = 0) { //parameterized candy constructor
    color = new_color; //set color
    if(new_color == "⭐" || new_color == "🎁") //set isSpecial condition
        isSpecial = true;
    else
        isSpecial = false;
    //set isModifiable condition
    if(new_color == "🟦"|| new_color == "🟨" || new_color == "🟥" || new_color == "⬜" || new_color == "-" || new_color == "⭐" || new_color == "🎁")
        isModifiable = true;
    else
        isModifiable = false;
    rowLocation = new_row; //set row
    columnLocation = new_column; //set column
}

//getters
string candy::getColor() { //get candy color
    return color;
}
int candy::getRow() { //get candy row
    return rowLocation;
}
int candy::getColumn() { //get candy column
    return columnLocation;
}
bool candy::isSpecialCandy() { //check if candy is a special candy
    return isSpecial;
}
bool candy::isModifiableCandy() { //check if candy is a "candy" or a coordinate emoji
    return isModifiable;
}

//setters
void candy::setColor(string new_color) { //set new color of candy
    if(new_color == "⭐" || new_color == "🎁") //change isSpecial condition
        isSpecial = true;
    color = new_color; //change color
    //change isModifiable condition
    if(new_color == "🟦"|| new_color == "🟨" || new_color == "🟥" || new_color == "⬜" || new_color == "-" || new_color == "⭐" || new_color == "🎁")
        isModifiable = true;
    else
        isModifiable = false;
}
void candy::setRow(int new_row) { //set row
    rowLocation = new_row;
}
void candy::setColumn(int new_column) { //set column
    columnLocation = new_column;
}
void candy::setAll(string new_color, int new_row, int new_column) { //change everything about a candy
    color = new_color;
    rowLocation = new_row;
    columnLocation = new_column;
}

/**other, not necessary
//***DOES NOT CHECK IF LOCATION isOnBoard()****
void candy::move(char direction) { //moves candy to new location (w,a,s,d)
    switch (direction) {
        case 'w':
            rowLocation--;
            break;
        case 's':
            rowLocation++;
            break;
        case 'a':
            columnLocation--;
            break;
        case 'd':
            columnLocation++;
            break;
        default:
            break;
    }
}
*/
