#ifndef GLOBAL_VARS_H_INCLUDED
#define GLOBAL_VARS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define FUENF 5
#define ZEHN 10
#define ZWANZIG 20
#define FUENFZIG 50
#define HUNDERT 100
#define ZWEIHUNDERT 200
#define FUENFHUNDERT 500

#define MAX 10

#define DEBUG 1
#ifndef _WIN32
#define _WIN32 1
#endif // _WIN32
#define null 0

// Geldscheine
int v_f[MAX];
int v_z[MAX];
int v_zw[MAX];
int v_ff[MAX];
int v_h[MAX];
int v_zh[MAX];
int v_fh[MAX];

//TODO: Structs Optimieren und die Zugriffsberechtigungen anpassen

// Strukturen
typedef struct {
    char kontonummer[8];
    char blz[8];
    int saldo[100];
}konto;

typedef struct {
    char name[20];
    char prename[20];
    konto b_konto;
}benutzer;

typedef struct {
    char kartennummer[20];
    konto konto;
    char pin[8];
}ec_card;

typedef struct {
    konto sender;
    konto empfaenger;
}uweisung;

// Runtime Vars
int * card;
int geld;
ec_card * tmpcard;


#endif // GLOBAL_VARS_H_INCLUDED
