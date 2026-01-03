#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include <string>

class Room {
public:
    int roomNumber;
    std::string type;
    double price;
    int isBooked; 

    void display();
};


void saveToFile(const std::vector<Room>& hotel);
void loadFromFile(std::vector<Room>& hotel);
void addRoom(std::vector<Room>& hotel);
void viewRooms(std::vector<Room>& hotel);
void searchRoom(std::vector<Room>& hotel);
void bookRoom(std::vector<Room>& hotel);
void vacateRoom(std::vector<Room>& hotel);
void deleteRoom(std::vector<Room>& hotel);

#endif