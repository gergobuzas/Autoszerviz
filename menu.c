//
// Created by Gerg� on 2021. 11. 05..
//
#include "menu.h"


void openingscreen() {
    econio_clrscr();
    econio_textcolor(COL_GREEN);
    printf("�dv�zl�nk az Aut�szerv�z Kft. adatb�zis�ban!\n");
    econio_textcolor(COL_RESET);
    printf("A folytat�shoz nyomja meg az ENTER billenty�t...\n");

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
    printf("1. G�pj�rm� adatok kezel�se\n");
    printf("         Hozz�ad�s \n");
    printf("         T�rl�s\n");
    printf("\n");
    econio_textcolor(COL_LIGHTRED);
    printf("2. Keres�s\n");
    printf("         G�pj�rm�\n");
    printf("         Tulajdonos\n");
    printf("\n");
    econio_textcolor(COL_LIGHTGREEN);
    printf("3. T�tel feljegyz�se\n");
    printf("\n");
    econio_textcolor(COL_WHITE);
    printf("4. Szerv�zt�rt�net lek�rdez�se\n");
    printf("\n");
    econio_textcolor(COL_YELLOW);
    printf("5. Hamarosan lej�r� m�szaki vizsg�k list�z�sa\n");
    econio_textcolor(COL_RESET);
    printf("\n\n\n\n");
    printf("P  Adatok list�z�sa\n");
    printf("\n\n\n\n");
    printf("Q  Kil�p�s a programb�l\n");

    MainMenu2:
    switch (econio_getch()) {
        case '1':
            econio_clrscr();
            printf("Hogyan szeretn� v�ltoztatni az adatb�zist?\n\n");
            printf("    a)  G�pj�rm� hozz�ad�sa\n");
            printf("    b)  G�pj�rm� t�rl�se\n");
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
            printf("    a)  G�pj�rm�re\n");
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
            printf("Biztos ki szeretne l�pni a programb�l?\n");
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
            printf("Adatok list�z�sa\n");
            printf("    a)  G�pj�rm�\n");
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
            printf("G�pj�rm� hozz�ad�sa\n");
            econio_normalmode();
            *autokstart = gepjarmu_hozzaadasa(autokstart);
            printf("\n\n");
            printf("M�velet sikeresen v�grehajtva!\n");
            econio_rawmode();
            printf("\n\nA Folytat�shoz nyomja meg az ENTERt!\n");
            while (econio_getch(key) != KEY_ENTER);
            break;
        case 1:
            econio_clrscr();
            printf("G�pj�rm� t�rl�se\n");
            econio_normalmode();
            *autokstart = gepjarmu_torlese(autokstart);
            printf("\n\n");
            printf("M�velet sikeresen v�grehajtva!\n");
            econio_rawmode();
            printf("\n\nA Folytat�shoz nyomja meg az ENTERt!\n");
            while (econio_getch(key) != KEY_ENTER);
            break;
        case 2:
            econio_clrscr();
            printf("G�pj�rm� keres�se\n");
            econio_normalmode();
            gepjarmu_keres(*autokstart);
            econio_rawmode();
            printf("\n\nA Folytat�shoz nyomja meg az ENTERt!\n");
            while (econio_getch(key) != KEY_ENTER);
            break;
        case 3:
            econio_clrscr();
            printf("Tulajdonosra keres�s\n");
            econio_normalmode();
            nevek_keres(*autokstart);
            econio_rawmode();
            printf("\n\nA Folytat�shoz nyomja meg az ENTER-t!\n");
            while (econio_getch(key) != KEY_ENTER);
            break;
        case 4:
            econio_clrscr();
            printf("T�tel feljegyz�se\n");
            econio_normalmode();
            szervizekstart = szerviz_hozzaadasa(szervizekstart, *autokstart);
            printf("\n\n");
            printf("M�velet sikeresen v�grehajtva!\n");
            econio_rawmode();
            printf("\n\nA Folytat�shoz nyomja meg az ENTER-t!\n");
            while (econio_getch(key) != KEY_ENTER);
            break;
        case 5:
            econio_clrscr();
            printf("Szerv�zt�rt�net lek�rdez�se\n");
            econio_normalmode();
            szerviz_keres(szervizekstart);
            econio_rawmode();
            printf("\n\nA Folytat�shoz nyomja meg az ENTER-t!\n");
            while (econio_getch(key) != KEY_ENTER);
            break;
        case 6:
            econio_clrscr();
            printf("Hamarosan lej�r� m�szaki viszg�val rendelkez� g�pj�rm�vek list�z�sa\n");
            econio_normalmode();
            lejaromuszaki(*autokstart);
            econio_rawmode();
            printf("\n\nA Folytat�shoz nyomja meg az ENTERt!\n");
            while (econio_getch(key) != KEY_ENTER);
            break;
        case 9:
            printf("Aut�k list�z�sa\n\n");
            autok_kiir(*autokstart);
            printf("\n\nA Folytat�shoz nyomja meg az ENTERt!\n");
            while (econio_getch(key) != KEY_ENTER);
            break;
        case 10:
            printf("Szervizek list�z�sa\n\n");
            szervizek_kiir(szervizekstart);
            printf("\n\nA Folytat�shoz nyomja meg az ENTERt!\n");
            while (econio_getch(key) != KEY_ENTER);
            break;
    }
}

