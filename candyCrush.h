#ifndef CANDYCRUSH_H
#define CANDYCRUSH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "candy.h"

using namespace std;

class candyCrush {

    private:
    /*regular colors
        char blue = '🟦';
        char green = '🟩';
        char red = '🟥';
        char white = '⬜';
    */
    /*special items
        char star = '⭐';
        char gift = '🎁';
    */
    //map output
        static const int rows = 13;      //number of rows in level
        static const int columns = 13;   //number of columns in level
        int score;

        candy board[rows][columns];

    public:
        candyCrush(string level);

        void initializeBoard(string level); //initializes board by reading from file
        void resetBoard();
        void displayBoard();      //displays level
        void swap(int row1, int col1, int row2, int col2);            //swaps elements
        void generateCandy();   //inserts new color into position in level
        void removeMatches();

        int getRows();
        int getColumns();
        int getScore();

        void setRows(int rows);
        void setColumns(int col);
        void setScore(int score);

        bool isOnBoard(int row, int col);
        vector<bool> isSameColor(int row, int col);
        bool isStar(int row, int col);
        bool isGift(int row, int col);


};
#endif