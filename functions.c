#include "functions.h"


#define MAX_LENGHT 45

void autok_kiir(autok *autokstart) {
    for (; autokstart != NULL; autokstart = autokstart->autok_kov) {
        printf("%s; %s; %s; %s; %d; %s; %g; %s; %d.%02d.%02d;\n", autokstart->nev, autokstart->telefonszam,
               autokstart->marka, autokstart->tipus, autokstart->evjarat\
, autokstart->uzemanyag, autokstart->hengerurtartalom, autokstart->rendszam, autokstart->muszaki.ev, \
        autokstart->muszaki.honap, autokstart->muszaki.nap);
    }
}

void szervizek_kiir(szervizek *szervizekstart) {
    for (; szervizekstart != NULL; szervizekstart = szervizekstart->szervizek_kov) {
        printf("%s; %s; %s; %d; %d.%02d.%02d;\n", szervizekstart->autoneve, szervizekstart->rendszam,
               szervizekstart->tetel, szervizekstart->koltseg, \
                szervizekstart->datum.ev, szervizekstart->datum.honap, szervizekstart->datum.nap);
    }
}

autok *gepjarmu_hozzaadasa(autok **autokstart) {
    char nev[45], marka[45], tipus[45], uzemanyag[45], rendszam[45], telefonszam[45];
    int evjarat;
    double hengerurtartalom;
    date muszaki;
    printf("Kérem, gépelje be a Tulajdonos nevét!\n");
    fgets(nev, MAX_LENGHT, stdin);
    if ((strlen(nev) > 0) && (nev[strlen(nev) - 1] == '\n'))
        nev[strlen(nev) - 1] = '\0';
    printf("Kérem, adja meg a Tulajdonos telefonszámát!\n");
    fgets(telefonszam, MAX_LENGHT, stdin);
    if ((strlen(telefonszam) > 0) && (telefonszam[strlen(telefonszam) - 1] == '\n'))
        telefonszam[strlen(telefonszam) - 1] = '\0';
    printf("Kérem, adja meg a gépjármû márkáját!\n");
    fgets(marka, MAX_LENGHT, stdin);
    if ((strlen(marka) > 0) && (marka[strlen(marka) - 1] == '\n'))
        marka[strlen(marka) - 1] = '\0';
    printf("Kérem, adja meg a gépjármû márkáján belüli típusát!\n");
    fgets(tipus, MAX_LENGHT, stdin);
    if ((strlen(tipus) > 0) && (tipus[strlen(tipus) - 1] == '\n'))
        tipus[strlen(tipus) - 1] = '\0';
    printf("Kérem, adja meg a gépjármû milyen meghajtású!\n");
    fgets(uzemanyag, MAX_LENGHT, stdin);
    if ((strlen(uzemanyag) > 0) && (uzemanyag[strlen(uzemanyag) - 1] == '\n'))
        uzemanyag[strlen(uzemanyag) - 1] = '\0';
    printf("Kérem, adja meg a gépjármû rendszámát!\n");
    fgets(rendszam, MAX_LENGHT, stdin);;
    if ((strlen(rendszam) > 0) && (rendszam[strlen(rendszam) - 1] == '\n'))
        rendszam[strlen(rendszam) - 1] = '\0';
    printf("Kérem, adja meg a gépjármû forgalomba helyezésének évét!\n");
    scanf(" %d", &evjarat); //fgets(evjarat,45, stdin);
    printf("Kérem, adja meg a gépjármû hengerûrtartalmát!\n");
    scanf(" %lf", &hengerurtartalom);
    getchar();
    printf("Kérem, adja meg a gépjármû mûszaki érvényességének végét!\n");
    printf("Év: ");
    scanf(" %d", &muszaki.ev);
    getchar();
    printf("Hónap: ");
    scanf(" %d", &muszaki.honap);
    getchar();
    printf("Nap: ");
    scanf(" %d", &muszaki.nap);
    getchar();

    autok *uj = (autok *) malloc(sizeof(autok));
    uj->uzemanyag = (char *) malloc((strlen(uzemanyag) + 1) * sizeof(char));
    strcpy(uj->uzemanyag, uzemanyag);
    uj->marka = (char *) malloc((strlen(marka) + 1) * sizeof(char));
    strcpy(uj->marka, marka);
    uj->nev = (char *) malloc((strlen(nev) + 1) * sizeof(char));
    strcpy(uj->nev, nev);
    uj->rendszam = (char *) malloc((strlen(rendszam) + 1) * sizeof(char));
    strcpy(uj->rendszam, rendszam);
    uj->tipus = (char *) malloc((strlen(tipus) + 1) * sizeof(char));
    strcpy(uj->tipus, tipus);
    uj->telefonszam = (char *) malloc((strlen(telefonszam) + 1) * sizeof(char));
    strcpy(uj->telefonszam, telefonszam);
    uj->evjarat = evjarat;
    uj->hengerurtartalom = hengerurtartalom;
    uj->muszaki.ev = muszaki.ev;
    uj->muszaki.honap = muszaki.honap;
    uj->muszaki.nap = muszaki.nap;
    uj->autok_kov = *autokstart;

    autok *mozgo = *autokstart;
    while (mozgo->autok_kov != NULL)
        mozgo = mozgo->autok_kov;
    mozgo->autok_kov = uj;
    uj->autok_kov = NULL;

    return *autokstart;
}

