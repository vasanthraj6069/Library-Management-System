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


void removeBook()
{
    int i;
    int j;
    int id;
    int found = 0;

    char choice;
    char name[100];


    printf("\n");
    printf("========================================\n");
    printf("             REMOVE BOOK\n");
    printf("========================================\n");

    printf("A. By Book ID\n");
    printf("B. By Book Name\n");
    printf("C. Back to Main Menu\n");

    printf("Enter your choice: ");
    scanf(" %c", &choice);


    switch(choice)
    {
        /* =========================
           REMOVE BY BOOK ID
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

                    printf("Book ID  : %d\n", books[i].book_id);
                    printf("Title    : %s\n", books[i].title);
                    printf("Author   : %s\n", books[i].author);
                    printf("Quantity : %d\n", books[i].quantity);

                    /* Shift remaining books */

                    for(j = i; j < book_count - 1; j++)
                    {
                        books[j] = books[j + 1];
                    }

                    book_count--;

                    printf("\nBook removed successfully!\n");

                    break;
                }
            }

            if(found == 0)
            {
                printf("\nBook ID not found!\n");
            }

            break;


        /* =========================
           REMOVE BY BOOK NAME
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

                    printf("Book ID  : %d\n", books[i].book_id);
                    printf("Title    : %s\n", books[i].title);
                    printf("Author   : %s\n", books[i].author);
                    printf("Quantity : %d\n", books[i].quantity);

                    /* Shift remaining books */

                    for(j = i; j < book_count - 1; j++)
                    {
                        books[j] = books[j + 1];
                    }

                    book_count--;

                    printf("\nBook removed successfully!\n");

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
