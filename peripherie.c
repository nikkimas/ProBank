#include <stdio.h>

int[] emulateCard(void)
{
    int cnr;
    int knr;
    printf("ECCardNumber: ");
    scanf("%d", &cnr);
    printf("Kundennummer: ");
    scanf("%d", &knr);
    int retV[2];
    retV[0] = cnr;
    retV[1] = knr;
    return retV;
}