szervizek *szerviz_hozzaadasa(szervizek *szervizekstart, autok *autokstart) {
    char tetel[45], rendszam[45], autoneve[45];
    date datum;
    int koltseg;

    printf("Kérem adja meg a tétel nevét: \n");
    fgets(tetel, MAX_LENGHT, stdin);
    if ((strlen(tetel) > 0) && (tetel[strlen(tetel) - 1] == '\n'))
        tetel[strlen(tetel) - 1] = '\0';
    printf("Kérem adja meg a gépjármû rendszámát: \n");
    fgets(rendszam, MAX_LENGHT, stdin);
    if ((strlen(rendszam) > 0) && (rendszam[strlen(rendszam) - 1] == '\n'))
        rendszam[strlen(rendszam) - 1] = '\0';
    printf("Kérem adja meg az autó nevét (Márka + Típus): \n");
    fgets(autoneve, MAX_LENGHT, stdin);
    if ((strlen(autoneve) > 0) && (autoneve[strlen(autoneve) - 1] == '\n'))
        autoneve[strlen(autoneve) - 1] = '\0';
    printf("Kérem adja meg az évet, amikor a szervíz történt: \n");
    scanf("%d", &datum.ev);
    getchar();
    printf("Kérem adja meg a hónapot, amikor a szervíz történt: \n");
    scanf("%d", &datum.honap);
    getchar();
    printf("Kérem adja meg a napot, amikor a szervíz történt: \n");
    scanf("%d", &datum.nap);
    getchar();
    printf("Kérem adja meg mennyibe került a szervíz: \n");
    scanf("%d", &koltseg);
    getchar();

    szervizek *uj = (szervizek *) malloc(sizeof(szervizek));
    uj->autoneve = (char *) malloc((strlen(autoneve) + 1) * sizeof(char));
    strcpy(uj->autoneve, autoneve);
    uj->rendszam = (char *) malloc((strlen(rendszam) + 1) * sizeof(char));
    strcpy(uj->rendszam, rendszam);
    uj->tetel = (char *) malloc((strlen(tetel) + 1) * sizeof(char));
    strcpy(uj->tetel, tetel);
    uj->datum.ev = datum.ev;
    uj->datum.honap = datum.honap;
    uj->datum.nap = datum.nap;
    uj->koltseg = koltseg;
    uj->szervizek_kov = NULL;

    if (strcmp(uj->tetel, "Mûszaki vizsga") == 0) {
        while (autokstart != NULL) {
            if (strcmp(uj->rendszam, autokstart->rendszam) == 0) {
                if (autokstart->evjarat == uj->datum.ev) {
                    autokstart->muszaki.ev = uj->datum.ev + 4;
                    autokstart->muszaki.honap = uj->datum.honap;
                    autokstart->muszaki.nap = uj->datum.nap;
                } else if (autokstart->evjarat + 3 >= uj->datum.ev) {
                    autokstart->muszaki.ev = uj->datum.ev + 3;
                    autokstart->muszaki.honap = uj->datum.honap;
                    autokstart->muszaki.nap = uj->datum.nap;
                } else {
                    autokstart->muszaki.ev = uj->datum.ev + 2;
                    autokstart->muszaki.honap = uj->datum.honap;
                    autokstart->muszaki.nap = uj->datum.nap;
                }
            }
            autokstart = autokstart->autok_kov;
        }
    }

    szervizek *mozgo = szervizekstart;
    while (mozgo->szervizek_kov != NULL)
        mozgo = mozgo->szervizek_kov;
    mozgo->szervizek_kov = uj;
    return szervizekstart;
}

