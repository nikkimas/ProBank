#include <stdio.h>
#include <stdlib.h>
#include "global_vars.h"
#include <mysql.h>
#include <my_global.h>

#define DEBUG 1

int main(void)
{
    char inp;
    card = emulateCard();
    printWelcome();
    printMenu();
    inp = scanfTTY();
    printGoodbye();
    return EXIT_SUCCESS;
}
