#include <stdio.h>

struct Book
{
    int book_id;
    char title[100];
    char author[100];
    int quantity;
};

extern struct Book books[100];
extern int book_count;

void showBook()
{
    int i;

    printf("\n");
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                           ALL BOOKS                                         |\n");
    printf("+-----------------------------------------------------------------------------+\n");

    if(book_count == 0)
    {
        printf("|                       No books available!                                   |\n");
        printf("+-----------------------------------------------------------------------------+\n");
        return;
    }

    printf("| %-8s | %-25s | %-25s | %-8s |\n", "Book ID", "Title", "Author", "Quantity");
    printf("+----------+---------------------------+---------------------------+----------+\n");

    for(i = 0; i < book_count; i++)
    {
        printf("| %-8d | %-25.25s | %-25.25s | %-8d |\n", books[i].book_id, books[i].title, books[i].author, books[i].quantity);
        printf("+----------+---------------------------+---------------------------+----------+\n");
    }

    printf("\nTotal Books: %d\n", book_count);
    printf("================================================================================\n");
}
