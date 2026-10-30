# Mobile Contact Management System

## Objective
To develop a simple mobile contact management system using a singly linked list in C++.

## Software Required
- Dev-C++
- C++ compiler

## Features
1. Add a contact
2. Display all contacts
3. Search a contact by phone number
4. Delete a contact by phone number
5. Exit the program

## Data Structure
Each `Contact` node stores:
- Name
- Phone number
- Email address
- Pointer to the next contact (`next`)

The pointer `head` stores the address of the first node in the linked list.

## How to Run in Dev-C++
1. Open Dev-C++.
2. Select **File > New > Source File**.
3. Paste the C++ program into the editor.
4. Save the file as `contact.cpp`.
5. Select **Execute > Compile & Run** or press **F11**.

## Menu Options
- `1` — Add Contact
- `2` — Display Contacts
- `3` — Search Contact
- `4` — Delete Contact
- `0` — Exit

## Working
- **Add:** Creates a new node and adds it to the end of the list.
- **Display:** Traverses the list and prints every contact.
- **Search:** Finds a contact by matching its phone number.
- **Delete:** Removes the matching node and reconnects the list.
- **Exit:** Frees the allocated nodes before ending the program.

## Time Complexity
Let `n` be the number of contacts.

| Operation | Time Complexity |
|---|---|
| Add Contact | O(n) |
| Display Contacts | O(n) |
| Search Contact | O(n) |
| Delete Contact | O(n) |

## Limitation
Contacts are stored in memory only. They are lost when the program exits.

## Conclusion
This project demonstrates how a singly linked list can be used to add, display, search, and delete mobile contacts dynamically in C++.
