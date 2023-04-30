#include "vectorSplit.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

/*
 * Algorithm: Splits a file into a vector of strings by locating delimiters in the file.
 * Open the file using an ifstream object
 * Read through the file one line at a time using a while loop
 * For each line, create a string variable to store the current value.
 * Iterate through the characters in the line, and if the current character is the delimiter, add the current value to the vector and clear the value variable.
 * If the value variable is not empty, add it to the vector.
 * Close the file.
 * parameters: filename (string), delimeter (const char), data (vector<string>)
 * returns: nothing (void)
*/

void vectorSplit(string filename, const char delimiter, vector<string>& data) {
    ifstream file(filename); //create ifstream object

    if(!file.fail()) { //check that file can be opened
        string line;
        while(getline(file, line)) { //while there are new lines in the file
            string value;
            for(int i = 0; i < line.size(); i++) { //loop through the line of the file
                char ch = line[i];
                if(ch == delimiter) { //check for delimieter
                    data.push_back(value); //add section to vector
                    value.clear(); //reset value
                }
                else
                    value.push_back(ch); //
            }
            if (!value.empty()) { //if value has been assigned, add value to data vector
                data.push_back(value);
            }
        }
    }
    
    else //file could not be opened
        cout << "vectorSplit - failed to open \"" << filename << "\"" << endl;
    file.close(); //close file
}
