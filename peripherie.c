#include "global_vars.h"

void printCash(int cash)
{
    printf("\n%i\t\t\t\t\t%i\n", cash, cash);
    printf("\t\t\tICH BIN GELD%i\t\t\n", cash);
    printf("%i\t\t\t\t\t%i\n", cash, cash);
}

char * emulateCard(void)
{
    static char retV[2];
    char cnr;
    char knr;
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

void beServer()
{

}

void beClient()
{

}
