#include <stdio.h>

int * emulateCard(void)
{
    static int retV[2];
    int cnr;
    int knr;
    printf("ElectronicCardNumber: ");
    scanf("%d", &cnr);
    printf("Kundennummer: ");
    scanf("%d", &knr);
    retV[0] = cnr;
    retV[1] = knr;
    return retV;
}
