#include "Room.h"

Room::Room() {
    level_number = 0;
    room_position[0] = 0;
    room_position[1] = 0;

}
Room::Room(int new_level_number, int row, int col) {
    level_number = new_level_number;
    room_position[0] = row;
    room_position[1] = col;

}

int Room::getLevelNumber() {
    return level_number;
}
int Room::getRoomRow() {
    return room_position[0];
}
int Room::getRoomCol() {
    return room_position[1];
}

void Room::setLevelNumber(int level) {
    level_number = level;
}
void Room::setRoomPosition(int row, int col) {
    room_position[0] = row;
    room_position[1] = col;
}