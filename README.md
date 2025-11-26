# Hotel_booking-billing_system

Hotel Booking & Billing System (C Project)

A simple yet functional console-based Hotel Booking & Billing System built in C.
This program uses file handling (binary files) to store booking records and provides a complete CRUD system along with automated bill generation.

📌 Features
✔️ Add Booking

Create a new booking with customer name, room number, number of days, and price per day.

✔️ View All Bookings

Displays all saved bookings from the binary file (bookings.dat).

✔️ Update Booking

Modify details of an existing booking by entering its ID.

✔️ Delete Booking

Removes a booking by ID using a temporary replacement file.

✔️ Generate Bill

Calculates and prints the total bill for any booking based on:

Total = Days Stayed × Price Per Day

🧱 Data Structure Used
typedef struct {
    int id;
    char name[50];
    int roomNo;
    int days;
    float pricePerDay;
} Booking;

📁 Files Used
File	Purpose
bookings.dat	Main storage file for all bookings (binary format)
temp.dat	Temporary file used during deletion
▶️ How to Compile and Run
On Linux / macOS
gcc hotel.c -o hotel
./hotel

On Windows (MinGW)
gcc hotel.c -o hotel.exe
hotel.exe

📂 Project Structure
📦 Hotel-Booking-System
 ┣ 📜 hotel.c
 ┣ 📜 README.md
 ┣ 📜 bookings.dat   (auto-created when the program runs)
 ┗ 📜 temp.dat        (used only during deletion)

🖥️ Program Menu
==== HOTEL BOOKING & BILLING SYSTEM ====
1. Add Booking
2. View Bookings
3. Update Booking
4. Delete Booking
5. Generate Bill
6. Exit
Enter your choice:

🧪 Example Bill Output
===== HOTEL BILL =====
Name         : John Smith
Room Number  : 204
Days Stayed  : 3
Rate/Day     : 1500.00
---------------------------
TOTAL AMOUNT : 4500.00

📌 Notes

Enter valid input values to avoid unexpected behavior.

Records are permanently saved in bookings.dat unless deleted.

You may enhance this program by:

Adding validations

Sorting bookings

Adding a search function

Improving UI formatting

📜 License

This project is open-source and free to use, modify, and distribute.

🖼️ Screenshot

Add your screenshot here:

![Program Screenshot](screenshots/sample.png)
