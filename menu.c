//
// Created by Gergõ on 2021. 11. 05..
//
#include "menu.h"


void openingscreen() {
    econio_clrscr();
    econio_textcolor(COL_GREEN);
    printf("Üdvözlünk az Autószervíz Kft. adatbázisában!\n");
    econio_textcolor(COL_RESET);
    printf("A folytatáshoz nyomja meg az ENTER billentyût...\n");

    MainMenu: //Tovabblepes
    switch (econio_getch()) {
        case KEY_ENTER:
            econio_clrscr();
            break;
        default:
            goto MainMenu;
    }
}

int mainmenu() {
    MainMenu1:
    econio_clrscr();
    econio_textcolor(COL_LIGHTCYAN);
    printf("1. Gépjármû adatok kezelése\n");
    printf("         Hozzáadás \n");
    printf("         Törlés\n");
    printf("\n");
    econio_textcolor(COL_LIGHTRED);
    printf("2. Keresés\n");
    printf("         Gépjármû\n");
    printf("         Tulajdonos\n");
    printf("\n");
    econio_textcolor(COL_LIGHTGREEN);
    printf("3. Tétel feljegyzése\n");
    printf("\n");
    econio_textcolor(COL_WHITE);
    printf("4. Szervíztörténet lekérdezése\n");
    printf("\n");
    econio_textcolor(COL_YELLOW);
    printf("5. Hamarosan lejáró mûszaki vizsgák listázása\n");
    econio_textcolor(COL_RESET);
    printf("\n\n\n\n");
    printf("P  Adatok listázása\n");
    printf("\n\n\n\n");
    printf("Q  Kilépés a programból\n");

    MainMenu2:
    switch (econio_getch()) {
        case '1':
            econio_clrscr();
            printf("Hogyan szeretné változtatni az adatbázist?\n\n");
            printf("    a)  Gépjármû hozzáadása\n");
            printf("    b)  Gépjármû törlése\n");
            printf("    c)  Vissza\n");
        Gepjarmuadatok:
            switch (econio_getch()) {
                case 'a':
                case 'A':
                    return 0;
                case 'b':
                case 'B':
                    return 1;
                case 'c':
                case 'C':
                    return 7;
                default:
                    goto Gepjarmuadatok;
            }
        case '2':
            econio_clrscr();
            printf("Mire szeretne keresni?\n\n");
            printf("    a)  Gépjármûre\n");
            printf("    b)  Tulajdonosra\n");
            printf("    c)  Vissza\n");
        Kereses:
            switch (econio_getch()) {
                case 'a':
                case 'A':
                    return 2;
                case 'b':
                case 'B':
                    return 3;
                case 'c':
                case 'C':
                    return 7;
                default:
                    goto Kereses;
            }
        case '3': //Tetel feljegyzese
            return 4;
        case '4': //Szerviztortenet
            return 5;
        case '5': //Lejaro muszaki vizsga
            return 6;
        case 'q':
        case 'Q':
            econio_clrscr();
            printf("Biztos ki szeretne lépni a programból?\n");
            printf("       (I)Igen              (N)Nem\n");
        AreYouSure:
            switch (econio_getch()) {
                case 'i':
                case 'I':
                    return 8;
                case 'n':
                case 'N':
                    goto MainMenu1;
                default:
                    goto AreYouSure;
            }
        case 'p':
        case 'P':
            econio_clrscr();
            printf("Adatok listázása\n");
            printf("    a)  Gépjármû\n");
            printf("    b)  Szervizek\n");
            printf("    c)  Vissza\n");
        Listazas:
            switch (econio_getch()) {
                case 'a':
                case 'A':
                    return 9;
                case 'b':
                case 'B':
                    return 10;
                case 'c':
                case 'C':
                    return 7;
                default:
                    goto Listazas;
            }
        default:
            goto MainMenu2;
    }

}


void almenu(int opcioertek, autok **autokstart, szervizek *szervizekstart) {
    char key;

    switch (opcioertek) {
        case 0:
            econio_clrscr();
            printf("Gépjármû hozzáadása\n");
            econio_normalmode();
            *autokstart = gepjarmu_hozzaadasa(autokstart);
            printf("\n\n");
            printf("Mûvelet sikeresen végrehajtva!\n");
            econio_rawmode();
            printf("\n\nA Folytatáshoz nyomja meg az ENTERt!\n");
            while (econio_getch(key) != KEY_ENTER);
            break;
        case 1:
            econio_clrscr();
            printf("Gépjármû törlése\n");
            econio_normalmode();
            *autokstart = gepjarmu_torlese(autokstart);
            printf("\n\n");
            printf("Mûvelet sikeresen végrehajtva!\n");
            econio_rawmode();
            printf("\n\nA Folytatáshoz nyomja meg az ENTERt!\n");
            while (econio_getch(key) != KEY_ENTER);
            break;
        case 2:
            econio_clrscr();
            printf("Gépjármû keresése\n");
            econio_normalmode();
            gepjarmu_keres(*autokstart);
            econio_rawmode();
            printf("\n\nA Folytatáshoz nyomja meg az ENTERt!\n");
            while (econio_getch(key) != KEY_ENTER);
            break;
        case 3:
            econio_clrscr();
            printf("Tulajdonosra keresés\n");
            econio_normalmode();
            nevek_keres(*autokstart);
            econio_rawmode();
            printf("\n\nA Folytatáshoz nyomja meg az ENTER-t!\n");
            while (econio_getch(key) != KEY_ENTER);
            break;
        case 4:
            econio_clrscr();
            printf("Tétel feljegyzése\n");
            econio_normalmode();
            szervizekstart = szerviz_hozzaadasa(szervizekstart, *autokstart);
            printf("\n\n");
            printf("Mûvelet sikeresen végrehajtva!\n");
            econio_rawmode();
            printf("\n\nA Folytatáshoz nyomja meg az ENTER-t!\n");
            while (econio_getch(key) != KEY_ENTER);
            break;
        case 5:
            econio_clrscr();
            printf("Szervíztörténet lekérdezése\n");
            econio_normalmode();
            szerviz_keres(szervizekstart);
            econio_rawmode();
            printf("\n\nA Folytatáshoz nyomja meg az ENTER-t!\n");
            while (econio_getch(key) != KEY_ENTER);
            break;
        case 6:
            econio_clrscr();
            printf("Hamarosan lejáró mûszaki viszgával rendelkezõ gépjármûvek listázása\n");
            econio_normalmode();
            lejaromuszaki(*autokstart);
            econio_rawmode();
            printf("\n\nA Folytatáshoz nyomja meg az ENTERt!\n");
            while (econio_getch(key) != KEY_ENTER);
            break;
        case 9:
            printf("Autók listázása\n\n");
            autok_kiir(*autokstart);
            printf("\n\nA Folytatáshoz nyomja meg az ENTERt!\n");
            while (econio_getch(key) != KEY_ENTER);
            break;
        case 10:
            printf("Szervizek listázása\n\n");
            szervizek_kiir(szervizekstart);
            printf("\n\nA Folytatáshoz nyomja meg az ENTERt!\n");
            while (econio_getch(key) != KEY_ENTER);
            break;
    }
}

