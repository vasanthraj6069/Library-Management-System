#include <stdio.h>
#include <string.h>

struct Book
{
    int book_id;
    char title[100];
    char author[100];
    int quantity;
};

struct Issue
{
    int issue_id;
    int book_id;
    int user_id;
    char user_name[100];

    char issue_date[11];
    char due_date[11];
    char return_date[11];

    int fine;
    int returned;
};

extern struct Book books[100];
extern struct Issue issues[100];

extern int book_count;
extern int issue_count;


void listBooks()
{
    int i;
    int j;
    int book_index;

    printf("\n");
    printf("====================================================================================\n");
    printf("                              ISSUED BOOKS\n");
    printf("====================================================================================\n");

    if(issue_count == 0)
    {
        printf("No issued books available!\n");
        return;
    }

    printf("%-8s %-8s %-18s %-10s %-15s %-12s %-12s %-15s %-8s\n",
           "IssueID",
           "BookID",
           "Book Name",
           "UserID",
           "User Name",
           "Issue Date",
           "Due Date",
           "Return Date",
           "Fine");

    printf("------------------------------------------------------------------------------------\n");


    for(i = 0; i < issue_count; i++)
    {
        book_index = -1;

        /* Find book using Book ID */

        for(j = 0; j < book_count; j++)
        {
            if(books[j].book_id == issues[i].book_id)
            {
                book_index = j;
                break;
            }
        }

        if(book_index != -1)
        {
            printf("%-8d %-8d %-18s %-10d %-15s %-12s %-12s %-15s Rs.%d\n",

                   issues[i].issue_id,

                   issues[i].book_id,

                   books[book_index].title,

                   issues[i].user_id,

                   issues[i].user_name,

                   issues[i].issue_date,

                   issues[i].due_date,

                   issues[i].return_date,

                   issues[i].fine);
        }
    }

    printf("====================================================================================\n");
}
