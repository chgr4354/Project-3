#include <iostream>

using namespace std;

class Food {

    private:
        string name;
        int recover;

    public:
        Food();
        Food(string name, int recover);

        string getName();
        int getRecover();

        void setName(string name);
        void setRecover(int points);

};