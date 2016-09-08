#include "global_vars.h"

void prepare()
{
    createVorrat();
}

void loop()
{
    char *inp;
    card = emulateCard();
    printWelcome();
    printMenu();
    inp = scanfTTY();
    menu(inp);
    printGoodbye();
}

int main(void)
{
    #ifdef DEBUG
        printf("DEBUGING MODE PLEASE BE CAREFUL!!\n");
    #endif // DEBUG
    prepare();
    loop();
    return EXIT_SUCCESS;
}
