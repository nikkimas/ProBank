#include <stdio.h>

typedef struct package
{
    int kontoNr;
    char benutzerName;
    int pin;
}package;
package pack1;

typedef struct charReturn
{
    char returnVal;
}charReturn;


void main(void)
{
    pack1.kontoNr = KontoNrInput();
    /*pack1.benutzerName = UserNameInput();*/

    char *returned_str = createStr();
}

int KontoNrInput(void)
{
    int ktNr;

    Clear();
    printf("Bitte geben Sie ihre Konto Nummer ein: ");
    scanf("%i", &ktNr);

    return ktNr;
}

char * UserNameInput(void)
{
    char userName[10];

    Clear();
    char *userNameRet = (char *) malloc(sizeof(char) * 3);
    printf("Bitte geben Sie ihren Benutzernamen ein: ");
    scanf("%s", &userNameRet);



    return userNameRet;

}


char * createStr() {

    char char1= 'm';
    char char2= 'y';

    char *str = (char *) malloc(sizeof(char) * 3);
    str[0] = char1;
    str[1] = char2;
    str[2] = '\0';

    return str;

}
