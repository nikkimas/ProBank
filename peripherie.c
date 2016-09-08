#include "global_vars.h"

void printCash(int cash)
{
    printf("\n%i\t\t\t\t\t%i\n", cash, cash);
    printf("\t\t\tICH BIN GELD%i\t\t\n", cash);
    printf("%i\t\t\t\t\t%i\n", cash, cash);
}

int * emulateCard(void)
{
    static int retV[2];
    int cnr;
    int knr;
    printf("ElectronicCardNumber: ");
    scanf("%d", &cnr);
    fflush(stdin);
    printf("Kundennummer: ");
    scanf("%d", &knr);
    fflush(stdin);
    retV[0] = cnr;
    retV[1] = knr;
    return retV;
}
