/* Name: Rida Rahmani
Roll number: CO2123
Title: Dynamic Contact List Management Using Linked List 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact
{
    char name[50];
    char phone[20];
    struct Contact *next;
};

struct Contact *head = NULL;

// Insert at Beginning
void insertBeginning()
{
    struct Contact *newNode;

    newNode = (struct Contact *)malloc(sizeof(struct Contact));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter phone number: ");
    scanf(" %[^\n]", newNode->phone);

    newNode->next = head;
    head = newNode;

    printf("Contact inserted at beginning successfully.\n");
}

// Insert at End
void insertEnd()
{
    struct Contact *newNode, *temp;

    newNode = (struct Contact *)malloc(sizeof(struct Contact));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter phone number: ");
    scanf(" %[^\n]", newNode->phone);

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Contact inserted at end successfully.\n");
}

// Delete by Name
void deleteContact()
{
    char name[50];
    struct Contact *temp, *prev;

    if (head == NULL)
    {
        printf("Contact list is empty.\n");
        return;
    }

    printf("Enter name to delete: ");
    scanf(" %[^\n]", name);

    temp = head;

    // Delete first node
    if (strcmp(temp->name, name) == 0)
    {
        head = temp->next;
        free(temp);

        printf("Contact deleted successfully.\n");
        return;
    }

    prev = NULL;

    while (temp != NULL && strcmp(temp->name, name) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Contact not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Contact deleted successfully.\n");
}

// Search by Name
void searchContact()
{
    char name[50];
    struct Contact *temp;

    if (head == NULL)
    {
        printf("Contact list is empty.\n");
        return;
    }

    printf("Enter name to search: ");
    scanf(" %[^\n]", name);

    temp = head;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            printf("\nContact Found!\n");
            printf("Name  : %s\n", temp->name);
            printf("Phone : %s\n", temp->phone);
            return;
        }

        temp = temp->next;
    }

    printf("Contact not found.\n");
}

// Display All Contacts
void displayContacts()
{
    struct Contact *temp;

    if (head == NULL)
    {
        printf("Contact list is empty.\n");
        return;
    }

    temp = head;

    printf("\n----- Contact List -----\n");

    while (temp != NULL)
    {
        printf("Name  : %s\n", temp->name);
        printf("Phone : %s\n", temp->phone);
        printf("------------------------\n");

        temp = temp->next;
    }
}

// Free all nodes
void freeAll()
{
    struct Contact *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n===== CONTACT MANAGEMENT SYSTEM =====\n");
        printf("1. Insert Contact at Beginning\n");
        printf("2. Insert Contact at End\n");
        printf("3. Delete Contact by Name\n");
        printf("4. Search Contact by Name\n");
        printf("5. Display All Contacts\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                deleteContact();
                break;

            case 4:
                searchContact();
                break;

            case 5:
                displayContacts();
                break;

            case 6:
                freeAll();
                printf("All memory released.\n");
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

 return 0;
}
/* OUTPUT:

===== CONTACT MANAGEMENT SYSTEM =====
1. Insert Contact at Beginning
2. Insert Contact at End
3. Delete Contact by Name
4. Search Contact by Name
5. Display All Contacts
6. Exit
Enter your choice: 1
Enter name: Rida
Enter phone number: 7021204851
Contact inserted at beginning successfully.

===== CONTACT MANAGEMENT SYSTEM =====
1. Insert Contact at Beginning
2. Insert Contact at End
3. Delete Contact by Name
4. Search Contact by Name
5. Display All Contacts
6. Exit
Enter your choice: 2
Enter name: R.R
Enter phone number: 7021305456
Contact inserted at end successfully.

===== CONTACT MANAGEMENT SYSTEM =====
1. Insert Contact at Beginning
2. Insert Contact at End
3. Delete Contact by Name
4. Search Contact by Name
5. Display All Contacts
6. Exit
Enter your choice: 5

----- Contact List -----
Name  : Rida
Phone : 7021204851
------------------------
Name  : R.R
Phone : 7021305456
------------------------

===== CONTACT MANAGEMENT SYSTEM =====
1. Insert Contact at Beginning
2. Insert Contact at End
3. Delete Contact by Name
4. Search Contact by Name
5. Display All Contacts
6. Exit
Enter your choice: 4 3
Enter name to delete: R.R
Contact deleted successfully.

===== CONTACT MANAGEMENT SYSTEM =====
1. Insert Contact at Beginning
2. Insert Contact at End
3. Delete Contact by Name
4. Search Contact by Name
5. Display All Contacts
6. Exit
Enter your choice: 4
Enter name to search: Rida

Contact Found!
Name  : Rida
Phone : 7021204851

===== CONTACT MANAGEMENT SYSTEM =====
1. Insert Contact at Beginning
2. Insert Contact at End
3. Delete Contact by Name
4. Search Contact by Name
5. Display All Contacts
6. Exit
Enter your choice: 5

----- Contact List -----
Name  : Rida
Phone : 7021204851
------------------------

===== CONTACT MANAGEMENT SYSTEM =====
1. Insert Contact at Beginning
2. Insert Contact at End
3. Delete Contact by Name
4. Search Contact by Name
5. Display All Contacts
6. Exit
Enter your choice: 6
All memory released.
Program terminated.

*/
