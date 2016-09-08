#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char inp;
    int card;
    card = emulateCard();
    printWelcome();
    printMenu();
    inp = scanfTTY();
    printGoodbye();
    return EXIT_SUCCESS;
}
