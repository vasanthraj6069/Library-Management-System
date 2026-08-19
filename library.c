#include <stdio.h>
#include <string.h>

/* =========================
   BOOK STRUCTURE
   ========================= */

struct Book
{
    int book_id;
    char title[100];
    char author[100];
    int quantity;
};


/* =========================
   ISSUE STRUCTURE
   ========================= */

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


/* =========================
   SHARED DATA
   ========================= */

struct Book books[100];

struct Issue issues[100];

int book_count = 0;

int issue_count = 0;


/* =========================
   FUNCTION DECLARATIONS
   ========================= */

void addBook();
void removeBook();
void updateBook();
void searchBook();
void issueBook();
void returnBook();
void listBooks();
void showBook();
void saveBook();
void exitProgram();
void loadData();

/* =========================
   MAIN FUNCTION
   ========================= */

int main()
{
    int choice;
    loadData();

    while(1)
    {
        printf("\n");

        printf("\t+----------------------------------------+\n");
        printf("\t|       LIBRARY MANAGEMENT SYSTEM        |\n");
        printf("\t+----------------------------------------+\n");

        printf("\t|  1. Add New Book                       |\n");
        printf("\t+----------------------------------------+\n");

        printf("\t|  2. Remove Book                        |\n");
        printf("\t+----------------------------------------+\n");

        printf("\t|  3. Update Book Details                |\n");
        printf("\t+----------------------------------------+\n");

        printf("\t|  4. Search Book                        |\n");
        printf("\t+----------------------------------------+\n");

        printf("\t|  5. Issue Book                         |\n");
        printf("\t+----------------------------------------+\n");

        printf("\t|  6. Return Book                        |\n");
        printf("\t+----------------------------------------+\n");

        printf("\t|  7. List issued Books                  |\n");
        printf("\t+----------------------------------------+\n");

        printf("\t|  8. Show All Book                      |\n");
        printf("\t+----------------------------------------+\n");

        printf("\t|  9. Save Book                          |\n");
        printf("\t+----------------------------------------+\n");

        printf("\t| 10. Exit                               |\n");
        printf("\t+----------------------------------------+\n");

        printf("\n\tEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addBook();
                break;

            case 2:
                removeBook();
                break;

            case 3:
                updateBook();
                break;

            case 4:
                searchBook();
                break;

            case 5:
                issueBook();
                break;

            case 6:
                returnBook();
                break;

            case 7:
                listBooks();
                break;

            case 8:
                showBook();
                break;

            case 9:
                saveBook();
                break;

            case 10:
                exitProgram();
                break;

            default:
                printf("\n\tInvalid choice!\n");
        }
    }

    return 0;
}
