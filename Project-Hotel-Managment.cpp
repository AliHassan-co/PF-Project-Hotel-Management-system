#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Room {
public:
    int roomNumber;
    string type;
    double price;
    int isBooked; // 0: Available, 1: Booked

    void display() {
        string status = (isBooked == 1) ? "Booked" : "Available";
        cout << left << setw(12) << roomNumber 
             << setw(12) << type 
             << setw(10) << price 
             << setw(12) << status << endl;
    }
};

// File operations
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

int main() {
    vector<Room> hotel;
    loadFromFile(hotel);

    int choice;
    while (true) {
        cout << "\n=============================================";
        cout << "\n   HOTEL MANAGEMENT SYSTEM (FINAL)";
        cout << "\n=============================================";
        cout << "\n1. Add Room";
        cout << "\n2. View All Rooms";
        cout << "\n3. Search Room";
        cout << "\n4. Book Room (Check-in)";
        cout << "\n5. Vacate Room (Check-out)";
        cout << "\n6. Delete Room Record";
        cout << "\n7. Exit";
        cout << "\nSelection: ";
        cin >> choice;

        if (choice == 1) {
            Room r;
            cout << "Room No: "; cin >> r.roomNumber;
            cout << "Type (AC/Non-AC): "; cin >> r.type;
            cout << "Price: "; cin >> r.price;
            r.isBooked = 0;
            hotel.push_back(r);
            saveToFile(hotel);
            cout << "\n[Success] Room Added!";

        } else if (choice == 2) {
            cout << "\n---------------------------------------------------" << endl;
            cout << left << setw(12) << "Room No." << setw(12) << "Type" << setw(10) << "Price" << setw(12) << "Status" << endl;
            cout << "---------------------------------------------------" << endl;
            for (auto &r : hotel) r.display();

        } else if (choice == 3) {
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

        } else if (choice == 4) {
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

        } else if (choice == 5) {
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

        } else if (choice == 6) {
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

        } else if (choice == 7) {
            break;
        }
    }
    return 0;
}




