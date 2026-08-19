#include <stdio.h>

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


void addBook()
{
    int i;
    int j;
    int new_id;
    int id_exists;


    printf("\n");
    printf("========================================\n");
    printf("              ADD NEW BOOK\n");
    printf("========================================\n");


    if(book_count >= 100)
    {
        printf("Book storage is full!\n");
        return;
    }


    /* =================================
       GENERATE SMALLEST AVAILABLE ID
       ================================= */

    new_id = 1;

    while(1)
    {
        id_exists = 0;

        for(i = 0; i < book_count; i++)
        {
            if(books[i].book_id == new_id)
            {
                id_exists = 1;
                break;
            }
        }

        if(id_exists == 0)
        {
            break;
        }

        new_id++;
    }


    /* Store automatically generated ID */

    books[book_count].book_id = new_id;


    printf("Book ID: %d\n", new_id);


    /* Book Name */

    printf("Enter Book Name: ");
    scanf(" %[^\n]", books[book_count].title);


    /* Author Name */

    printf("Enter Author Name: ");
    scanf(" %[^\n]", books[book_count].author);


    /* Quantity */

    printf("Enter Quantity: ");
    scanf("%d", &books[book_count].quantity);


    if(books[book_count].quantity < 0)
    {
        printf("\nInvalid quantity!\n");
        return;
    }


    /* Increase book count */

    book_count++;


    printf("\nBook added successfully!\n");


    printf("\nBook Details\n");
    printf("-------------------------\n");

    printf("Book ID  : %d\n",
           books[book_count - 1].book_id);

    printf("Title    : %s\n",
           books[book_count - 1].title);

    printf("Author   : %s\n",
           books[book_count - 1].author);

    printf("Quantity : %d\n",
           books[book_count - 1].quantity);

    printf("-------------------------\n");
}
