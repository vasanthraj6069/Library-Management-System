# 📚 Library Management System

A **Library Management System** developed in **C** using **Singly Linked Lists** and **File Handling**. This menu-driven application helps manage library books efficiently by performing operations such as adding, displaying, searching, modifying, deleting, issuing, returning, saving, and loading book records. It demonstrates the practical implementation of **C programming, data structures, dynamic memory allocation, modular programming, and file handling**.

---

## 📌 Project Overview

This project is designed to automate basic library operations through a simple console-based interface. It provides an efficient way to maintain book records and demonstrates how linked lists and file handling can be used to build a real-world application in C.

---

## 🚀 Features

* ➕ Add New Book
* 📋 Display All Books
* 🔍 Search Book by ID/Title
* ✏️ Modify Book Details
* ❌ Delete Book Record
* 📖 Issue Book
* 📥 Return Book
* 📊 Sort Book Records
* 💾 Save Records to File
* 📂 Load Records from File
* 🖥️ Menu-Driven Interface

---

## 🛠️ Technologies Used

* C Programming
* GCC Compiler
* Linux
* Makefile
* Singly Linked List
* File Handling

---

## 📚 Concepts Covered

* Structures
* Pointers
* Dynamic Memory Allocation (`malloc`, `free`)
* Singly Linked List
* Functions
* Header Files
* Modular Programming
* File Handling (`fopen`, `fclose`, `fprintf`, `fscanf`)
* Linear Search
* Bubble Sort

---

## 📁 Project Structure

```text
LIBRARY-MANAGEMENT-SYSTEM/
│
├── main.c
├── header.h
├── add_book.c
├── display_book.c
├── search_book.c
├── modify_book.c
├── delete_book.c
├── issue_book.c
├── return_book.c
├── sort_book.c
├── save.c
├── load.c
├── Makefile
└── README.md
```

---

## 🔄 Work Process

```text
                       START
                         │
                         ▼
                Display Main Menu
                         │
                         ▼
                User Selects Option
                         │
      ┌────────────┬─────────────┬─────────────┐
      │            │             │             │
      ▼            ▼             ▼             ▼
   Add Book    Display Book   Search Book   Modify Book
      │            │             │             │
      └────────────┼─────────────┼─────────────┘
                   │
      ┌────────────┼─────────────┬─────────────┐
      ▼            ▼             ▼             ▼
 Delete Book   Issue Book   Return Book   Sort Books
                   │
                   ▼
             Save / Load File
                   │
                   ▼
                  Exit
```

---

## 📋 Sample Output

### Main Menu

```text
==========================================
        LIBRARY MANAGEMENT SYSTEM
==========================================

1. Add Book
2. Display Books
3. Search Book
4. Modify Book
5. Delete Book
6. Issue Book
7. Return Book
8. Sort Books
9. Save Records
10. Load Records
11. Exit

Enter your choice:
```

### Display Books

```text
+---------+--------------------------+-----------------+----------+
| Book ID | Book Name                | Author          | Status   |
+---------+--------------------------+-----------------+----------+
| B101    | Embedded C               |    Micheal j    | Available|
| B102    | C Programming            | Dennis Ritchie  | Issued   |
| B103    | Data Structures          | Mark Allen      | Available|
+---------+--------------------------+-----------------+----------+
```

---

## ⚙️ Compilation

### Using Makefile

```bash
make
```

### Manual Compilation

```bash
gcc *.c -o library
```

---

## ▶️ Run the Program

```bash
./library
```

---

## 🌟 Project Highlights

* ✔ Menu-Driven Application
* ✔ Singly Linked List Implementation
* ✔ Dynamic Memory Allocation
* ✔ File Handling (Save & Load)
* ✔ Book Issue & Return Management
* ✔ Sorting & Searching
* ✔ Modular Programming

---

## 🎯 Learning Outcomes

Through this project, I improved my understanding of:

* C Programming
* Data Structures
* Linked List Operations
* File Handling
* Dynamic Memory Allocation
* Modular Programming
* Linux Development Environment
* Debugging & Problem Solving

---

## 🚀 Future Enhancements

* User Login Authentication
* Fine Calculation for Late Returns
* Book Reservation System
* Student Membership Management
* Export Records to CSV
* Improved User Interface

Vasanth Kumar R

🎓 B.E. Electronics and Communication Engineering (2025)

💻 Embedded Systems Enthusiast

**GitHub:**
https://github.com/vasanthraj6069

**LinkedIn:**
https://www.linkedin.com/in/vasanth-kumar-r-a76044277

---

## 📄 License

This project is intended for **educational and learning purposes**. You are free to use, modify, and share it with proper credit.

---

## ⭐ Support




