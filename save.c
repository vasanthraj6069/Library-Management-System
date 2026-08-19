#include <stdio.h>

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

/* Data defined in library.c */

extern struct Book books[100];
extern struct Issue issues[100];

extern int book_count;
extern int issue_count;


void saveBook()
{
    FILE *book_fp;
    FILE *issue_fp;

    int i;


    printf("\n");
    printf("========================================\n");
    printf("             SAVE DATA\n");
    printf("========================================\n");


    /* =========================
       SAVE BOOK DATA
       ========================= */

    book_fp = fopen("books.txt", "w");

    if(book_fp == NULL)
    {
        printf("Unable to open books.txt!\n");
        return;
    }


    for(i = 0; i < book_count; i++)
    {
        fprintf(book_fp,
                "%d|%s|%s|%d\n",
                books[i].book_id,
                books[i].title,
                books[i].author,
                books[i].quantity);
    }


    fclose(book_fp);


    /* =========================
       SAVE ISSUE DATA
       ========================= */

    issue_fp = fopen("issues.txt", "w");

    if(issue_fp == NULL)
    {
        printf("Unable to open issues.txt!\n");
        return;
    }


    for(i = 0; i < issue_count; i++)
    {
        fprintf(issue_fp,
                "%d|%d|%d|%s|%s|%s|%s|%d|%d\n",

                issues[i].issue_id,

                issues[i].book_id,

                issues[i].user_id,

                issues[i].user_name,

                issues[i].issue_date,

                issues[i].due_date,

                issues[i].return_date,

                issues[i].fine,

                issues[i].returned);
    }


    fclose(issue_fp);


    printf("Book data saved successfully!\n");
    printf("Issue data saved successfully!\n");

    printf("========================================\n");
}
