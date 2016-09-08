#include "global_vars.h"

void printPlusRow()
{
    int i;
    for(i = 0; i < 70; i++)
    {
        printf("+");
    }
}

void screenLoop()
{
    clear();
    printPlusRow();
    printf("\t\t\t\tB I T T E\tG E B E N\tS I E\tI H R E\tK A R T E\tE I N\n");
    printPlusRow();
}

void printMinusRow()
{
    int i;
    for(i = 0; i < 70; i++)
    {
        printf("-");
    }
}

void printSetGeld()
{

}

void printGetGeld()
{
    int geld;
    printPlusRow();
    printf("\n\t\t\tG E L D\tA B H E B E N\n");
    printPlusRow();
    printf("\nBitte geben Sie den Betrag ein den sie abheben wollen\n$ ");
    scanf("%d", &geld);
    fflush(stdin);
    if((geld%5) == 0)
    {
        cashOut(geld);
    }
    else
    {
        printf("Automat kann keine ungraden Betraege ausgeben\n");
    }
    loop();
}

void printWelcome()
{
    printMinusRow();
    printf("\n\t\t\tG E L D A U T O M A T\n");
    printMinusRow();
    printf("\n");
}

void printMenu()
{
    printf("\n\n-1- Geld abheben\n-2- Geld einzahlen\n-3- Kontostand anzeigen\n-4- Ueberweisung\n-5- Abbrechen\n");
    #ifdef DEBUG
        printf("-7- Show Vorrat\n");
    #endif // DEBUG
    printf("$ ");
}

void printGoodbye()
{
    printMinusRow();
    printf("\n\tT H A N K\tY O U\tA N D\tG O O D B Y E\n");
    printMinusRow();
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
    case '2': printSetGeld(); break;
    case '5': exit(EXIT_SUCCESS); break;
    #ifdef DEBUG
    case '7': printVorrat(); break;
    #endif // DEBUG
    default: printf("Input Missmatch Error\n"); break;
    }
}

int convertCharToInt(char * value)
{
    return atoi(value);
}

void printVorrat()
{
    int i;
    for(i = 0; i < sizeof(v_f); i++)
    {
        //printf("%d", FUENF);
        printf("%d\n", v_f[i]);
    }
    printf("\n");
}
