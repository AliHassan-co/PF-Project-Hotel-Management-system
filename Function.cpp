#include "Room.h"
#include <fstream>
#include <iomanip>
using namespace std;

void Room::display() {
    string status = (isBooked == 1) ? "Booked" : "Available";
    cout << left << setw(12) << roomNumber 
         << setw(12) << type 
         << setw(10) << price 
         << setw(12) << status << endl;
}

void saveToFile(const vector<Room>& hotel) {
    ofstream outFile("hotel_data.txt");
    for (const auto& r : hotel) {
        outFile << r.roomNumber << " " << r.type << " " << r.price << " " << r.isBooked << endl;
    }
    outFile.close();
}

void loadFromFile(vector<Room>& hotel) {
    ifstream inFile("hotel_data.txt");
    if (!inFile) return; 
    Room temp;
    hotel.clear();
    while (inFile >> temp.roomNumber >> temp.type >> temp.price >> temp.isBooked) {
        hotel.push_back(temp);
    }
    inFile.close();
}