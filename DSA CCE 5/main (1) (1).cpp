#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name, phone, email;
    Contact *next;
};

Contact *head = NULL;

void addContact() {
    Contact *n = new Contact;

    cout << "Enter Name: ";
    getline(cin, n->name);
    cout << "Enter Phone: ";
    getline(cin, n->phone);
    cout << "Enter Email: ";
    getline(cin, n->email);

    n->next = NULL;

    if (head == NULL)
        head = n;
    else {
        Contact *t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = n;
    }
    cout << "Contact Added Successfully!\n";
}

void display() {
    Contact *t = head;

    if (t == NULL)
        cout << "No Contacts Found!\n";

    while (t != NULL) {
        cout << "\nName: " << t->name;
        cout << "\nPhone: " << t->phone;
        cout << "\nEmail: " << t->email << "\n";
        t = t->next;
    }
}

void searchContact() {
    string p;
    cout << "Enter Phone Number: ";
    getline(cin, p);

    Contact *t = head;
    while (t != NULL) {
        if (t->phone == p) {
            cout << "Name: " << t->name;
            cout << "\nEmail: " << t->email << "\n";
            return;
        }
        t = t->next;
    }
    cout << "Contact Not Found!\n";
}

void deleteContact() {
    string p;
    cout << "Enter Phone to Delete: ";
    getline(cin, p);

    Contact *t = head, *prev = NULL;

    while (t != NULL && t->phone != p) {
        prev = t;
        t = t->next;
    }

    if (t == NULL) {
        cout << "Contact Not Found!\n";
        return;
    }

    if (prev == NULL)
        head = t->next;
    else
        prev->next = t->next;

    delete t;
    cout << "Contact Deleted!\n";
}

int main() {
    int ch;

    do {
        cout << "\n--- CONTACT MANAGEMENT ---\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";

        cin >> ch;
        cin.ignore(1000, '\n');

        switch (ch) {
            case 1: addContact(); break;
            case 2: display(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 0: cout << "Program Ended!\n"; break;
            default: cout << "Invalid Choice!\n";
        }
    } while (ch != 0);

    while (head != NULL) {
        Contact *t = head;
        head = head->next;
        delete t;
    }

    return 0;
}
