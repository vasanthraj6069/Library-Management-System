#include <stdio.h>
#include <stdlib.h>

void saveBook();

void exitProgram()
{
    char choice;

    printf("\n");
    printf("========================================\n");
    printf("                 EXIT\n");
    printf("========================================\n");

    printf("A. Save and Exit\n");
    printf("B. Exit Without Save\n");
    printf("C. Cancel\n");

    printf("\nEnter your choice: ");
    scanf(" %c", &choice);

    switch(choice)
    {
        case 'A':
        case 'a':

            saveBook();

            printf("\nData saved successfully!\n");
            printf("Program exiting...\n");

            exit(0);
            break;


        case 'B':
        case 'b':

            printf("\nExiting without saving...\n");

            exit(0);
            break;


        case 'C':
        case 'c':

            printf("\nBack to Main Menu...\n");

            return;


        default:

            printf("\nInvalid choice!\n");
            return;
    }
}
