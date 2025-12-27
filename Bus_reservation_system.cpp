#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 32
#define MAX_NAME 50
#define DATA_FILE "bus_data.dat"

typedef struct {
    int seat_no;
    int booked;           // 0 = available, 1 = booked
    char passenger[MAX_NAME];
} Seat;

Seat bus[MAX_SEATS];

/* Initialize seats */
void initBus() {
    for (int i = 0; i < MAX_SEATS; i++) {
        bus[i].seat_no = i + 1;
        bus[i].booked = 0;
        strcpy(bus[i].passenger, "Empty");
    }
}

/* Save data to file */
void saveData() {
    FILE *fp = fopen(DATA_FILE, "wb");
    if (fp == NULL) {
        printf("Error saving data!\n");
        return;
    }
    fwrite(bus, sizeof(Seat), MAX_SEATS, fp);
    fclose(fp);
}

/* Load data from file */
void loadData() {
    FILE *fp = fopen(DATA_FILE, "rb");
    if (fp == NULL) {
        initBus(); // If file not found, start fresh
        return;
    }
    fread(bus, sizeof(Seat), MAX_SEATS, fp);
    fclose(fp);
}

/* Display seat layout */
void displaySeats() {
    printf("\n--- Bus Seat Layout ---\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        printf("Seat %2d : %s\n",
               bus[i].seat_no,
               bus[i].booked ? bus[i].passenger : "Available");
    }
}

/* Book a seat */
void bookSeat() {
    int seat;
    char name[MAX_NAME];

    printf("\nEnter seat number to book (1-%d): ", MAX_SEATS);
    scanf("%d", &seat);

    if (seat < 1 || seat > MAX_SEATS) {
        printf("Invalid seat number!\n");
        return;
    }

    if (bus[seat - 1].booked) {
        printf("Seat %d is already booked by %s.\n",
               seat, bus[seat - 1].passenger);
    } else {
        printf("Enter passenger name: ");
        scanf(" %[^\n]", name);

        bus[seat - 1].booked = 1;
        strcpy(bus[seat - 1].passenger, name);

        printf("Seat %d booked successfully for %s.\n", seat, name);
        saveData();
    }
}

/* Cancel booking */
void cancelBooking() {
    int seat;

    printf("\nEnter seat number to cancel booking: ");
    scanf("%d", &seat);

    if (seat < 1 || seat > MAX_SEATS) {
        printf("Invalid seat number!\n");
        return;
    }

    if (!bus[seat - 1].booked) {
        printf("Seat %d is not booked yet.\n", seat);
    } else {
        printf("Booking cancelled for %s (Seat %d).\n",
               bus[seat - 1].passenger, seat);

        bus[seat - 1].booked = 0;
        strcpy(bus[seat - 1].passenger, "Empty");
        saveData();
    }
}

int main() {
    int choice;

    loadData(); // Load saved bookings

    while (1) {
        printf("\n===== BUS RESERVATION SYSTEM =====\n");
        printf("1. Display Seats\n");
        printf("2. Book Seat\n");
        printf("3. Cancel Booking\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                bookSeat();
                break;
            case 3:
                cancelBooking();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
