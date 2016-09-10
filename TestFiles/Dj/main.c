#include <stdio.h>


void main(void)
{
    int test;

    test = scanfTTY();
    printf("%i", test);
    system("pause");
}

char scanfTTY()
{
    char inp;
    scanf("%s", &inp);
    fflush(stdin);
    return inp;
}
