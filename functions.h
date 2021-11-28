#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "database.h"
#include "string.h"
#include "debugmalloc.h"
#include "time.h"
#include "econio.h"
#include "menu.h"

void autok_kiir(autok* autokstart);
void szervizek_kiir(szervizek* szervizekstart);

autok* gepjarmu_hozzaadasa(autok** autokstart);
szervizek* szerviz_hozzaadasa(szervizek* szervizekstart, autok* autokstart);

autok* gepjarmu_torlese(autok** autokstart); //Ha az elsõ a törlendõ elem, akkor bugos

void nevek_keres(autok* autokstart);
void gepjarmu_keres(autok* autokstart);
void szerviz_keres(szervizek* szervizekstart);

void lejaromuszaki(autok* autokstart);

#endif // FUNCTIONS_H_INCLUDED
