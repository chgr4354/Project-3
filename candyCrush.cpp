#include "candyCrush.h"

using namespace std;
candyCrush::candyCrush() {
    //N/A
}

candyCrush::candyCrush(string levelName) {
    //resetBoard();
    initializeBoard(levelName);

}

void candyCrush::initializeBoard(string level) { //initializes board by reading from file
    ifstream levelDesign(level);
    string tempColor;

    for(int i = 0; i < rows; i++) {
        for(int k = 0; k < columns; k++) {
            levelDesign >> tempColor;
            board[i][k] = candy(tempColor, i, k);
        }
    }
}
/*
void candyCrush::resetBoard() { //resets board to the same color (possibly unnecessary)

    for(int i = 0; i < rows; i++) {
        for(int k = 0; k < columns; k++) {
            board[i][k] = candy('🐱‍🚀', i, k);
        }
    }
}
*/
void candyCrush::displayBoard() { //displays board

    for(int i = 0; i < rows; i++) {
        if(i < 10) {
            for(int k = 0; k < columns; k++) {
                cout << board[i][k].getColor();
            }
            cout << "\n";
        }
    }
    cout <<"  1️⃣ 2️⃣ 3️⃣ 4️⃣ 5️⃣ 6️⃣ 7️⃣ 8️⃣ 9️⃣ 🔟" << endl;
}  

bool candyCrush::swap(int row1, int col1, int row2, int col2) { //swaps elements
    if((isOnBoard(row1, col1) && isOnBoard(row2, col2)) && 
       (board[row1][col1].isModifiableCandy() && board[row2][col2].isModifiableCandy())) 
    {
        candy temp = board[row1][col1];
        board[row1][col1] = board[row2][col2];
        board[row2][col2] = temp;
        return true;
    }
    else
        return false;

}

//generateColor() will create a new candy object in place of one that has moved or been deleted at (row, col)
//80% chance of regular color, 20% chance of special color
//***call srand() function in main***
void candyCrush::generateCandy() {

    for(int i = 0; i < rows; i++) {
        if(i < 10) {
            for(int k = 0; k < columns; k++) {
                if(board[i][k].getColor() == "⬛") {
                    if(isOnBoard(i, k)) {
                        int randNum = rand() % 10;
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
                            case 8:
                                board[i][k] = candy("⭐", i, k);
                                score++;
                                break;
                            case 9:
                                board[i][k] = candy("🎁", i, k);
                                score++;
                                break;
                            default:
                                cout << "generation error" << endl;
                                break;
                        }
                    }
                    else
                        return; //***change return value for debugging in future
                }
            }
        }
    }
}

/* removeMatches() will check if candy color matches or it is a special candy using isSameColor()
   removeMatches() will use recursion to check for every instance of matching colors until there are no more matches
*/
void candyCrush::removeMatches(string color, int row, int col) {
    if (!isOnBoard(row, col)) {
        return;
    }
    else if(board[row][col].isModifiableCandy() == false) {
        return;
    }
    if (board[row][col].getColor() == color) {
        board[row][col].setColor("⬛");
        score++;
        removeMatches(color, row + 1, col); // check for any other matches below the current candy
        removeMatches(color, row - 1, col); // check for any other matches above the current candy
        removeMatches(color, row, col + 1); // check for any other matches to the right of the current candy
        removeMatches(color, row, col - 1); // check for any other matches to the left of the current candy
    }
    return;
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


candy candyCrush::getCandy(int row, int col) {
    return board[row][col];
}