autok *gepjarmu_torlese(autok **autokstart) {
    char rendszam[45];
    printf("Kérem adja meg a gépjármû rendszámát:\n");
    fgets(rendszam, MAX_LENGHT, stdin);
    if ((strlen(rendszam) > 0) && (rendszam[strlen(rendszam) - 1] == '\n'))
        rendszam[strlen(rendszam) - 1] = '\0';

    autok *koveto = NULL;
    autok *torlendo = *autokstart;
    while (torlendo != NULL && strcmp(torlendo->rendszam, rendszam) != 0) { //torlendo raallitasa a keresett rendszamu node-ra, koveto mogotte
        koveto = torlendo;
        torlendo = torlendo->autok_kov;
    }
    if (torlendo == NULL) {
        printf("Nincs ilyen elem a listában.\n");
    } else if (koveto == NULL) { //elso elem a torlendo
        autok *ujeleje = torlendo->autok_kov;
        free(torlendo->rendszam);
        free(torlendo->nev);
        free(torlendo->telefonszam);
        free(torlendo->uzemanyag);
        free(torlendo->marka);
        free(torlendo->tipus);
        free(torlendo);
        *autokstart = ujeleje;
    } else {
        koveto->autok_kov = torlendo->autok_kov;
        free(torlendo->rendszam);
        free(torlendo->telefonszam);
        free(torlendo->uzemanyag);
        free(torlendo->tipus);
        free(torlendo->marka);
        free(torlendo->nev);
        free(torlendo);
    }
    return *autokstart;
}


void nevek_keres(autok *autokstart) {
    char nev[45];
    int talalat = 0;
    printf("Kérem adja meg a keresett nevet: \n");
    fgets(nev, MAX_LENGHT, stdin);
    if ((strlen(nev) > 0) && (nev[strlen(nev) - 1] == '\n')) {
        nev[strlen(nev) - 1] = '\0';
    }
    while (autokstart != NULL) {
        if (strcmp(nev, autokstart->nev)==0) { //strcmp nullat returnol
            talalat++;
            printf("\n%s; %s; %s; %s; %s; %d; %s; %g; %d, %02d, %02d\n", autokstart->nev, autokstart->telefonszam,
                   autokstart->rendszam, \
            autokstart->marka, autokstart->tipus, autokstart->evjarat, autokstart->uzemanyag,
                   autokstart->hengerurtartalom, \
            autokstart->muszaki.ev, autokstart->muszaki.honap, autokstart->muszaki.nap);
        }
        autokstart = autokstart->autok_kov;
    }
    if (talalat == 0)
        printf("Nincs találat!\n");
}

