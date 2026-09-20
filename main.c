#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

/* Structure to store book details */
struct Book
{
    int id;
    char title[50];
    char author[50];
    int quantity;
};

/* Structure to store issued book details */
struct Issue
{
    int bookId;
    char issuer[50];
};

/* Arrays of structures */
struct Book library[MAX];
struct Issue issued[MAX];

/* Global counters */
int count = 0;
int issueCount = 0;

/* Function Prototypes */
int findBook(int id);
void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
void deleteBook();
void editBook();

/* Search book by ID */
int findBook(int id)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (library[i].id == id)
            return i;
    }

    return -1;
}

/* Add Book */
void addBook()
{
    int id;
    int valid = 0;

    /* Check if library is full */
    if (count >= MAX)
    {
        printf("Library is full!\n");
        return;
    }

    /* Keep asking until unique and valid ID is entered */
    while (!valid)
    {
        printf("Enter Book ID: ");

        /* Validate integer input */
        if (scanf("%d", &id) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n')
                ; /* clear input buffer */
            continue;
        }

        /* Check for duplicate ID */
        if (findBook(id) != -1)
        {
            printf("Error: Book ID already exists! Try a different ID.\n");
        }
        else
        {
            valid = 1; /* valid unique ID */
        }
    }

    library[count].id = id;

    while (getchar() != '\n')
        ; /* Removes leftover Enter key from buffer */

    printf("Enter Book Title: ");
    fgets(library[count].title, 50, stdin);
    library[count].title[strcspn(library[count].title, "\n")] = '\0';

    printf("Enter Author Name: ");
    fgets(library[count].author, 50, stdin);
    library[count].author[strcspn(library[count].author, "\n")] = '\0';

    printf("Enter Quantity: ");
    scanf("%d", &library[count].quantity);

    count++;

    printf("Book Added Successfully!\n");
}

/* Display Books */
void displayBooks()
{
    int i;

    if (count == 0)
    {
        printf("No Books Available!\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        printf("\nBook ID  : %d", library[i].id);
        printf("\nTitle    : %s", library[i].title);
        printf("\nAuthor   : %s", library[i].author);
        printf("\nQuantity : %d\n", library[i].quantity);
    }
}

/* Search Book */
void searchBook()
{
    int id, index;

    printf("Enter Book ID: ");
    scanf("%d", &id);

    index = findBook(id);

    if (index == -1)
        printf("Book Not Found!\n");
    else
    {
        printf("\nBook Found!\n");
        printf("Book ID  : %d\n", library[index].id);
        printf("Title    : %s\n", library[index].title);
        printf("Author   : %s\n", library[index].author);
        printf("Quantity : %d\n", library[index].quantity);
    }
}

/* Issue Book */
void issueBook()
{
    int id, index;

    printf("Enter Book ID: ");
    scanf("%d", &id);
    getchar();

    index = findBook(id);

    if (index == -1)
    {
        printf("Book Not Found!\n");
        return;
    }

    if (library[index].quantity <= 0)
    {
        printf("Book Out of Stock!\n");
        return;
    }

    if (issueCount >= MAX)
    {
        printf("Issue record limit reached!\n");
        return;
    }

    printf("Enter Issuer Name: ");
    fgets(issued[issueCount].issuer, 50, stdin);
    issued[issueCount].issuer[strcspn(issued[issueCount].issuer, "\n")] = '\0';

    issued[issueCount].bookId = id;

    library[index].quantity--;
    issueCount++;

    printf("Book Issued Successfully!\n");
}

/* Return Book */
void returnBook()
{
    int id, index;

    printf("Enter Book ID: ");
    scanf("%d", &id);

    index = findBook(id);

    if (index == -1)
    {
        printf("Book Not Found!\n");
        return;
    }

    library[index].quantity++;

    printf("Book Returned Successfully!\n");
}

/* Delete Book */
void deleteBook()
{
    int id, index, i;

    printf("Enter Book ID: ");
    scanf("%d", &id);

    index = findBook(id);

    if (index == -1)
    {
        printf("Book Not Found!\n");
        return;
    }

    for (i = index; i < count - 1; i++)
        library[i] = library[i + 1];

    count--;

    printf("Book Deleted Successfully!\n");
}

/* Edit Book */
void editBook()
{
    int id, index, choice;

    printf("Enter Book ID to Edit: ");
    scanf("%d", &id);

    index = findBook(id);

    if (index == -1)
    {
        printf("Book Not Found!\n");
        return;
    }

    printf("\n1. Edit Title");
    printf("\n2. Edit Author");
    printf("\n3. Edit Quantity");
    printf("\nEnter Choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
        case 1:
            printf("Enter New Title: ");
            fgets(library[index].title, 50, stdin);
            library[index].title[strcspn(library[index].title, "\n")] = '\0';
            break;

        case 2:
            printf("Enter New Author: ");
            fgets(library[index].author, 50, stdin);
            library[index].author[strcspn(library[index].author, "\n")] = '\0';
            break;

        case 3:
            printf("Enter New Quantity: ");
            scanf("%d", &library[index].quantity);
            break;

        default:
            printf("Invalid Choice!\n");
            return;
    }

    printf("Book Updated Successfully!\n");
}

/* Main Function */
int main()
{
    int choice;

    while (1)
    {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====");
        printf("\n1. Add Book");
        printf("\n2. Display Books");
        printf("\n3. Search Book");
        printf("\n4. Issue Book");
        printf("\n5. Return Book");
        printf("\n6. Delete Book");
        printf("\n7. Edit Book");
        printf("\n8. Exit");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                deleteBook();
                break;

            case 7:
                editBook();
                break;

            case 8:
                printf("Thank You!\n");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
