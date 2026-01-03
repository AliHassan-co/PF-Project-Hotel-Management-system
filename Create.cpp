#include "Room.h"
using namespace std;

void addRoom(vector<Room>& hotel) {
    Room r;
    cout << "Room No: "; cin >> r.roomNumber;
    cout << "Type (AC/Non-AC): "; cin >> r.type;
    cout << "Price: "; cin >> r.price;
    r.isBooked = 0;
    hotel.push_back(r);
    saveToFile(hotel);
    cout << "\n[Success] Room Added!";
}