#include "candyCrush.h"

using namespace std;

candyCrush::candyCrush(string levelName) {
    //resetBoard();
    initializeBoard(levelName);

}

void candyCrush::initializeBoard(string level) { //initializes board by reading from file
    ifstream levelDesign(level);
    char tempColor;

    for(int i = 0; i < rows; i++) {
        for(int k = 0; k < columns; k++) {
            levelDesign >> tempColor;
            board[i][k] = candy(tempColor, i, k);
        }
    }
}
/*
void candyCrush::resetBoard() { //resets board to the same color (possibly unnecessary?)

    for(int i = 0; i < rows; i++) {
        for(int k = 0; k < columns; k++) {
            board[i][k] = candy('🐱‍🚀', i, k);
        }
    }
}
*/
void candyCrush::displayBoard() { //displays board

    for(int i = 0; i < rows; i++) {
        for(int k = 0; k < columns; k++) {
            cout << board[i][k].getColor();
        }
        cout << "\n";
    }
}  

bool candyCrush::swap(int row1, int col1, int row2, int col2) { //swaps elements
    if((isOnBoard(row1, col1) && isOnBoard(row2, col2)) && 
       (board[row1][col1].isModifiableCandy() && board[row2][col2].isModifiableCandy())) 
       {
        candy temp = board[row1][col1];
        board[row1][col1] = board[row2][col2];
        board[row2][col2] = temp;
        return true;
        //displayBoard();
    }
    else
        return false;

}

//generateColor() will create a new candy object in place of one that has moved or been deleted at (row, col)
//80% chance of regular color, 20% chance of special color
//***call srand() function in main***
void candyCrush::generateCandy(int row, int col) {
    int randNum = rand() % 10;
    switch(randNum) {
        case 0:
            board[row][col] = candy('🟦', row, col);
            break;
        case 1:
            board[row][col] = candy('🟩', row, col);
            break;
        case 2:
            board[row][col] = candy('🟥', row, col);
            break;
        case 3:
            board[row][col] = candy('⬜', row, col);
            break;
        case 4:
            board[row][col] = candy('🟦', row, col);
            break;
        case 5:
            board[row][col] = candy('🟩', row, col);
            break;
        case 6:
            board[row][col] = candy('🟥', row, col);
            break;
        case 7:
            board[row][col] = candy('⬜', row, col);
            break;
        case 8:
            board[row][col] = candy('⭐', row, col);
            break;
        case 9:
            board[row][col] = candy('🎁', row, col);
            break;
        default:
            cout << "generation error" << endl;
            break;
    }
}

/* removeMatches() will check if candy color matches or it is a special candy using isSameColor()
   removeMatches() will use recursion to check for every instance of matching colors until there are no more matches
   removeMatches() will assign each matched location to 
*/
void candyCrush::removeMatches() {
    

}

int candyCrush::getRows() {
    return rows;

}
int candyCrush::getColumns() {
    return columns;

}
int candyCrush::getScore() {
    return score;

}
void candyCrush::setScore(int new_score) {
    score = new_score;
}

bool candyCrush::isOnBoard(int new_row, int new_col) {
    if(new_row > 0 || new_row < rows || new_col > 0 || new_col < columns)
        return true;
    else
        return false;
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
    if(board[row][col].getColor() == '⭐')
        return true;
    else
        return false;
}
//checks if candy is a gift
bool candyCrush::isGift(int row, int col) {
    if(board[row][col].getColor() == '🎁')
        return true;
    else
        return false;
}
