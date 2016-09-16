#include "global_vars.h"
void prepare()
{
    createVorrat();
    #ifdef SERVER_VER
        printf("Initial LOG [\t Try to create Server\t]");
        beServer();
    #else
        printf("Inital LOG [\t Try to create Client\t]\n");
        beClient();
        printSharpRow(70);
        printNL();
    #endif
}

void setUpTmpUser(char * ecc)
{
    char t_knr = ecc[0];
    char t_knt = ecc[1];
    tmpcard->kartennummer = t_knr;
//    tmpcard->konto = t_knt;
    tmpcard->pin = 4444;
}

void loop()
{
    char *inp;
    card = emulateCard();
    setUpTmpUser(card);
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
    #endif
    prepare();
    loop();
    return EXIT_SUCCESS;
}
