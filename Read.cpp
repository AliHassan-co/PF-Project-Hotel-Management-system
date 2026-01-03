#include "Room.h"
#include <iomanip>
using namespace std;

void viewRooms(vector<Room>& hotel) {
    cout << "\n---------------------------------------------------" << endl;
    cout << left << setw(12) << "Room No." << setw(12) << "Type" << setw(10) << "Price" << setw(12) << "Status" << endl;
    cout << "---------------------------------------------------" << endl;
    for (auto &r : hotel) r.display();
}

void searchRoom(vector<Room>& hotel) {
    int rNo;
    bool found = false;
    cout << "Enter Room Number to Search: "; cin >> rNo;
    for (auto &r : hotel) {
        if (r.roomNumber == rNo) {
            cout << "\n--- Room Found ---" << endl;
            r.display();
            found = true; break;
        }
    }
    if (!found) cout << "\n[Error] Room not found!";
}