void gepjarmu_keres(autok *autokstart) {
    char rendszam[45];
    int talalat = 0;
    printf("Kérem adja meg a keresett gépjármû rendszámát: \n");
    fgets(rendszam, MAX_LENGHT, stdin);
    if ((strlen(rendszam) > 0) && (rendszam[strlen(rendszam) - 1] == '\n')) {
        rendszam[strlen(rendszam) - 1] = '\0';
    }
    while (autokstart != NULL) {
        if ((strcmp(rendszam, autokstart->rendszam) == 0)) {
            talalat++;
            printf("%s; %s; %s; %s; %s; %d; %s; %g; %d, %02d, %02d\n", autokstart->nev, autokstart->telefonszam,
                   autokstart->rendszam, \
            autokstart->marka, autokstart->tipus, autokstart->evjarat, autokstart->uzemanyag,
                   autokstart->hengerurtartalom, \
            autokstart->muszaki.ev, autokstart->muszaki.honap, autokstart->muszaki.nap);
        }
        autokstart = autokstart->autok_kov;
    }
    if (talalat == 0)
        printf("Nincs találat!\n");
}

void szerviz_keres(szervizek *szervizekstart) {
    char rendszam[45];
    int talalat = 0, osszeg = 0;
    printf("Kérem adja meg a keresett gépjármû rendszámát: \n");
    fgets(rendszam, MAX_LENGHT, stdin);
    if (strlen(rendszam) > 0 && rendszam[strlen(rendszam) - 1] == '\n')
        rendszam[strlen(rendszam) - 1] = '\0';
    printf("\n");
    while (szervizekstart != NULL) {
        if ((strcmp(rendszam, szervizekstart->rendszam) == 0)) {
            talalat++;
            osszeg += szervizekstart->koltseg;
            printf("%s; %s; %s; %d; %02d; %02d; %dHUF;\n", szervizekstart->rendszam, \
            szervizekstart->autoneve, szervizekstart->tetel, szervizekstart->datum.ev, \
            szervizekstart->datum.honap, szervizekstart->datum.nap, szervizekstart->koltseg);
        }
        szervizekstart = szervizekstart->szervizek_kov;
    }
    if (talalat == 0){
        printf("Nincs találat!\n");
        return;
    }
    printf("\n\nTételek száma: %d db\n", talalat);
    printf("A gépjármûre ráfordított összeg: %d HUF", osszeg);
}

void lejaromuszaki(autok *autokstart) {
    int intervallum, talalat = 0;
    time_t starttime = time(NULL);
    printf("Kérem adja meg napokban, milyen intervallumon belül szeretné vizsgálni a mûszaki vizsga lejártát?\n");
    scanf("%d", &intervallum);
    getchar();
    printf("\n");
    while (autokstart != NULL) {
        double kulonbseg;
        struct tm endtime;
        endtime.tm_year = autokstart->muszaki.ev - 1900;
        endtime.tm_mon = autokstart->muszaki.honap - 1;
        endtime.tm_mday = autokstart->muszaki.nap;
        endtime.tm_sec = 0;
        endtime.tm_min = 0;
        endtime.tm_hour = 0;
        endtime.tm_wday = 0;
        endtime.tm_yday = 0;
        endtime.tm_isdst = 0;
        kulonbseg = (difftime(mktime(&endtime), starttime) / 3600 / 24); //difftime mp-ben adja vissza
        if (kulonbseg <= intervallum) {
            printf("%s; %s; %s; %s; %s; %d; %s; %g; %d.%02d.%02d.;\n", autokstart->nev, autokstart->telefonszam,
                   autokstart->rendszam, \
            autokstart->marka, autokstart->tipus, autokstart->evjarat, autokstart->uzemanyag,
                   autokstart->hengerurtartalom, \
            autokstart->muszaki.ev, autokstart->muszaki.honap, autokstart->muszaki.nap);
            talalat++;
        }
        autokstart = autokstart->autok_kov;
    }
    if (talalat == 0)
        printf("\nNincs találat!\n");
}