#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

void addContact(Contact contacts[], int *numContacts);
void displayContacts(const Contact contacts[], int numContacts);
void searchContact(const Contact contacts[], int numContacts);

int main() {
    Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;

    do {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                displayContacts(contacts, numContacts);
                break;
            case 3:
                searchContact(contacts, numContacts);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addContact(Contact contacts[], int *numContacts) {
    if (*numContacts >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", contacts[*numContacts].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[*numContacts].phone);
    (*numContacts)++;
    printf("Contact added successfully!\n");
}

void displayContacts(const Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("No contacts to display.\n");
        return;
    }
    printf("\nContact List:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
    }
}

void searchContact(const Contact contacts[], int numContacts) {
    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Contact found: Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}
