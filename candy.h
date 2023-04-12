#ifndef CANDY_H
#define CANDY_H

#include <iostream>

using namespace std;

class candy {
    private:
        char color;
        bool isSpecial;
        bool isModifiable;
        int rowLocation;
        int columnLocation;
    public:
        candy(); //not yet implemented in candy.cpp
        candy(char color, int row, int column);
        char getColor();
        int getRow();
        int getColumn();
        void setColor(char color);
        void setRow(int row);
        void setColumn(int column);
        void setAll(char color, int row, int column);
        void move(char direction);
        bool isSpecialCandy();
        bool isModifiableCandy();

};
#endif
