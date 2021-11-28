#include <stdio.h>
#include "econio.h"
#include "debugmalloc.h"
#include "menu.h"


#ifdef _WIN32

#include <windows.h>

#endif


int main() {
    econio_set_title("Autoszerviz");
#ifdef _WIN32
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
#endif


    FILE *autokptr = autok_filemegnyitasa(); //autokat tartalmazo fajl megnyitasa
    autok *autoklista = NULL;
    autoklista = autok_feltolt(autoklista, autokptr);

    FILE *szervizekptr = szervizek_filemegnyitasa(); //szervizeket tartalmazo fajl megnyitasa
    szervizek *szervizeklista = NULL;
    szervizeklista = szervizek_feltolt(szervizeklista, szervizekptr);
    fclose(autokptr);
    fclose(szervizekptr);

    int mainmenuvalue;
    econio_rawmode();
    openingscreen();

    while(mainmenuvalue != 8) {
        mainmenuvalue = mainmenu(); //visszaadja a fomenu erteket - mainmenu.h
        almenu(mainmenuvalue, &autoklista, szervizeklista);
    }

    econio_normalmode();
    autokptr = autok_filemegnyitasa_iras();
    autokadatok_mentese(autokptr, autoklista);
    fclose(autokptr);
    autok_felszabadit(autoklista);

    szervizekptr = szervizek_filemegnyitasa_iras();
    szervizekadatok_mentese(szervizekptr, szervizeklista);
    fclose(szervizekptr);
    szervizek_felszabadit(szervizeklista);

    return 0;
}
