#include "candyCrush.h"

using namespace std;
candyCrush::candyCrush() {
    //N/A
}

candyCrush::candyCrush(string levelName) {
    //resetBoard();
    initializeBoard(levelName);

}

/*
 * Algorithm: initializes the board from a file to make it easy to design a level and import it to the game
  * Create an ifstream object and pass in the file name
  * create a temporary string that stores the color of a candy
  * loop through artificial rows and columns and initialize a new candy at each location
  * parameters: level (string)
*/
void candyCrush::initializeBoard(string level) { //initializes board by reading from file
    ifstream levelDesign(level);
    string tempColor; //store color of candy

    for(int i = 0; i < rows; i++) { //loop through rows
        for(int k = 0; k < columns; k++) { //loop through columns
            levelDesign >> tempColor; //get color of candy in file
            board[i][k] = candy(tempColor, i, k); //initialize new candy
        }
    }
}
/*
void candyCrush::resetBoard() { //resets board to the same color (unnecessary)

    for(int i = 0; i < rows; i++) {
        for(int k = 0; k < columns; k++) {
            board[i][k] = candy('🐱‍🚀', i, k);
        }
    }
}
*/

/*
 * Algorithm: dipslays the candyCrush object as a board of rows and columns
 * loop i from 0 to nuber of rows and make sure i never reaches 10
 * loop k from 0 to number of columns and print out the color of each candy at each iteration
 * then print out the numbering for the columsn at the end
 * parameter: N/A
 * returns: nothing (void)
*/
void candyCrush::displayBoard() { //displays board

    for(int i = 0; i < rows; i++) { //loop through rows
        if(i < 10) { //check that i never reaches 10
            for(int k = 0; k < columns; k++) { //loop through columns
                cout << board[i][k].getColor(); //print color of candy
            }
            cout << "\n";
        }
    }
    cout <<"  1️⃣ 2️⃣ 3️⃣ 4️⃣ 5️⃣ 6️⃣ 7️⃣ 8️⃣ 9️⃣ 🔟" << endl; //print column numbering
}

/*
 * Algorithm: swaps a candy with a different candy on the board
 * Checks if both candies are on the board and both are modifiable
 * set a temp candy to the first candy then set the first candy to the second candy
 * set the second candy to the temp candy
 * parameters: row1 (int), col1 (int), row2 (int), col2 (int)
 * returns: bool - true if executed, false otherwise
*/
bool candyCrush::swap(int row1, int col1, int row2, int col2) { //swaps elements
    if((isOnBoard(row1, col1) && isOnBoard(row2, col2)) && 
       (board[row1][col1].isModifiableCandy() && board[row2][col2].isModifiableCandy())) //check for bounds and modifiablity
    {
        //swap candies in the specified locations
        candy temp = board[row1][col1]; 
        board[row1][col1] = board[row2][col2];
        board[row2][col2] = temp;
        return true;
    }
    else
        return false;

}

//generateColor() will create a new candy object in place of one that has moved or been deleted at (row, col)
//95% chance of regular color, 5% chance of special color
//parameters: N/A
//returns: nothing (void)
void candyCrush::generateCandy() {
    for(int i = 0; i < rows; i++) { //loop through rows
        if(i < 10) {
            for(int k = 0; k < columns; k++) { //loop through columsn
                if(board[i][k].getColor() == "⬛") { //check if color is black
                    if(isOnBoard(i, k)) { //check if candy is on board
                        int randNum = rand() % 100; //random number between 0-99
                        if (randNum < 95) {
                            randNum %= 4; //random number between 0-3
                            //change candy color randomly
                            switch(randNum) {
                                case 0:
                                    board[i][k] = candy("🟦", i, k);
                                    score++;
                                    break;
                                case 1:
                                    board[i][k] = candy("🟨", i, k);
                                    score++;
                                    break;
                                case 2:
                                    board[i][k] = candy("🟥", i, k);
                                    score++;
                                    break;
                                case 3:
                                    board[i][k] = candy("⬜", i, k);
                                    score++;
                                    break;
                                case 4:
                                    board[i][k] = candy("🟦", i, k);
                                    score++;
                                    break;
                                case 5:
                                    board[i][k] = candy("🟨", i, k);
                                    score++;
                                    break;
                                case 6:
                                    board[i][k] = candy("🟥", i, k);
                                    score++;
                                    break;
                                case 7:
                                    board[i][k] = candy("⬜", i, k);
                                    score++;
                                    break;
                                default:
                                    cout << "generation error" << endl;
                                    break;
                            }
                        }
                        else {
                            randNum %= 2; //random number between 0-1
                            switch(randNum) {
                                case 0:
                                    board[i][k] = candy("⭐", i, k);
                                    score++;
                                    break;
                                case 1:
                                    board[i][k] = candy("🎁", i, k);
                                    score++;
                                    break;
                                default:
                                    cout << "generation error" << endl;
                                    break;
                            }
                        }
                    }
                    else
                        return;
                }
            }
        }
    }
}

/* 
    removeMatches() checks if candy color matches or if it is a special candy
    removeMatches() uses recursion to check for every instance of matching colors until there are no more matches
    parameters: color (string), row (int), col (int)
    returns: nothing (void)
*/
void candyCrush::removeMatches(string color, int row, int col) {
    if (!isOnBoard(row, col)) { //make sure that the candy is on the board
        return;
    }
    else if(board[row][col].isModifiableCandy() == false) { //make sure the candy is modifiable
        return;
    }
    if (board[row][col].getColor() == color) {

        board[row][col].setColor("⬛");
        removeMatches(color, row + 1, col); // check for any other matches below the current candy
        removeMatches(color, row - 1, col); // check for any other matches above the current candy
        removeMatches(color, row, col + 1); // check for any other matches to the right of the current candy
        removeMatches(color, row, col - 1); // check for any other matches to the left of the current candy
    }
    else if(isStar(row,col)) { //check if candy is a star
        for(int i = 1; i < columns; i++) { //"remove" all candy in a row
            board[row][i].setColor("⬛");
        }
    }
    else if(isGift(row,col)) { //check if candy is a gift
        for(int i = 1; i < rows; i++) { //"remove" all candy in a column
            board[i][col].setColor("⬛");
        }
    }
    return;
}

//get total number of rows on board
int candyCrush::getRows() {
    return rows;

}
//get total number of columns on board
int candyCrush::getColumns() {
    return columns;

}
//get player's score fo the level
int candyCrush::getScore() {
    return score;

}
//set player's score for the level
void candyCrush::setScore(int new_score) {
    score = new_score;
}
//check if a candy is on the board
bool candyCrush::isOnBoard(int new_row, int new_col) {
    if(new_row < 0 || new_row > rows || new_col < 0 || new_col > columns)
        return false;
    else
        return true;
}
//checks if candy is same color
bool candyCrush::isSameColor(int row1, int col1, int row2, int col2) {
    if(board[row1][col1].getColor() == board[row2][col2].getColor())
        return true;
    else
        return false;
}
//checks if candy is a star
bool candyCrush::isStar(int row, int col) {
    if(board[row][col].getColor() == "⭐")
        return true;
    else
        return false;
}
//checks if candy is a gift
bool candyCrush::isGift(int row, int col) {
    if(board[row][col].getColor() == "🎁")
        return true;
    else
        return false;
}
//returns a candy at a given row,col
candy candyCrush::getCandy(int row, int col) {
    return board[row][col];
}
