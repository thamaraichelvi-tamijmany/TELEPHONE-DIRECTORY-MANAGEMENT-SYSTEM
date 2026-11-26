Telephone Directory in C

A console-based Telephone Directory application written in C that uses binary file handling (contacts.dat) to store, search, update, and delete contact records persistently.

Features

Add Record: Save new contacts with full names (including spaces) and phone numbers.

Display All Records: View a numbered list of all saved contacts in the directory.

Search by Name: Look up a contact's details using their full name.

Search by Phone: Quickly retrieve a contact using their phone number.

Update Record: Modify the name or phone number of an existing contact.

Delete Record: Remove a contact safely using temporary file replacement (temp.dat).

Input Safety: Protects against buffer overflows and handles invalid non-numeric menu inputs without crashing or looping infinitely.

Project Structure

telephone-directory/
├── main.c          # Source code for the telephone directory
├── contacts.dat    # Binary data file generated automatically at runtime
└── README.md       # Project documentation


Getting Started

Prerequisites

You need a C compiler installed on your system, such as GCC (MinGW on Windows, GCC on Linux, or Clang/Xcode Command Line Tools on macOS).

Compilation & Execution

Clone the repository:

git clone https://github.com/your-username/your-repo-name.git
cd your-repo-name


Compile the code:

gcc main.c -o directory


Run the program:

Linux / macOS:

./directory


Windows:

directory.exe


Usage

Once running, select an option from the interactive menu by entering the corresponding number (1–7):

--- TELEPHONE DIRECTORY ---
1. Add Record
2. Display All Records
3. Search by Name
4. Search by Phone
5. Update Record
6. Delete Record
7. Exit
Enter choice:

How Data Persistence Works

Contacts are stored as binary struct Contact blocks inside contacts.dat using fwrite() and fread().

Updating & Deleting: Because binary records cannot be resized or removed in place easily, updateRecord() and deleteRecord() write the modified dataset to temp.dat, remove the old contacts.dat, and rename temp.dat to contacts.dat.

License

This project is licensed under the MIT License - see the LICENSE file for details.
