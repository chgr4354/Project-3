#include <cassert>
#include "candy.h"

int main() {

    //default constructor
    candy candy1;
    assert(candy1.getColor() == "-");
    assert(candy1.getRow() == 0);
    assert(candy1.getColumn() == 0);
    
    //parameterized constructor
    candy candy2("🟦", 5, 6);
    assert(candy2.getColor() == "🟦");
    assert(candy2.getColumn() == 6);
    assert(candy2.getRow() == 5);
    assert(candy2.isModifiableCandy() == true);
    assert(candy2.isSpecialCandy() == false);

    //test setters
    candy2.setColor("⭐");
    assert(candy2.getColor() == "⭐");
    assert(candy2.isSpecialCandy() == true);
    assert(candy2.isModifiableCandy() == true);

    candy2.setAll("🟨", 2, 3);
    assert(candy2.getRow() == 2);
    assert(candy2.getColumn() == 3);
    assert(candy2.getColor() == "🟨");

    candy2.setRow(8);
    assert(candy2.getRow() == 8);
    candy2.setColumn(1);
    assert(candy2.getColumn() == 1);

}