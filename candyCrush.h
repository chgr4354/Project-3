#ifndef CANDYCRUSH_H
#define CANDYCRUSH_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "candy.h"

using namespace std;

class candyCrush {

    private:
        static const int rows = 11;      //number of rows in level
        static const int columns = 11;   //number of columns in level
        int score = 0;

        candy board[rows][columns];

    public:
        candyCrush();
        candyCrush(string level);

        //other
        void initializeBoard(string level); //initializes board by reading from file
        void resetBoard();
        void displayBoard();      //displays level
        bool swap(int row1, int col1, int row2, int col2); //swaps elements
        void generateCandy();   //inserts new color into position in level
        void removeMatches(string color, int row, int col);

        //getters
        int getRows();
        int getColumns();
        int getScore();
        candy getCandy(int row, int col);

        //setters
        void setRows(int rows);
        void setColumns(int col);
        void setScore(int score);

        //bools
        bool isOnBoard(int row, int col);
        bool isSameColor(int row, int col, int row2, int col2);
        bool isStar(int row, int col);
        bool isGift(int row, int col);

        //for future, may want isColor() function for easier testing

};
#endif
