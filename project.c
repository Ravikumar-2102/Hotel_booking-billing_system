#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "bookings.dat"

// Booking structure
typedef struct {
    int id;
    char name[50];
    int roomNo;
    int days;
    float pricePerDay;
} Booking;

// Function prototypes
void addBooking();
void viewBookings();
void updateBooking();
void deleteBooking();
void generateBill();

// MAIN FUNCTION
int main() {
    int choice;

    while (1) {
        printf("\n==== HOTEL BOOKING & BILLING SYSTEM ====\n");
        printf("1. Add Booking\n");
        printf("2. View Bookings\n");
        printf("3. Update Booking\n");
        printf("4. Delete Booking\n");
        printf("5. Generate Bill\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBooking(); break;
            case 2: viewBookings(); break;
            case 3: updateBooking(); break;
            case 4: deleteBooking(); break;
            case 5: generateBill(); break;
            case 6: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// ADD BOOKING
void addBooking() {
    FILE *fp = fopen(FILE_NAME, "ab");
    Booking b;

    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("\n=== ADD BOOKING ===\n");

    printf("Enter Booking ID: ");
    scanf("%d", &b.id);

    printf("Enter Name: ");
    scanf(" %[^\n]", b.name);

    printf("Enter Room Number: ");
    scanf("%d", &b.roomNo);

    printf("Enter Number of Days: ");
    scanf("%d", &b.days);

    printf("Enter Price per Day: ");
    scanf("%f", &b.pricePerDay);

    fwrite(&b, sizeof(Booking), 1, fp);
    fclose(fp);

    printf("Booking Added Successfully!\n");
}

// VIEW ALL BOOKINGS
void viewBookings() {
    FILE *fp = fopen(FILE_NAME, "rb");
    Booking b;

    if (!fp) {
        printf("No bookings found or error opening file!\n");
        return;
    }

    printf("\n=== BOOKING LIST ===\n");

    while (fread(&b, sizeof(Booking), 1, fp)) {
        printf("ID: %d | Name: %s | Room: %d | Days: %d | Price/Day: %.2f\n",
               b.id, b.name, b.roomNo, b.days, b.pricePerDay);
    }

    fclose(fp);
}

// UPDATE BOOKING
void updateBooking() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    Booking b;
    int id, found = 0;

    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Booking ID to update: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(Booking), 1, fp)) {
        if (b.id == id) {
            found = 1;

            printf("\n=== UPDATE BOOKING ===\n");

            printf("Enter new name: ");
            scanf(" %[^\n]", b.name);

            printf("Enter new room number: ");
            scanf("%d", &b.roomNo);

            printf("Enter new number of days: ");
            scanf("%d", &b.days);

            printf("Enter new price per day: ");
            scanf("%f", &b.pricePerDay);

            fseek(fp, -sizeof(Booking), SEEK_CUR);
            fwrite(&b, sizeof(Booking), 1, fp);

            printf("Booking Updated Successfully!\n");
            break;
        }
    }

    if (!found)
        printf("Booking ID not found!\n");

    fclose(fp);
}

// DELETE BOOKING
void deleteBooking() {
    FILE *fp = fopen(FILE_NAME, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    Booking b;
    int id, found = 0;

    if (!fp || !temp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Booking ID to delete: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(Booking), 1, fp)) {
        if (b.id == id) {
            found = 1;
        } else {
            fwrite(&b, sizeof(Booking), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found)
        printf("Booking Deleted Successfully!\n");
    else
        printf("Booking ID not found!\n");
}

// GENERATE BILL
void generateBill() {
    FILE *fp = fopen(FILE_NAME, "rb");
    Booking b;
    int id, found = 0;

    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Booking ID for Bill: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(Booking), 1, fp)) {
        if (b.id == id) {
            found = 1;

            float total = b.days * b.pricePerDay;

            printf("\n===== HOTEL BILL =====\n");
            printf("Name         : %s\n", b.name);
            printf("Room Number  : %d\n", b.roomNo);
            printf("Days Stayed  : %d\n", b.days);
            printf("Rate/Day     : %.2f\n", b.pricePerDay);
            printf("---------------------------\n");
            printf("TOTAL AMOUNT : %.2f\n", total);

            break;
        }
    }

    if (!found)
        printf("Booking ID not found!\n");

    fclose(fp);
}
