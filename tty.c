#include "global_vars.h"

void printPlusRow()
{
    int i;
    for(i = 0; i < 70; i++)
    {
        printf("+");
    }
}

void printNL()
{
    printf("\n");
}

void printMinusRow()
{
    int i;
    for(i = 0; i < 70; i++)
    {
        printf("-");
    }
}

void printSharpRow(int row)
{
    int i;
    for(i = 0; i < row; i++)
    {
        printf("#");
    }
}

void printUeberweisung()
{
    char empf, blz, ktnr, desc;
    int geld;
    printPlusRow();
    printf("\n\t\t\tU E B E R W E I S U N G\n");
    printPlusRow();
    printf("\n\n");
    printf("Empfaenger$ ");
    scanf("%s", &empf);
    fflush(stdin);
    printf("BLZ:");
    scanf("%s", &blz);
    fflush(stdin);
    printf("KontoNummer$ ");
    scanf("%s", &ktnr);
    fflush(stdin);
    printf("Beschreibung$ ");
    scanf("%s", &desc);
    fflush(stdin);
    printf("Betrag$ ");
    scanf("%d", &geld);
    fflush(stdin);
    printf("Warte bitte einen Moment die Daten werden jetzt verifiziert!");
}

void printSetGeld()
{
    int inp;
    printPlusRow();
    printf("\n\t\t\tG E L D\tE I N Z A H L E N\n");
    printPlusRow();
    printf("\n\n$ ");
    scanf("%d", &inp);
    if((inp%5) == 0)
    {
        cashIn(geld);
    }
    else
    {
        printf("Automat kann nur Scheine annehmen");
    }
}

void printGetGeld()
{
    int geld;
    printPlusRow();
    printf("\n\t\t\tG E L D\tA B H E B E N\n");
    printPlusRow();
    printf("\nBitte geben Sie den Betrag ein den sie abheben wollen\n$ ");
    scanf("%d", &geld);
    fflush(stdin);
    if((geld%5) == 0)
    {
        cashOut(geld);
    }
    else
    {
        printf("Automat kann keine ungraden Betraege ausgeben\n");
    }
    loop();
}

void printKontostand()
{
    printPlusRow();
    printf("");
    printPlusRow();
}

void printWelcome()
{
    printMinusRow();
    printf("\n\t\t\tG E L D A U T O M A T\n");
    printMinusRow();
    printf("\n");
}

void printMenu()
{
    printf("\n\n-1- Geld abheben\n-2- Geld einzahlen\n-3- Kontostand anzeigen\n-4- Ueberweisung\n-5- Abbrechen\n");
    #ifdef DEBUG
        printf("-7- Show Vorrat\n");
    #endif // DEBUG
    printf("$ ");
}

void printGoodbye()
{
    printMinusRow();
    printf("\n\tT H A N K\tY O U\tA N D\tG O O D B Y E\n");
    printMinusRow();
}

char scanfTTY()
{
    char inp;
    scanf("%s", &inp);
    fflush(stdin);
    return inp;
}

void menu(char inp)
{
    switch(inp)
    {
    case '1': printGetGeld(); break;
    case '2': printSetGeld(); break;
    case '3': printKontostand(); break;
    case '4': printUeberweisung(); break;
    case '5': loop(); break;
    #ifdef DEBUG
    case '7': printVorrat(); break;
    #endif // DEBUG
    default: printf("Input Missmatch Error\n"); break;
    }
}

int convertCharToInt(char * value)
{
    int ret;
    sscanf(value, "%i", &ret);
    return ret;
}

void printVorrat()
{
    int i;
    for(i = 0; i < sizeof(v_f); i++)
    {
        //printf("%d", FUENF);
        printf("%d\n", v_f[i]);
    }
    printf("\n");
}

void Clear(void)
{
    #ifdef UNIX/LINUX
        system("clear");
    #endif // linux
    #ifdef _WIN32
        system("cls");
    #endif // _WIN32
}

void TTYSetSize(void)
{
    #ifdef UNIX/LINUX
        system("clear");
    #endif // linux
    #ifdef _WIN32
        system("mode 140,50");
    #endif // _WIN32
}

int einzahlung(int betrag, int kontostand)
{
    if(betrag>5000) //Einzahlungen nur bis 5000€ möglich
        return "EXIT FAILURE";
        //printf("Zu hoher Betrag! Geben sie einen geringeren Betrag ein.\n");
    else
    kontostand+=betrag;

    #ifdef DEBUG
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~~~~~~~~~~GELD EINZAHLEN~~~~~~~~~~\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        printf("Wie viel Geld wollen sie einzahlen?\n");
        printf("Betrag wird dem Konto gutgeschrieben...");
        printf("Erfolgreich!\n");
        printf("Sie werden nun wieder zur Auswahl weitergeleitet!\n");
    #endif

    // Zurück zu der Auswahl - auswahl(NULL)
    return 0;
}

int auszahlen(int kontostand, int input, int rechner, int scheine[], int CorrEingabe)
{
    for(rechner=0; rechner<7; rechner++)
        scheine[rechner]=0;

	#ifdef DEBUG
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~~~~~~~~~~GELD AUSZAHLEN~~~~~~~~~~\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    #endif
   while(CorrEingabe!=1)
    {
        #ifdef DEBUG
		printf("Wie viel Geld wollen sie abheben?\n");
		#endif

        rechner=input % 5;
        if(rechner>0 || input>5000)
			#ifdef DEBUG
			printf("Fehler! Versuchen sie es erneut.\n");
			#endif
		else
        {
            if(input>kontostand)
                return "EXIT FAILURE"
            else
            CorrEingabe=1;
        }
    }

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

    #ifdef DEBUG
	printf("Sie erhalten:\n%d 500 Euro Schein(e)\n%d 200 Euro Schein(e)\n%d 100 Euro Schein(e)\n%d 50  Euro Schein(e)\n%d 20  Euro Schein(e)\n%d 10  Euro Schein(e) \n%d 5   Euro Schein(e).\n\n", scheine[6], scheine[5], scheine[4], scheine[3], scheine[2], scheine[1], scheine[0]);
    #endif
	#ifdef DEBUG
	printf("Sie werden nun wieder zur Auswahl weitergeleitet!\n");
	#endif
    //Zurück zu der Auswahl - auswahl(NULL);
    return 0;

}
