#ifndef CANDY_H
#define CANDY_H

#include <iostream>

using namespace std;

class candy {
    private:
        string color;
        bool isSpecial;
        bool isModifiable;
        int rowLocation;
        int columnLocation;
    public:
        candy(); //not yet implemented in candy.cpp
        candy(string color, int row, int column);
        string getColor();
        int getRow();
        int getColumn();
        void setColor(string color);
        void setRow(int row);
        void setColumn(int column);
        void setAll(string color, int row, int column);
        void move(char direction);
        bool isSpecialCandy();
        bool isModifiableCandy();

};
#endif
