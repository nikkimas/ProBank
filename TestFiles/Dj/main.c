#include <stdio.h>

int main(void){

    char pin[5], ch;
    int i;

    Clear();

    printf("Enter the PIN <4 characters>: ");

    for(i=0; i<4; i++){
        ch = getch();
        pin[i] = ch;
        ch = '*';
        printf("%c",ch);
    }

    pin[i] = '\0';

    /*If you want to know what you have entered as password, you can print it*/
    printf("\nYour password is: ");

    for(i=0;i<4;i++){
        printf("%c",pin[i]);
    }

}

void Clear(void){

    #ifdef linux
        system("clear");
    #endif

    #ifdef _WIN32
        system("cls");
    #endif

}
