#include <stdio.h>


void main(void)
{
    int test;

    test = scanfTTY();
    printf("%i", test);
    system("pause");
}

const char * scanfTTY()
{
    const char * inp;
    scanf("%s", inp);
    fflush(stdin);
    return inp;
}
