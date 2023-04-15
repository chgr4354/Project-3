#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void vectorSplit(string filename, const char delimiter, vector<string>& data) {
    ifstream file(filename);

    if(!file.fail()) {
        string line;
        while(getline(file, line)) {
            string value;
            for(int i = 0; i < line.size(); i++) {
                char ch = line[i];
                if(ch == delimiter) {
                    data.push_back(value);
                    value.clear();
                }
                else
                    value.push_back(ch);
            }
            if (!value.empty()) {
                data.push_back(value);
            }
        }
    }
    else
        cout << "vectorSplit - failed to open \"" << filename << "\"" << endl;

}