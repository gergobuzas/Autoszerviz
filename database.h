#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "econio.h"
#include "debugmalloc.h"

 // DATABASE_H_INCLUDED


typedef struct date{
    int ev;
    int honap;
    int nap;
}date;

typedef struct autok{
    char* nev, *marka, *tipus, *uzemanyag, *rendszam, *telefonszam;
    int evjarat;
    double hengerurtartalom;
    date muszaki;
    struct autok* autok_kov;
}autok;

typedef struct szervizek{
    char *tetel, *rendszam, *autoneve;
    date datum;
    int koltseg;
    struct szervizek* szervizek_kov;
}szervizek;


//beolvassa az autok.txt-t
FILE* autok_filemegnyitasa();

//autok.txt megnyitasa irasra
FILE* autok_filemegnyitasa_iras();

//megszamolja, hogy hany db auto van a fajlban
int autok_sorszamol(FILE* autokptr);

//feltolt egy dinamikusan foglalt lancolt listat a meglevo auto adatokkal
autok* autok_feltolt(autok* autoklistaja, FILE* autokptr);

//beleirja a programon belul eltarolt adatokat
void autokadatok_mentese(FILE* autokptr, autok* autokstart);

//felszabaditja az autokat dinamikusan betoltott lancolt listajat
void autok_felszabadit(autok* lancoltlista);


//szervizek.txt fájlkezelései; ugyanúgy mûködnek, mint az autósok
FILE* szervizek_filemegnyitasa();

FILE* szervizek_filemegnyitasa_iras();

int szervizek_sorszamol(FILE* szervizekptr);

szervizek* szervizek_feltolt(szervizek* szervizekstart, FILE* szervizekptr);

void szervizekadatok_mentese(FILE* szervizekptr, szervizek* szervizeklista);

void szervizek_felszabadit(szervizek* szervizekstart);


#endif
