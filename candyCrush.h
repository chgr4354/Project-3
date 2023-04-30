#ifndef CANDYCRUSH_H
#define CANDYCRUSH_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "candy.h"

using namespace std;

class candyCrush {

    private:
        static const int rows = 11;     //number of rows in level
        static const int columns = 11;  //number of columns in level
        int score = 0;                  //score for level
        candy board[rows][columns];     //array of candy objects to represent the board

    public:
        candyCrush();               //deafult constructor
        candyCrush(string level);   //parameterized constructor takes in filename

        //other
        void initializeBoard(string level);                 //initializes board by reading from file
        void resetBoard();                                  //resets board
        void displayBoard();                                //displays level
        bool swap(int row1, int col1, int row2, int col2);  //swaps elements
        void generateCandy();                               //inserts new color into position in level
        void removeMatches(string color, int row, int col); //remove candies of similar color

        //getters
        int getRows();                      //get rows
        int getColumns();                   //get columns
        int getScore();                     //get level score
        candy getCandy(int row, int col);   //get a candy at a certain row,col

        //setters
        void setRows(int rows);     //set rows
        void setColumns(int col);   //set columns
        void setScore(int score);   //set level score

        //bools
        bool isOnBoard(int row, int col);                       //check if candy is on board
        bool isSameColor(int row, int col, int row2, int col2); //check if two candies are the same color
        bool isStar(int row, int col);                          //check if candy is color star
        bool isGift(int row, int col);                          //check if candy is color gift

};
#endif
