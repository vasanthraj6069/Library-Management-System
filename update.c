#include <stdio.h>
#include <string.h>

struct Book
{
    int book_id;
    char title[100];
    char author[100];
    int quantity;
};

/* Shared data from library.c */

extern struct Book books[100];
extern int book_count;


void updateBook()
{
    int i;
    int id;
    int found = 0;

    char choice;
    char name[100];

    printf("\n");
    printf("========================================\n");
    printf("          UPDATE BOOK DETAILS\n");
    printf("========================================\n");
    printf("Search a book using:\n");

    printf("A. By Book ID\n");
    printf("B. By Book Name\n");
    printf("C. Back to Main Menu\n");

    printf("Enter your choice: ");
    scanf(" %c", &choice);


    switch(choice)
    {
        /* =========================
           UPDATE BY BOOK ID
           ========================= */

        case 'A':
        case 'a':

            printf("\nEnter Book ID: ");
            scanf("%d", &id);

            for(i = 0; i < book_count; i++)
            {
                if(books[i].book_id == id)
                {
                    found = 1;

                    printf("\nBook Found!\n");
                    printf("-------------------------\n");

                    printf("Book ID  : %d\n", books[i].book_id);
                    printf("Title    : %s\n", books[i].title);
                    printf("Author   : %s\n", books[i].author);
                    printf("Quantity : %d\n", books[i].quantity);

                    printf("-------------------------\n");

                    /* Update Field Menu */

                    printf("\nWhat do you want to update?\n");
                    printf("1. Book Name\n");
                    printf("2. Author Name\n");
                    printf("3. Quantity\n");
                    printf("4. Cancel\n");

                    printf("Enter your choice: ");
                    scanf("%d", &id);

                    switch(id)
                    {
                        case 1:

                            printf("Enter New Book Name: ");
                            scanf(" %[^\n]", books[i].title);

                            printf("\nBook Name updated successfully!\n");

                            break;


                        case 2:

                            printf("Enter New Author Name: ");
                            scanf(" %[^\n]", books[i].author);

                            printf("\nAuthor Name updated successfully!\n");

                            break;


                        case 3:

                            printf("Enter New Quantity: ");
                            scanf("%d", &books[i].quantity);

                            if(books[i].quantity < 0)
                            {
                                printf("\nInvalid quantity!\n");
                                return;
                            }

                            printf("\nQuantity updated successfully!\n");

                            break;


                        case 4:

                            printf("\nUpdate cancelled.\n");

                            break;


                        default:

                            printf("\nInvalid choice!\n");
                    }

                    if(id >= 1 && id <= 3)
                    {
                        printf("\nUpdated Book Details\n");
                        printf("-------------------------\n");

                        printf("Book ID  : %d\n", books[i].book_id);
                        printf("Title    : %s\n", books[i].title);
                        printf("Author   : %s\n", books[i].author);
                        printf("Quantity : %d\n", books[i].quantity);

                        printf("-------------------------\n");
                    }

                    break;
                }
            }

            if(found == 0)
            {
                printf("\nBook ID not found!\n");
            }

            break;


        /* =========================
           UPDATE BY BOOK NAME
           ========================= */

        case 'B':
        case 'b':

            printf("\nEnter Book Name: ");
            scanf(" %[^\n]", name);

            for(i = 0; i < book_count; i++)
            {
                if(strcmp(books[i].title, name) == 0)
                {
                    found = 1;

                    printf("\nBook Found!\n");
                    printf("-------------------------\n");

                    printf("Book ID  : %d\n", books[i].book_id);
                    printf("Title    : %s\n", books[i].title);
                    printf("Author   : %s\n", books[i].author);
                    printf("Quantity : %d\n", books[i].quantity);

                    printf("-------------------------\n");

                    /* Update Field Menu */

                    printf("\nWhat do you want to update?\n");
                    printf("1. Book Name\n");
                    printf("2. Author Name\n");
                    printf("3. Quantity\n");
                    printf("4. Cancel\n");

                    printf("Enter your choice: ");
                    scanf("%d", &id);

                    switch(id)
                    {
                        case 1:

                            printf("Enter New Book Name: ");
                            scanf(" %[^\n]", books[i].title);

                            printf("\nBook Name updated successfully!\n");

                            break;


                        case 2:

                            printf("Enter New Author Name: ");
                            scanf(" %[^\n]", books[i].author);

                            printf("\nAuthor Name updated successfully!\n");

                            break;


                        case 3:

                            printf("Enter New Quantity: ");
                            scanf("%d", &books[i].quantity);

                            if(books[i].quantity < 0)
                            {
                                printf("\nInvalid quantity!\n");
                                return;
                            }

                            printf("\nQuantity updated successfully!\n");

                            break;


                        case 4:

                            printf("\nUpdate cancelled.\n");

                            break;


                        default:

                            printf("\nInvalid choice!\n");
                    }

                    if(id >= 1 && id <= 3)
                    {
                        printf("\nUpdated Book Details\n");
                        printf("-------------------------\n");

                        printf("Book ID  : %d\n", books[i].book_id);
                        printf("Title    : %s\n", books[i].title);
                        printf("Author   : %s\n", books[i].author);
                        printf("Quantity : %d\n", books[i].quantity);

                        printf("-------------------------\n");
                    }

                    break;
                }
            }

            if(found == 0)
            {
                printf("\nBook Name not found!\n");
            }

            break;


        /* =========================
           BACK
           ========================= */

        case 'C':
        case 'c':

            printf("\nBack to Main Menu\n");

            break;


        default:

            printf("\nInvalid choice!\n");
    }
}
