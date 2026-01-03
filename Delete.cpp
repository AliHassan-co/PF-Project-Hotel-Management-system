#include "Room.h"
using namespace std;

void deleteRoom(vector<Room>& hotel) {
    int rNo;
    cout << "Delete Room Number: "; cin >> rNo;
    for (int i = 0; i < hotel.size(); i++) {
        if (hotel[i].roomNumber == rNo) {
            hotel.erase(hotel.begin() + i);
            saveToFile(hotel);
            cout << "\n[Success] Record Deleted!";
            break;
        }
    }
}