# Hotel_booking-billing_system

Hotel Booking & Billing System (C Project)

A simple yet functional console-based Hotel Booking & Billing System built in C.
This program uses file handling (binary files) to store booking records and provides a complete CRUD system along with automated bill generation.

 Features

 Add Booking

Create a new booking with customer name, room number, number of days, and price per day.

 View All Bookings

Displays all saved bookings from the binary file (bookings.dat).

 Update Booking

Modify details of an existing booking by entering its ID.

 Delete Booking

Removes a booking by ID using a temporary replacement file.

 Generate Bill

Calculates and prints the total bill for any booking based on:

Total = Days Stayed × Price Per Day

 Data Structure Used
typedef struct {
    int id;
    char name[50];
    int roomNo;
    int days;
    float pricePerDay;
} Booking;

 Files Used
File	Purpose
bookings.dat	Main storage file for all bookings (binary format)
temp.dat	Temporary file used during deletion
 How to Compile and Run
On Linux / macOS
gcc hotel.c -o hotel
./hotel

On Windows (MinGW)
gcc hotel.c -o hotel.exe
hotel.exe

 Project Structure
 Hotel-Booking-System
 ┣ hotel.c
 ┣  README.md
 ┣  bookings.dat   (auto-created when the program runs)
 ┗  temp.dat        (used only during deletion)

 Program Menu
==== HOTEL BOOKING & BILLING SYSTEM ====
1. Add Booking
2. View Bookings
3. Update Booking
4. Delete Booking
5. Generate Bill
6. Exit
Enter your choice:

 Example Bill Output
===== HOTEL BILL =====
Name         : John Smith
Room Number  : 204
Days Stayed  : 3
Rate/Day     : 1500.00
---------------------------
TOTAL AMOUNT : 4500.00

 Notes

Enter valid input values to avoid unexpected behavior.

Records are permanently saved in bookings.dat unless deleted.

You may enhance this program by:

Adding validations

Sorting bookings

Adding a search function

Improving UI formatting

 Screenshots

Add your screenshot here:

<img width="242" height="116" alt="image" src="https://github.com/user-attachments/assets/c011327f-3ffb-4a6c-9fec-957c8b3ca6ac" />

<img width="239" height="214" alt="image" src="https://github.com/user-attachments/assets/a92d0594-c74c-4d70-9e45-cd0114fbdee8" />

<img width="391" height="181" alt="image" src="https://github.com/user-attachments/assets/c0d57a88-25c9-4759-ac22-d686120e7a0e" />

<img width="262" height="212" alt="image" src="https://github.com/user-attachments/assets/f50e4b0b-dcca-4fb1-85cd-60f260339081" />

<img width="248" height="235" alt="image" src="https://github.com/user-attachments/assets/2f8b90c0-af10-41f7-a65d-98694b1d3d47" />

<img width="239" height="121" alt="image" src="https://github.com/user-attachments/assets/86a35970-c475-4447-a661-74c969b872da" />
