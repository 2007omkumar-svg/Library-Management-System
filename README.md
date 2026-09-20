# Library Management System

A simple **Library Management System in C** using structures, arrays, functions, and a menu-driven interface.

## Features

- Add a new book
- Display all books
- Search for a book by ID
- Issue a book
- Return a book
- Delete a book
- Edit book title, author, or quantity
- Validate duplicate Book IDs
- Check book availability before issuing
- Menu-driven console interface

## Concepts Used

- C structures (`struct`)
- Arrays of structures
- Functions and function prototypes
- Loops and conditional statements
- `switch-case`
- String handling with `fgets()` and `strcspn()`
- Input validation
- Searching using Book ID

## How to Run

### GCC

```bash
gcc main.c -o library
./library
```

### Windows

```bash
gcc main.c -o library.exe
library.exe
```

## Menu

```text
===== LIBRARY MANAGEMENT SYSTEM =====
1. Add Book
2. Display Books
3. Search Book
4. Issue Book
5. Return Book
6. Delete Book
7. Edit Book
8. Exit
```

## Project Structure

```text
library-management-system/
├── main.c
└── README.md
```

## Source

The code was formatted from the uploaded `PPC_MP_CODE (2).pdf`, which contains the Library Management System implementation across 6 pages.
