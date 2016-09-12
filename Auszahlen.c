#include "global_vars.h"

int auszahlen()
{
    int kontostand=2000 ;
    int input=0;
    int rechner=0;
    int scheine[7];
    int CorrEingabe=0;

    for(rechner=0; rechner<7; rechner++)
        scheine[rechner]=0;

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~~~~~~~~~~GELD AUSZAHLEN~~~~~~~~~~\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    while(CorrEingabe!=1)
    {
        printf("Wie viel Geld wollen sie abheben?\n");
        scanf("%dje", &input);

        rechner=input % 5;
        if(rechner>0 || input>5000)
            printf("Fehler! Versuchen sie es erneut.\n");
        else
        {
            if(input>kontostand)
                printf("Sie haben nicht genug Guthaben! Geben sie einen geringeren Betrag ein.\n");
            else
            CorrEingabe=1;
        }
    }
    system("cls");

    kontostand-=input;

    rechner=input / 500;
    scheine[6]+=rechner;
    input=input-(scheine[6]*500);

    rechner=input / 200;
    scheine[5]+=rechner;
    input=input-(scheine[5]*200);

    rechner=input / 100;
    scheine[4]+=rechner;
    input=input-(scheine[4]*100);

    rechner=input / 50;
    scheine[3]+=rechner;
    input=input-(scheine[3]*50);

    rechner=input / 20;
    scheine[2]+=rechner;
    input=input-(scheine[2]*20);

    rechner=input / 10;
    scheine[1]+=rechner;
    input=input-(scheine[1]*10);

    rechner=input / 5;
    scheine[0]+=rechner;
    input=input-(scheine[0]*5);

    printf("Sie erhalten:\n%d 500 Euro Schein(e)\n%d 200 Euro Schein(e)\n%d 100 Euro Schein(e)\n%d 50  Euro Schein(e)\n%d 20  Euro Schein(e)\n%d 10  Euro Schein(e) \n%d 5   Euro Schein(e).\n\n", scheine[6], scheine[5], scheine[4], scheine[3], scheine[2], scheine[1], scheine[0]);
    printf("Sie werden nun wieder zur Auswahl weitergeleitet!\n");
    Sleep(2500);
    //Zurück zu der Auswahl - auswahl(NULL);
    return 0;

}
