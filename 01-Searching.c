/*Title:Implement array operations and searching
Name: Rida Rahmani
Roll number: CO2123*/

#include <stdio.h>
//Marks Display
void display(int arr[20], int n)
{
    int i;

    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Marks: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

//Marks Insertion
void insertMark(int arr[20], int *n)
{
    int position, mark, i;

    if (*n == 20)
    {
        printf("Array is full. Cannot insert.\n");
        return;
    }

    printf("Enter position to insert (1 to %d): ", *n + 1);
    scanf("%d", &position);

    if (position < 1 || position > *n + 1)
    {
        printf("Invalid position.\n");
        return;
    }

    printf("Enter mark: ");
    scanf("%d", &mark);
for (i = *n; i >= position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position - 1] = mark;
    (*n)++;

    printf("Mark inserted successfully.\n");
}

//Marks Deletion
void deleteMark(int arr[20], int *n)
{
    int position, i;

    if (*n == 0)
    {
        printf("Array is empty. Cannot delete.\n");
        return;
    }

    printf("Enter position to delete (1 to %d): ", *n);
    scanf("%d", &position);

    if (position < 1 || position > *n)
    {
        printf("Invalid position.\n");
        return;
    }

    for (i = position - 1; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    (*n)--;

    printf("Mark deleted successfully.\n");
}

//
void linearSearch(int arr[20], int n)
{
    int key, i, found = 0;

    printf("Enter mark to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("Mark %d found at position %d.\n", key, i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Mark not found.\n");
    }
}

//Sorting using bubble sort
void bubbleSort(int arr[20], int n)
{
    int i, j, temp;

    for (i = 0; i < n ; i++)
    {
        for (j = 0; j < n - i ; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
//Searching using Binary Search
void binarySearch(int arr[20], int n)
{
    int key, low, high, mid;
    int found = 0;

    bubbleSort(arr, n);

    printf("Array sorted in ascending order.\n");
    display(arr, n);

    printf("Enter mark to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            printf("Mark %d found at position %d.\n",
                   key, mid + 1);
            found = 1;
            break;
        }
        else if (key > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

 if (!found)
    {
        printf("Mark not found.\n");
    }
}


int main()
{
    int arr[20];
    int n, i, choice;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n < 0 || n > 20)
    {
        printf("Invalid number of students.\n");
        return 0;
    }

    printf("Enter marks of %d students:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\nARRAY OPERATIONS MENU\n");
        printf("1. Insert Mark\n");
        printf("2. Delete Mark\n");
        printf("3. Display Marks\n");
        printf("4. Linear Search\n");
        printf("5. Sort and Binary Search\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertMark(arr, &n);
                break;

            case 2:
                deleteMark(arr, &n);
                break;

            case 3:
                display(arr, n);
                break;

            case 4:
                linearSearch(arr, n);
                break;

            case 5:
                if (n == 0)
                {
                    printf("Array is empty.\n");
                }
                else
                {
                    binarySearch(arr, n);
                }
                break;

            case 6:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

return 0;
}

/* Output:
student@TCOERCL-VI-15:~$ cc pr1.c
student@TCOERCL-VI-15:~$ ./a.out
Enter number of students: 5
Enter marks of 5 students:
30
70
80
60
40

ARRAY OPERATIONS MENU
1. Insert Mark
2. Delete Mark
3. Display Marks
4. Linear Search
5. Sort and Binary Search
6. Exit
Enter your choice: 1
Enter position to insert (1 to 6): 1
Enter mark: 20
Mark inserted successfully.

ARRAY OPERATIONS MENU
1. Insert Mark
2. Delete Mark
3. Display Marks
4. Linear Search
5. Sort and Binary Search
6. Exit
Enter your choice: 3
Marks: 20 30 70 80 60 40 

ARRAY OPERATIONS MENU
1. Insert Mark
2. Delete Mark
3. Display Marks
4. Linear Search
5. Sort and Binary Search
6. Exit
Enter your choice: 2
Enter position to delete (1 to 6): 6
Mark deleted successfully.

ARRAY OPERATIONS MENU
1. Insert Mark
2. Delete Mark
3. Display Marks
4. Linear Search
5. Sort and Binary Search
6. Exit
Enter your choice: 3
Marks: 20 30 70 80 60 

ARRAY OPERATIONS MENU
1. Insert Mark
2. Delete Mark
3. Display Marks
4. Linear Search
5. Sort and Binary Search
6. Exit
Enter your choice: 4
Enter mark to search: 70
Mark 70 found at position 3.

ARRAY OPERATIONS MENU
1. Insert Mark
2. Delete Mark
3. Display Marks
4. Linear Search
5. Sort and Binary Search
6. Exit
Enter your choice: 5
Array sorted in ascending order.
Marks: 20 30 40 60 70 
Enter mark to search: 70
Mark 70 found at position 5.

ARRAY OPERATIONS MENU
1. Insert Mark
2. Delete Mark
3. Display Marks
4. Linear Search
5. Sort and Binary Search
6. Exit
Enter your choice: 6
Program terminated.

*/