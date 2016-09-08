#include <stdio.h>
#include <stdlib.h>
#include "global_vars.h"

#define DEBUG 1

void prepare()
{
    createVorrat();
}

int main(void)
{
    #ifdef DEBUG
        printf("DEBUGING MODE PLEASE BE CAREFUL!!\n");
    #endif // DEBUG
    char inp;
    card = emulateCard();
    printWelcome();
    printMenu();
    inp = scanfTTY();
    menu(inp);
    printGoodbye();
    return EXIT_SUCCESS;
}
