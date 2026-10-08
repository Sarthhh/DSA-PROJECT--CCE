#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name, phone;
    Contact* next;
};

Contact* head = NULL;

void addContact() {
    Contact* newNode = new Contact;

    cout << "Enter Name: ";
    cin >> newNode->name;

    cout << "Enter Phone: ";
    cin >> newNode->phone;

    newNode->next = head;
    head = newNode;

    cout << "Contact Added!\n";
}

void display() {
    Contact* temp = head;

    if (temp == NULL) {
        cout << "No Contacts!\n";
        return;
    }

    while (temp != NULL) {
        cout << "Name: " << temp->name
             << " | Phone: " << temp->phone << endl;
        temp = temp->next;
    }
}

void searchContact() {
    string name;
    cout << "Enter Name: ";
    cin >> name;

    Contact* temp = head;

    while (temp != NULL) {
        if (temp->name == name) {
            cout << "Contact Found!\n";
            cout << "Name: " << temp->name
                 << " | Phone: " << temp->phone << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Contact Not Found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- Mobile Contact Management ---\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addContact(); break;
            case 2: display(); break;
            case 3: searchContact(); break;
            case 4: cout << "Thank You!\n"; break;
            default: cout << "Invalid Choice!\n";
        }
    } while (choice != 4);

    return 0;
}
