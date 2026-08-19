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


void loadData()
{
    FILE *book_fp;
    FILE *issue_fp;

    book_count = 0;
    issue_count = 0;


    /* =========================
       LOAD BOOK DATA
       ========================= */

    book_fp = fopen("books.txt", "r");

    if(book_fp != NULL)
    {
        while(book_count < 100 &&
              fscanf(book_fp, "%d|%99[^|]|%99[^|]|%d\n",
                     &books[book_count].book_id,
                     books[book_count].title,
                     books[book_count].author,
                     &books[book_count].quantity) == 4)
        {
            book_count++;
        }

        fclose(book_fp);
    }


    /* =========================
       LOAD ISSUE DATA
       ========================= */

    issue_fp = fopen("issues.txt", "r");

    if(issue_fp != NULL)
    {
        while(issue_count < 100 &&
              fscanf(issue_fp,
                     "%d|%d|%d|%99[^|]|%10[^|]|%10[^|]|%10[^|]|%d|%d\n",
                     &issues[issue_count].issue_id,
                     &issues[issue_count].book_id,
                     &issues[issue_count].user_id,
                     issues[issue_count].user_name,
                     issues[issue_count].issue_date,
                     issues[issue_count].due_date,
                     issues[issue_count].return_date,
                     &issues[issue_count].fine,
                     &issues[issue_count].returned) == 9)
        {
            issue_count++;
        }

        fclose(issue_fp);
    }


    printf("\nData loaded successfully!\n");
}
