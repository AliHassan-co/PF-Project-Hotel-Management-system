#include "Room.h"
using namespace std;

int main() {
    vector<Room> hotel;
    loadFromFile(hotel);

    int choice;
    while (true) {
        cout << "\n=============================================";
        cout << "\n   HOTEL MANAGEMENT SYSTEM";
        cout << "\n=============================================";
        cout << "\n1. Add Room\n2. View All Rooms\n3. Search Room\n4. Book Room\n5. Vacate Room\n6. Delete Room\n7. Exit";
        cout << "\nSelection: ";
        cin >> choice;

        if (choice == 1) addRoom(hotel);
        else if (choice == 2) viewRooms(hotel);
        else if (choice == 3) searchRoom(hotel);
        else if (choice == 4) bookRoom(hotel);
        else if (choice == 5) vacateRoom(hotel);
        else if (choice == 6) deleteRoom(hotel);
        else if (choice == 7) break;
    }
    return 0;
}