#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#ifndef AUTOSZERVIZ_MENU_H
#define AUTOSZERVIZ_MENU_H
#include <stdio.h>
#include <stdlib.h>
#include "econio.h"
#include "functions.h"
#include "database.h"

//
// Created by Gergõ on 2021. 10. 30..
//


//A "welcome" menu megjelenitese + press enter to continue
void openingscreen();


//Kiirja a main menut. Szamot ad vissza, ami hasznos lesz abbol a szempontbol, hogy hova lepjen tovabb a menu
/*  Amiket returnol a mainmenu, az hova vezet:
     * 0 = Gepjarmu hozzaadas;   1 = Gepjarmu torlese;
     * 2 = Gepjarmure kereses;   3 = Tulajdonosra kereses
     * 4 = Tetel feljegyzese;    5 = Szerviztortenet lekerdezese;
     * 6 = Lejaro muszaki viz;   7 = Vissza;
     * 8 = kilepes a programbol  9 = Auto adatok listazasa
     * 10 = Szervizek adatok listazasa
     */

int mainmenu();



//kiirja azt, amit szeretnenk csinalni + meghivja azt a functiont, amiben veghez tudjuk vinni, a teendonket
//a meghivott functionok tobbsegeben modositja az adatot --> ezert kell a tomboket megadni
//int a == mainmenubol returnolt szám
void almenu(int a, autok** autokstart, szervizek* szervizekstart);



#endif //AUTOSZERVIZ_MENU_H
#endif // MENU_H_INCLUDED
