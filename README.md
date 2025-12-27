# Bus Reservation System in C 🚌

A simple **console-based Bus Reservation System** implemented in **C**, supporting seat booking, cancellation, and persistent storage using file handling.

This project demonstrates **structures, file I/O, arrays, and menu-driven programming** in C.

---
## Features
- Fixed number of bus seats (32 seats)
- Display seat availability
- Book a seat with passenger name
- Cancel seat booking
- Persistent storage using binary file
- Data automatically saved and loaded (`bus_data.dat`)
- Menu-driven user interface

---
## 🛠️ Technologies Used
- **Language:** C
- **Concepts:**
  - Structures (`struct`)
  - File Handling (`fread`, `fwrite`)
  - Arrays
  - String handling
  - Menu-driven programs

---

## 📂 Project Structure
├── bus_reservation.c
├── bus_data.dat (auto-generated)
└── README.md

## 💾 Data Persistence

All bookings are saved in:
bus_data.dat
Data is automatically loaded when the program starts
Prevents data loss between program runs

## 💻 Sample Menu
===== BUS RESERVATION SYSTEM =====
1. Display Seats
2. Book Seat
3. Cancel Booking
4. Exit
Enter your choice:


## 🚀 How to Build & Run
### 🔧 Requirements
- GCC compiler
- Windows / Linux / macOS

### 🧱 Compile

gcc bus_reservation.c -o bus


## 🧠 Learning Outcomes

-Real-world use of file handling
-Managing records using structures
-Input validation
-Persistent data storage
-Modular programming in C

## 👤 Author
Gaurav Patel
Embedded Software Engineer | C++ | Systems Programming

