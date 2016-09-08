#include <stdio.h>

int main(void){

    char pin[5], ch;
    int i, asc;

    Clear();

    printf("Enter the PIN <4 characters>: ");

    for(i=0; i<4; i++){
        ch = getch();
        asc = ch;

        if ( asc <= 47 || asc >= 58 )
        {

            i--;
            continue;

        }

        pin[i] = ch;
        ch = '*';
        printf("%c",ch);
    }

    pin[i] = '\0';

    printf("\nYour password is: ");
    printf("%s",pin);

}

void Clear(void){

    #ifdef linux
        system("clear");
    #endif

    #ifdef _WIN32
        system("cls");
    #endif

}
