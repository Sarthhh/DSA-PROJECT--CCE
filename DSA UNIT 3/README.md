Mobile Contact Manager – Detailed Information
1. Project Description

Mobile Contact Manager is a C++ based application designed to store and manage mobile contact information. The system provides different operations such as adding, searching, updating, deleting, and displaying contacts. It provides a simple menu-driven interface that makes contact management easy and efficient.

2. Input (IP)

The following inputs are provided by the user:

Contact Name – Name of the person.
Mobile Number – Phone number of the contact.
Email Address – Email ID of the contact.
User Choice – Operation selected from the menu:
Add Contact
Search Contact
Update Contact
Delete Contact
Display Contacts
Exit

Example Input:

Enter Name: Rahul
Enter Mobile Number: 9876543210
Enter Email: rahul@gmail.com
3. Output (OP)

The system produces the following outputs:

Successfully added contact
Displayed list of contacts
Search result for a particular contact
Updated contact details
Deleted contact confirmation
"Contact not found" message when the requested contact does not exist
Exit/termination message

Example Output:

Contact Added Successfully!

Name   : Rahul
Mobile : 9876543210
Email  : rahul@gmail.com
4. Detailed Algorithm
Step 1: Start

Start the Mobile Contact Manager program.

Step 2: Initialize Contact Storage

Create a data structure such as an array, structure, class, or linked list to store contact information.

Each contact can contain:

Name
Mobile number
Email
Step 3: Display Menu

Display the available operations:

===== MOBILE CONTACT MANAGER =====
1. Add Contact
2. Search Contact
3. Update Contact
4. Delete Contact
5. Display All Contacts
6. Exit
Step 4: Get User Choice

Ask the user to select an operation.

Step 5: Add Contact

If the user selects Add Contact:

Enter the contact name.
Enter the mobile number.
Enter the email address.
Store the information.
Display "Contact Added Successfully."
Step 6: Search Contact

If the user selects Search Contact:

Ask for the contact name or mobile number.
Compare it with the stored contacts.
If a match is found, display the complete contact details.
If no match is found, display "Contact Not Found."
Step 7: Update Contact

If the user selects Update Contact:

Ask for the contact name or number.
Search for the contact.
If the contact exists, ask for the new details.
Update the stored information.
Display "Contact Updated Successfully."
If the contact does not exist, display "Contact Not Found."
Step 8: Delete Contact

If the user selects Delete Contact:

Ask for the contact name or number.
Search for the contact.
If found, remove the contact from storage.
Display "Contact Deleted Successfully."
If not found, display "Contact Not Found."
Step 9: Display All Contacts

If the user selects Display Contacts:

Check whether contacts are available.
If contacts exist, display all contact details.
If there are no contacts, display "No Contacts Available."
Step 10: Repeat

After completing an operation, display the menu again.

Step 11: Exit

If the user selects Exit, terminate the program.

Step 12: Stop

End the program.
