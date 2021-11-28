#include "database.h"


#define MAX_SOR 450
static char sor[450];

FILE *autok_filemegnyitasa() {
    FILE *autokptr;
    autokptr = fopen("autok.txt", "r");
    if (autokptr == NULL) {
        perror("Az autók fájl megnyitása nem sikerült!\n");
        printf("Nyomja meg az ENTERt a kilépéshez!\n");
        char exit_error;
        if (econio_getch(exit_error) == KEY_ENTER)
            exit(1);
    } else
        return autokptr;
}

FILE *autok_filemegnyitasa_iras() {
    FILE *autokptr;
    autokptr = fopen("autok.txt", "w");
    if (autokptr == NULL) {
        perror("Az autók fájl megnyitása mentéskor nem sikerült!\n");
        printf("Nyomja meg az ENTERt a kilépéshez!\n");
        char exit_error;
        if (econio_getch(exit_error) == KEY_ENTER)
            exit(1);
    } else
        return autokptr;
}

int autok_sorszamol(FILE *autokptr) {
    int sorokszama = 0;
    while (fgets(sor, MAX_SOR, autokptr) != NULL) {
        sorokszama++;
    }
    fseek(autokptr, 0, SEEK_SET); //vissza kell leptetni a FILEra mutato pointert az elejere
    return sorokszama;
}

autok *autok_feltolt(autok *autokstart, FILE *autokptr) {
    char sorelem[45];
    int elemidx = 0, sorokszama = autok_sorszamol(autokptr);
    int sorszam = 0;

    while (fgets(sor, sizeof(sor), autokptr)) {    //egy sor beolvasasa a filebol
        autok *autoklistaja = (autok *) malloc(sizeof(autok));

        int structidx = 0; //ez donti el, milyen tipusu(pl.: Nev, Marka, stb) lesz a beolvasott adat
        const char s[2] = ".";
        char *resz; //datum tagolashoz kell
        sorszam++; //megnezzuk, hogy hanyadik sornal vagyunk --> ha a vegenel akkor breakeljuk a while ciklust

        for (int i = 0; i < MAX_SOR; ++i) {
            if (sor[i] == '\n' && sorszam != sorokszama) {
                break;
            }

            if (sor[i] == ';') {
                sorelem[elemidx++] = '\0'; //megkapom az elemet, amit be akarok fuzni
                switch (structidx) { //eldönti, hogy éppen milyen adatot olvasott be
                    case 0:

                        autoklistaja->nev = (char *) malloc((strlen(sorelem) + 1) * sizeof(char)); //strdup(sorelem);
                        strcpy(autoklistaja->nev, sorelem);
                        break;
                    case 1:
                        autoklistaja->telefonszam = (char *) malloc((strlen(sorelem) + 1) * sizeof(char));
                        strcpy(autoklistaja->telefonszam, sorelem);
                        break;
                    case 2:
                        autoklistaja->marka = (char *) malloc((strlen(sorelem) + 1) * sizeof(char));
                        strcpy(autoklistaja->marka, sorelem);
                        break;
                    case 3:
                        autoklistaja->tipus = (char *) malloc((strlen(sorelem) + 1) * sizeof(char));
                        strcpy(autoklistaja->tipus, sorelem);
                        break;
                    case 4:
                        autoklistaja->evjarat = atoi(sorelem); //structban intkent?!
                        break;
                    case 5:
                        autoklistaja->uzemanyag = (char *) malloc((strlen(sorelem) + 1) * sizeof(char));
                        strcpy(autoklistaja->uzemanyag, sorelem);
                        break;
                    case 6:
                        autoklistaja->hengerurtartalom = atof(sorelem);
                        break; //structban double?! //atof --> átkonvertálja a stringet doublel?
                    case 7:
                        autoklistaja->rendszam = (char *) malloc((strlen(sorelem) + 1) * sizeof(char));
                        strcpy(autoklistaja->rendszam, sorelem);
                        break;
                    case 8:
                        resz = strtok(sorelem, s);
                        autoklistaja->muszaki.ev = atoi(resz);
                        resz = strtok(NULL, s);
                        autoklistaja->muszaki.honap = atoi(resz);
                        resz = strtok(NULL, s);
                        autoklistaja->muszaki.nap = atoi(resz);
                        autoklistaja->autok_kov = autokstart;
                        autokstart = autoklistaja;
                        structidx = 0;
                        break;
                }
                elemidx = 0;
                structidx++;
                sorszam++;
            } else
                sorelem[elemidx++] = sor[i];
        }
    }
    return autokstart;
}

void autokadatok_mentese(FILE *autokptr, autok *autokstart) {
    while (autokstart != NULL) {
        fprintf(autokptr, "%s;%s;%s;%s;%d;%s;%g;%s;%d.%02d.%02d.;\n", autokstart->nev, autokstart->telefonszam,
                autokstart->marka, autokstart->tipus, autokstart->evjarat\
        , autokstart->uzemanyag, autokstart->hengerurtartalom, autokstart->rendszam, autokstart->muszaki.ev, \
        autokstart->muszaki.honap, autokstart->muszaki.nap);
        autokstart = autokstart->autok_kov;
    }
}

