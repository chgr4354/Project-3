#ifndef ROOM_H
#define ROOM_H

using namespace std;

class Room {
    private:
        int level_number; //Level 1 2 or 3 in room with same diff
        int room_position[2]; //Location of room on map

    public:
        Room();
        Room(int level_number, int row, int col);

        int getLevelNumber();
        int getRoomRow();
        int getRoomCol();

        void setLevelNumber(int level);
        void setRoomPosition(int row, int col);

        

};
#endif