Library Management System
A console-based Library Management System built in C, designed to simulate basic library operations for both admins and users.

Features:
Admin Panel
Password-protected admin access
Add new books (ID, title, author, description) saved to a file
Remove books by ID

 User Panel
Browse books by genre:
Psychological Thriller
Mystery
Non-fiction
Murder/Crime


Borrow a book from the available catalog

Built With
Language: C
Concepts: File I/O, structs, switch-case, string handling


Project Structure
librarymanagementsystem/
│
├── main.c        # Main source file
└── data.txt      # Book records (auto-generated on first add)

How to Run?
Clone the repository:
bash   git clone https://github.com/prakriti1132/librarymanagementsystem.git

Compile:
bash   gcc main.c -o library

Run:
bash   ./library

Admin password: adminlogin


Notes
Book data is stored in data.txt using pipe-separated format: ID|Title|Author|Description
Return book feature is under development
