#ifndef CANDY_H
#define CANDY_H

#include <iostream>

using namespace std;

class candy {
    private:
        char color;
        bool isSpecial;
        int rowLocation;
        int columnLocation;
    public:
        candy(char color, int row, int column);
        char getColor();
        int getRow();
        int getColumn();
        void setRow(int row);
        void setColumn(int col);
        bool isSpecialCandy();

};
#endif