#include "global_vars.h"

const char * einzahlung(int betrag, int kontostand)
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
