#ifndef CANDY_H
#define CANDY_H

#include <iostream>

using namespace std;

class candy {
    private:
        string color;       //color of candy
        bool isSpecial;     //if candy is special color
        bool isModifiable;  //if candy is modifiable
        int rowLocation;    //row location of candy
        int columnLocation; //column location of candy

    public:
        candy();                                        //default constructor
        candy(string color, int row, int column);       //parameterized constructor
        string getColor();                              //get color
        int getRow();                                   //get row
        int getColumn();                                //get column

        void setColor(string color);                    //set color
        void setRow(int row);                           //set row
        void setColumn(int column);                     //set column
        void setAll(string color, int row, int column); //set color,row,column
        void move(char direction);                      //move candy - not necessary
        bool isSpecialCandy();                          //is special color
        bool isModifiableCandy();                       //is modifiable

};
#endif
