#include "global_vars.h"

void prepare()
{
    createVorrat();
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
