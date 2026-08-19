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


void searchBook()
{
    int i;
    int id;
    int found = 0;

    char choice;
    char name[100];
    char author[100];


    printf("\n");
    printf("========================================\n");
    printf("              SEARCH BOOK\n");
    printf("========================================\n");

    printf("A. By Book ID\n");
    printf("B. By Book Name\n");
    printf("C. By Author Name\n");
    printf("D. Back to Main Menu\n");

    printf("Enter your choice: ");
    scanf(" %c", &choice);


    switch(choice)
    {
        /* =========================
           SEARCH BY BOOK ID
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

                    printf("Book ID  : %d\n",
                           books[i].book_id);

                    printf("Title    : %s\n",
                           books[i].title);

                    printf("Author   : %s\n",
                           books[i].author);

                    printf("Quantity : %d\n",
                           books[i].quantity);

                    printf("-------------------------\n");

                    break;
                }
            }

            if(found == 0)
            {
                printf("\nBook ID not found!\n");
            }

            break;


        /* =========================
           SEARCH BY BOOK NAME
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

                    printf("Book ID  : %d\n",
                           books[i].book_id);

                    printf("Title    : %s\n",
                           books[i].title);

                    printf("Author   : %s\n",
                           books[i].author);

                    printf("Quantity : %d\n",
                           books[i].quantity);

                    printf("-------------------------\n");

                    break;
                }
            }

            if(found == 0)
            {
                printf("\nBook Name not found!\n");
            }

            break;


        /* =========================
           SEARCH BY AUTHOR NAME
           ========================= */

        case 'C':
        case 'c':

            printf("\nEnter Author Name: ");
            scanf(" %[^\n]", author);

            for(i = 0; i < book_count; i++)
            {
                if(strcmp(books[i].author, author) == 0)
                {
                    found = 1;

                    printf("\nBook Found!\n");
                    printf("-------------------------\n");

                    printf("Book ID  : %d\n",
                           books[i].book_id);

                    printf("Title    : %s\n",
                           books[i].title);

                    printf("Author   : %s\n",
                           books[i].author);

                    printf("Quantity : %d\n",
                           books[i].quantity);

                    printf("-------------------------\n");

                    break;
                }
            }

            if(found == 0)
            {
                printf("\nAuthor Name not found!\n");
            }

            break;


        /* =========================
           BACK
           ========================= */

        case 'D':
        case 'd':

            printf("\nBack to Main Menu\n");

            break;


        default:

            printf("\nInvalid choice!\n");
    }
}