void autok_felszabadit(autok *lancoltlista) {
    while (lancoltlista != NULL) {
        autok *temp = lancoltlista;
        lancoltlista = lancoltlista->autok_kov;
        free(temp->tipus);
        free(temp->nev);
        free(temp->rendszam);
        free(temp->telefonszam);
        free(temp->marka);
        free(temp->uzemanyag);
        free(temp);
    }
}


FILE *szervizek_filemegnyitasa() {
    FILE *szervizekptr = fopen("szervizek.txt", "r");
    if (szervizekptr == NULL) {
        perror("A szervizek fájl megnyitása nem sikerült!\n");
        printf("Nyomja meg az ENTERt a kilépéshez!\n");
        char exit_error;
        if (econio_getch(exit_error) == KEY_ENTER)
            exit(1);
    } else
        return szervizekptr;
}

FILE *szervizek_filemegnyitasa_iras() {
    FILE *szervizekptr = fopen("szervizek.txt", "w");
    if (szervizekptr == NULL) {
        perror("A szervizek fájl megnyitása mentéskor nem sikerült.\n");
        printf("Nyomja meg az ENTERt a kilépéshez!\n");
        char exit_error;
        if (econio_getch(exit_error) == KEY_ENTER)
            exit(1);
    } else
        return szervizekptr;
}

int szervizek_sorszamol(FILE *szervizekptr) {
    int sorokszama = 0;
    while (fgets(sor, MAX_SOR, szervizekptr) != NULL) {
        sorokszama++;
    }
    fseek(szervizekptr, 0, SEEK_SET);
    return sorokszama;
}

szervizek *szervizek_feltolt(szervizek *szervizekstart, FILE *szervizekptr) {
    char sorelem[45];
    int elemidx = 0, sorszam = 0, sorokszama = szervizek_sorszamol(szervizekptr);


    while (fgets(sor, MAX_SOR, szervizekptr) != NULL) {
        int structidx = 0;
        const char s[2] = ".";
        char *resz;//dátum "szeleteléshez" kell
        szervizek *szervizeklistaja = (szervizek *) malloc(sizeof(szervizek));

        for (int i = 0; i < MAX_SOR; i++) {
            if (sor[i] == '\n') {
                break;
            }
            if (sor[i] == ';') {
                sorelem[elemidx++] = '\0';
                switch (structidx) {
                    case 0:
                        sorszam++;
                        if (sorszam < sorokszama + 1) {
                            szervizeklistaja->autoneve = (char *) malloc(
                                    (strlen(sorelem) + 1) * sizeof(char)); //strlen(sorelem)+1 = elemidx+2
                            strcpy(szervizeklistaja->autoneve, sorelem);
                        }

                        break;
                    case 1:

                        szervizeklistaja->rendszam = (char *) malloc(
                                (strlen(sorelem) + 1) * sizeof(char)); //strlen(sorelem)+1 = elemidx+2
                        strcpy(szervizeklistaja->rendszam, sorelem);
                        break;
                    case 2:

                        szervizeklistaja->tetel = (char *) malloc(
                                (strlen(sorelem) + 1) * sizeof(char)); //strlen(sorelem)+1 = elemidx+2
                        strcpy(szervizeklistaja->tetel, sorelem);
                        break;
                    case 3:
                        szervizeklistaja->koltseg = atoi(sorelem);
                        break;
                    case 4:
                        resz = strtok(sorelem, s);
                        szervizeklistaja->datum.ev = atoi(resz);
                        resz = strtok(NULL, s);
                        szervizeklistaja->datum.honap = atoi(resz);
                        resz = strtok(NULL, s);//lehet kell a pont
                        szervizeklistaja->datum.nap = atoi(resz);

                        szervizeklistaja->szervizek_kov = szervizekstart;
                        szervizekstart = szervizeklistaja;
                        break;
                }
                elemidx = 0;
                structidx++;
                if (structidx > 4)
                    structidx = 0;
            } else
                sorelem[elemidx++] = sor[i];
        }
    }
    return szervizekstart;
}

void szervizekadatok_mentese(FILE *szervizekptr, szervizek *szervizekstart) {
    while (szervizekstart != NULL) {
        fprintf(szervizekptr, "%s;%s;%s;%d;%d.%02d.%02d;\n", szervizekstart->autoneve, szervizekstart->rendszam, \
            szervizekstart->tetel, szervizekstart->koltseg, szervizekstart->datum.ev, szervizekstart->datum.honap, \
            szervizekstart->datum.nap);

        szervizekstart = szervizekstart->szervizek_kov;
    }
}

void szervizek_felszabadit(szervizek *szervizekstart) {

    while (szervizekstart != NULL) {
        szervizek *temp = szervizekstart;
        szervizekstart = szervizekstart->szervizek_kov;
        free(temp->autoneve);
        free(temp->rendszam);
        free(temp->tetel);
        free(temp);

    }
}

