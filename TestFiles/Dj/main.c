#include <stdio.h>

int main(void){

    char pin[5], ch;
    int i, asc, intPin;

    Clear();

    printf("Enter the PIN <4 characters>: ");

    for(i=0; i<4; i++){
        ch = getch();
        fflush(stdin);
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

    sscanf(pin, "%d", &intPin);

    #ifdef DEBUG
        printf("\nYour password is: ");
        printf("%s",pin);
    #endif

}

void Clear(void){

    #ifdef linux
        system("clear");
    #endif

    #ifdef _WIN32
        system("cls");
    #endif

}
