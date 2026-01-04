# PF-Project-Hotel-Management-system
## **1. Room.h (The Blueprint):**

This is a Header File. Think of it as the "Table of Contents" for your project.

Purpose: It tells every other .cpp file what the Room class looks like and what functions are available.

The Guard: The #ifndef ROOM\_H and #define ROOM\_H at the top prevent the compiler from getting confused if this file is included more than once.

Declarations: It contains the structure of your Room (room Number, type, etc.) and "prototypes" of your functions (like add Room).

#### **2. main.cpp (The Controller):**

This is the entry point of your program.

Logic: It contains the while(true) loop and the switch/if logic for your menu.

Role: Instead of doing the heavy lifting, it simply calls the functions defined in other files (e.g., when you press '1', it calls add Room (hotel)).

Data: It holds the vector<Room> hotel, which is the actual list where all your data lives while the program is running.

#### **3. Function.cpp (The Foundation):**

This file handles the "behind-the-scenes" work.

Room::display(): This is the logic that formats the output (using setw) so your room info looks like a clean table.

File Handling: It contains save To File and load From File. This is the most important part for data persistence, ensuring your hotel data isn't lost when you close the program.

##### **4. Create.cpp (The Input):**

Purpose: Dedicated to adding new data.

Logic: It asks the user for the Room Number, Type, and Price. It automatically sets is Booked to 0 (Available) because a new room record shouldn't start as booked.

Connection: It calls save To File at the end so the new room is immediately written to your text file.

##### **5. Read.cpp (The Viewer):**

Purpose: Dedicated to showing data without changing it.

View Rooms: It loops through the hotel vector and calls the .display() function for every room.

Search Room: It takes a user-inputted room number, compares it to the list, and shows only that specific room if it exists.

##### **6. Update.cpp (The Processor):**

Purpose: This handles the "Check-in" and "Check-out" logic.

Book Room: It finds a room and changes is Booked from 0 to 1.

Vacate Room: It changes is Booked back to 0.

Validation: It includes your original logic to check if a room is "Already Occupied" before letting someone book it.

##### **7. Delete.cpp (The Cleaner):**

Purpose: To remove a room from the system permanently.

Logic: It uses hotel.erase(). It searches for the index i of the room number you provided and removes that specific element from the vector.

Coming soon: LOGIN SYSTEM 
like Create id ,login id,
if they have already account sigup
THIS PROGRAME IS ADDED WITH HOTEL MANAGENMENT SYSTEM FOR JUST ADDED ROOM ,VIEW ROOM, SEARCH ALL ROOOM , CHECK IN AND CHECK OUT ROOM.

