#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printPlusRow()
{
    int i;
    for(i = 0; i < 70; i++)
    {
        printf("+");
    }
}

void printGetGeld()
{
    int i, geld;
    printPlusRow();
    printf("\n\t\t\tG E L D\tA B H E B E N\n");
    printPlusRow();
    printf("\nBitte geben Sie den Betrag ein den sie abheben wollen\n$ ");
    scanf("%d", &geld);
    fflush(stdin);
}

void printWelcome()
{
    int i;
    for(i = 0; i < 70; i++)
    {
        printf("-");
    }
    printf("\n\t\t\tG E L D A U T O M A T\n");
    for(i = 0; i < 70; i++)
    {
        printf("-");
    }
    printf("\n");
}

void printMenu()
{
    printf("\n\n-1- Geldabheben\n-2- Geldeinzahlen\n-3- Kontostand anzeigen\n-4- Ueberweisung\n-5- Abbrechen\n");
    printf("$ ");
}

void printGoodbye()
{
    int i;
    for(i = 0; i < 70; i++)
    {
        printf("-");
    }
    printf("\n\tT H A N K\tY O U\tA N D\tG O O D B Y E\n");
    for(i = 0; i < 70; i++)
    {
        printf("-");
    }
}

char scanfTTY()
{
    char inp;
    scanf("%s", &inp);
    fflush(stdin);
    return inp;
}

void menu(char inp)
{
    switch(inp)
    {
    case '1': printGetGeld(); break;
    case '2': setGeld(); break;
    case '5': exit(EXIT_SUCCESS); break;
    default: printf("Input Missmatch Error\n"); break;
    }
}
