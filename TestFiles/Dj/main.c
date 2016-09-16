#include <stdio.h>

int main(void)
{

}

void Clear(void){

    #ifdef linux
        system("clear");
    #endif

    #ifdef _WIN32
        system("cls");
    #endif

}

int pinInput(void)
{
    char pin[5], ch;
    int i, asc, intPin;

    Clear();  //Terminal wird gesäubert

    printf("ESC zum Abbrechen\n");
    printf("PIN bitte eingeben <4 characters>: ");

    for(i=0; i<4; i++){ //Eingabe von 4 Ziffern
		ch = getch(); //EIngabe wird in "ch" gespeichert
        fflush(stdin);  //Tastenpuffer leeren
        asc = ch;   //Ascii nummer von "ch" wird in "asc" gespeichert

        if ( asc == 27 )  //Prüfen, ob ESC gedrückt wird
        {
            //KartenAuswurf funktion
            return -1;
        }

        if ( asc <= 47 || asc >= 58 )//Prüfen, ob es ein buchstabe ist
        {
            i--; //laufvar um 1 decimieren
            continue; //an anfang von der "for" schleife springen
        }

        pin[i] = ch; //ch in das array für den PIN schreiben
        ch = '*';   // "*" statt der eingabe in "ch" schreiben
        printf("%c",ch);    //"ch" ausgeben
    }

    pin[i] = '\0';//Nullterminierung dranhängen

    sscanf(pin, "%d", &intPin); //"pin[]" in "intPin" schieben

    #ifdef DEBUG
        printf("\nYour password is: ");
        printf("%s",pin);
    #endif

    return intPin; // Pin an aufrufende funktion zurückgeben
}
}
