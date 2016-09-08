#include "global_vars.h"

int getGeld()
{

}

int setGeld()
{

}

void createVorrat()
{
    int i;
    for(i = 0; i < sizeof(v_f); i++)
    {
        v_f[i] = FUENF;
    }
    for(i = 0; i < sizeof(v_z); i++)
    {
        v_z[i] = ZEHN;
    }
    for(i = 0; i < sizeof(v_zw); i++)
    {
        v_zw[i] = ZWANZIG;
    }
    for(i = 0; i < sizeof(v_ff); i++)
    {
        v_ff[i] = FUENFZIG;
    }
    for(i = 0; i < sizeof(v_h); i++)
    {
        v_h[i] = HUNDERT;
    }
    for(i = 0; i < sizeof(v_zh); i++)
    {
        v_zh[i] = ZWEIHUNDERT;
    }
    for(i = 0; i < sizeof(v_fh); i++)
    {
        v_fh[i] = FUENFHUNDERT;
    }
}

int * Stueckelung(){

    //Globale Var des Gewünschten betrages
    //Globales Array des Geldlagers

}
