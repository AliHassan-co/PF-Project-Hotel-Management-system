#include "Room.h"
using namespace std;

void bookRoom(vector<Room>& hotel) {
    int rNo;
    bool found = false;
    cout << "Enter Room Number to Book: "; cin >> rNo;
    for (auto &r : hotel) {
        if (r.roomNumber == rNo) {
            if (r.isBooked == 0) {
                r.isBooked = 1;
                saveToFile(hotel);
                cout << "\n[Success] Room Booked!";
            } else cout << "\n[Alert] Already Occupied!";
            found = true; break;
        }
    }
    if (!found) cout << "\n[Error] Room not found!";
}

void vacateRoom(vector<Room>& hotel) {
    int rNo;
    bool found = false;
    cout << "Enter Room Number to Vacate: "; cin >> rNo;
    for (auto &r : hotel) {
        if (r.roomNumber == rNo) {
            r.isBooked = 0;
            saveToFile(hotel);
            cout << "\n[Success] Room is now Available!";
            found = true; break;
        }
    }
    if (!found) cout << "\n[Error] Room not found!";
}