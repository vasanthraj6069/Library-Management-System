#include <stdio.h>
#include <string.h>
#include <time.h>

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

/* Data is defined in library.c */

extern struct Book books[100];
extern struct Issue issues[100];

extern int book_count;
extern int issue_count;


void returnBook()
{
    int book_id;
    int user_id;
    int i;
    int found = 0;

    printf("\n");
    printf("========================================\n");
    printf("             RETURN BOOK\n");
    printf("========================================\n");

    printf("Enter Book ID: ");
    scanf("%d", &book_id);

    printf("Enter User ID: ");
    scanf("%d", &user_id);


    /* Search issue record */

    for(i = 0; i < issue_count; i++)
    {
        if(issues[i].book_id == book_id &&
           issues[i].user_id == user_id &&
           issues[i].returned == 0)
        {
            found = 1;
            break;
        }
    }


    if(found == 0)
    {
        printf("\nIssue record not found!\n");
        return;
    }


    /* =========================
       GET RETURN DATE
       ========================= */

    time_t t = time(NULL);

    struct tm return_time = *localtime(&t);

    strftime(issues[i].return_date,
             sizeof(issues[i].return_date),
             "%d-%m-%Y",
             &return_time);


    /* =========================
       CONVERT DUE DATE
       ========================= */

    struct tm due_time = {0};

    sscanf(issues[i].due_date,
           "%d-%d-%d",
           &due_time.tm_mday,
           &due_time.tm_mon,
           &due_time.tm_year);

    due_time.tm_mon--;
    due_time.tm_year -= 1900;

    due_time.tm_hour = 0;
    due_time.tm_min = 0;
    due_time.tm_sec = 0;


    /* Set return time to midnight */

    return_time.tm_hour = 0;
    return_time.tm_min = 0;
    return_time.tm_sec = 0;


    /* =========================
       CALCULATE LATE DAYS
       ========================= */

    time_t due = mktime(&due_time);

    time_t returned = mktime(&return_time);

    int late_days;

    late_days = (int)difftime(returned, due)
                / (24 * 60 * 60);


    /* =========================
       CALCULATE FINE
       ========================= */

    if(late_days > 0)
    {
        issues[i].fine = late_days * 5;
    }
    else
    {
        issues[i].fine = 0;
        late_days = 0;
    }


    /* Mark as returned */

    issues[i].returned = 1;


    /* =========================
       INCREASE BOOK QUANTITY
       ========================= */

    for(int j = 0; j < book_count; j++)
    {
        if(books[j].book_id == book_id)
        {
            books[j].quantity++;
            break;
        }
    }


    /* =========================
       DISPLAY DETAILS
       ========================= */

    printf("\n");
    printf("========================================\n");
    printf("       BOOK RETURNED SUCCESSFULLY\n");
    printf("========================================\n");

    printf("Book ID     : %d\n", book_id);

    printf("User ID     : %d\n",
           issues[i].user_id);

    printf("User Name   : %s\n",
           issues[i].user_name);

    printf("Issue Date  : %s\n",
           issues[i].issue_date);

    printf("Due Date    : %s\n",
           issues[i].due_date);

    printf("Return Date : %s\n",
           issues[i].return_date);

    printf("Late Days   : %d\n",
           late_days);

    printf("Fine        : Rs.%d\n",
           issues[i].fine);

    printf("========================================\n");
}
