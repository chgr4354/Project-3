#include <iostream>

using namespace std;

class Armor {

    private:
        string name;
        string story;
        int protection;
    
    public:
        Armor();
        Armor(string name, int protection, string story);

        string getName();
        string getStory();
        int getProtection();

        void setName(string name);
        void setStory(string story);
        void setProtection(int protection);

};