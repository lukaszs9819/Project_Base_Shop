#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *bd;
    FILE *bt;
    FILE *zast;
    char a,d,e,f,g,q,z,tow[50], znak,nazwatow[80],nazwatow1[80],nazwafir[300],imie[20],nazwisko[30],miejsce[80],usunfirme[30],nazwafir1[300],asorty[60];
    int ile=0,k,l,r,ileb,ch,i,v,usunt,id,id1,liczbaszt1,id2,liczbaszt2,liczbaszt,sprzedane,identy,t,identy1;
    float liczba3, n;
    bt= fopen("tow.txt", "r");
    ile= 0;
    ileb= 0;
    v= 0;
    k= 0;
    r= 0;
    l= 0;
    do  //Zliczanie linijek w bazie towarów
    {
        ch = fgetc(bt);
        if(ch == '\n')
            ile++;
    }
    while (ch != EOF);
    if(ch != '\n' && ile != 0)
        ile++;
    fclose(bt);
    ile--;
    bd= fopen("dos.txt","r");
    do //Zliczanie linijek w bazie dostawców
    {
        k = fgetc(bd);
        if(k == '\n')
            ileb++;
    }
    while (k != EOF);
    if(k != '\n' && ileb != 0)
        ileb++;
    ileb--;
    fclose(bd);
    while(1)
    {
        printf("Wybierz funkcje poprzez wpisanie na ekranie odpowiedniej litery, po literze nacisnij enter");
        printf("\nModyfikacja, sprzedaz, dostawa towarow(t)\nModyfikacja bazy dostawcow(m)\n");
        printf("Wyswietlanie posortowanej listy towarow lub dostawcow(w)\nWyswietlanie towarow brakujacych(b)\n");
        printf("Wyjdz z programu(x)\n");
        fflush(stdin); //Czyszczenie danych wejœcia
        scanf("%c",&a);
        if (a == 'x') break;
        switch (a)
        {
            case 't':
                while(1)
                {
                    printf("Wybierz funkcje poprzez wpisanie na ekranie odpowiedniej litery, po literze nacisnij enter");
                    printf("\nDodawanie towaru do listy(d)\nUsuwanie towarow z listy(u)\nEdycja towarow(e)\nSprzedaz(s)\nDostawa(a)\nPowrot do wczesniejszego wyboru(w)\n");
                    fflush(stdin);
                    scanf("%c",&d);
                    if(d=='w') break;
                    switch (d)
                    {
                        case 'd':
                            bt=fopen("tow.txt","a");
                            printf("Podaj numer ewidencyjny\n");
                            scanf("%s",&tow);
                            fputs(tow,bt);
                            fputs(",",bt);
                            printf("Podaj nazwe towau (Jezeli jest wiecej niz jedeno elementowa zamiast spacji uzyj znaku _ ) \n");
                            printf("Nie uzywaj polskich znakow\n");
                            scanf("%s",&tow);
                            fputs(tow ,bt);
                            fputs(",",bt);
                            printf("Podaj liczbe sztuk\n");
                            scanf("%s",&tow);
                            fputs(tow ,bt);
                            fputs("\n",bt);
                            fclose (bt);
                            printf("Dodano polmyslnie\n\n");
                            ile++;
                            break;
                        case 'u':
                            printf("podaj numer ID towaru ktory chcesz usunac z listy ");
                            scanf("%d",&usunt);
                            bt=fopen("tow.txt","r");
                            zast=fopen("zast.txt","a");
                            r=0;
                            for(i=0;i<ile;i++)
                            {
                                fscanf(bt,"%d,%s",&id,nazwatow);
                                char *przecinek = strchr(nazwatow, ',');
                                *przecinek = 0;
                                przecinek++;
                                liczbaszt = atoi(przecinek);
                                if(id!=usunt)
                                {
                                    fprintf(zast,"%d,%s,%d\n",id,nazwatow,liczbaszt);
                                    r++;
                                }
                            }
                            if(r!=ile)
                            {
                                ile--;
                                printf("Pomyslnie usunieto\n\n");
                            }
                            else
                                printf("Nie ma towaru o takim numerze identyfikacyjnym");
                            fclose (bt);
                            fclose (zast);
                            remove("tow.txt");
                            rename("zast.txt","tow.txt");
                            break;
                        case 'e':
                            printf("podaj numer ID towaru ktory chcesz edytowac ");
                            scanf("%d",&usunt);
                            bt=fopen("tow.txt","r");
                            zast=fopen("zast.txt","a");
                            for(i=0;i<ile;i++)
                            {
                                fscanf(bt,"%d,%s",&id,nazwatow);
                                char *przecinek = strchr(nazwatow, ',');
                                *przecinek = 0;
                                przecinek++;
                                liczbaszt = atoi(przecinek);
                                if(id==usunt)
                                {
                                    while(1)
                                    {
                                        printf("Wybierz dane do zmiany poprzez wpisanie na ekranie odpowiedniej litery, po literze nacisnij enter\n");
                                        printf("numer ID(i)\nnazwa(n)\nliczba sztuk(l)\npowrot(w)\n");
                                        scanf("%s",&e);
                                        if(e=='w') break;
                                        switch (e)
                                        {
                                            case 'i':
                                                printf("podaj nowy numer ID");
                                                scanf("%d",&id);
                                                break;
                                            case 'n':
                                                printf("podaj nowa nazwe(Jezeli jest wiecej niz jedeno elementowa zamiast spacji uzyj znaku _ ) \n");
                                                scanf("%s",&nazwatow);
                                                break;
                                            case 'l':
                                                while(1)
                                                {
                                                    printf("Podaj nowa liczbe sztuk \n");
                                                    scanf("%d",&liczbaszt);
                                                    if(liczbaszt>=0)
                                                        break;
                                                    else printf("\nliczba sztuk musi byc wieksza od lub rowna 0\n");
                                                }
                                                break;
                                            default:
                                                printf("Podano bledna litere, sprobuj ponownie\n");
                                                break;
                                        }
                                    }
                                    fprintf(zast,"%d,%s,%d\n",id,nazwatow,liczbaszt);
                                }
                                else
                                {
                                    fprintf(zast,"%d,%s,%d\n",id,nazwatow,liczbaszt);
                                }
                            }
                            fclose (bt);
                            fclose (zast);
                            remove("tow.txt");
                            rename("zast.txt","tow.txt");
                            printf("Pomyslnie zamieniono\n\n");
                            break;
                        case 's':
                            printf("podaj numer ID towaru ktory sprzedajesz\n");
                            scanf("%d",&usunt);
                            bt=fopen("tow.txt","r");
                            zast=fopen("zast.txt","a");
                            for(i=0;i<ile;i++)
                            {
                                fscanf(bt,"%d,%s",&id,nazwatow);
                                char *przecinek = strchr(nazwatow, ',');
                                *przecinek = 0;
                                przecinek++;
                                liczbaszt = atoi(przecinek);
                                if(id==usunt)
                                {
                                    while(1)
                                    {
                                        printf("podaj ile sztuk towaru sprzedajesz\n");
                                        scanf("%d",&sprzedane);
                                        if(sprzedane>liczbaszt)
                                        {
                                            printf("nie ma tyle towaru na magazynie, pozostalo %d sztuk\n\n",liczbaszt);
                                        }
                                        else
                                        {
                                            liczbaszt=liczbaszt-sprzedane;
                                            break;
                                        }
                                    }
                                }
                                fprintf(zast,"%d,%s,%d\n",id,nazwatow,liczbaszt);
                            }
                            fclose (bt);
                            fclose (zast);
                            remove("tow.txt");
                            rename("zast.txt","tow.txt");
                            printf("Pomyslnie sprzedano\n\n");
                            break;
                        case 'a':
                            printf("podaj numer ID towaru do ktorego przyszla dostawa\n");
                            scanf("%d",&usunt);
                            bt=fopen("tow.txt","r");
                            zast=fopen("zast.txt","a");
                            for(i=0;i<ile;i++)
                            {
                                fscanf(bt,"%d,%s",&id,nazwatow);
                                char *przecinek = strchr(nazwatow, ',');
                                *przecinek = 0;
                                przecinek++;
                                liczbaszt = atoi(przecinek);
                                if(id==usunt)
                                {
                                    printf("podaj ile sztuk towaru dostarczono\n");
                                    scanf("%d",&sprzedane);
                                    liczbaszt=liczbaszt+sprzedane;
                                }
                                fprintf(zast,"%d,%s,%d\n",id,nazwatow,liczbaszt);
                            }
                            fclose (bt);
                            fclose (zast);
                            remove("tow.txt");
                            rename("zast.txt","tow.txt");
                            printf("Pomyslnie uzupelniono magazyn\n\n");
                            break;
                        default:
                            printf("Podano bledna litere, sprobuj ponownie\n");
                            break;
                    }
                }
                break;
            case 'm':
                while(1)
                {
                    printf("Wybierz funkcje poprzez wpisanie na ekranie odpowiedniej litery, po literze nacisnij enter");
                    printf("\nDodawanie firm do listy(d)\nUsuwanie firm z listy(u)\nEdycja firm(e)\nPowrot do wczesniejszego wyboru(w)\n");
                    fflush(stdin);
                    scanf("%c",&f);
                    if (f == 'w') break;
                    switch (f)
                    {
                        case 'd':
                            bd=fopen("dos.txt","a");
                            printf("podaj nazwe firmy (jezeli nazwa jest dwu lub wiecej czlonowa zamiast spacji uzyj znaku _ ) ");
                            scanf("%s",&tow);
                            fputs(tow,bd);
                            fputs(",",bd);
                            printf("podaj imie wlasciciela ");
                            scanf("%s",&tow);
                            fputs(tow ,bd);
                            fputs(",",bd);
                            printf("podaj nazwisko wlasciciela ");
                            scanf("%s",&tow);
                            fputs(tow ,bd);
                            fputs(",",bd);
                            printf("podaj adres firmy (zamiast spacji uzyj znaku _ ) ");
                            scanf("%s",&tow);
                            fputs(tow ,bd);
                            fputs(",",bd);
                            printf("podaj asortyment firmy (zamiast spacji uzyj znaku _ ) ");
                            scanf("%s",&tow);
                            fputs(tow ,bd);
                            fputs(",",bd);
                            printf("podaj identyfikator firmy ");
                            scanf("%s",&tow);
                            fputs(tow ,bd);
                            fputs("\n",bd);
                            fclose (bd);
                            printf("Dodano pomyslnie\n\n");
                            ileb++;
                            break;
                        case 'u':
                            printf("podaj nazwe firm ktora chcesz usunac z listy ");
                            scanf("%s",&usunfirme);
                            bd=fopen("dos.txt","r");
                            zast=fopen("zast.txt","a");
                            for(i=0;i<ileb;i++)
                            {
                                fscanf(bd,"%s",nazwafir);
                                char *przecinek = strchr(nazwafir, ',');
                                *przecinek = 0;
                                przecinek++;
                                char *przecine = strchr(przecinek, ',');
                                *przecine = 0;
                                przecine++;
                                char *przecin = strchr(przecine, ',');
                                *przecin = 0;
                                przecin++;
                                char *przeci = strchr(przecin, ',');
                                *przeci = 0;
                                przeci++;
                                char *przec = strchr(przeci, ',');
                                *przec = 0;
                                przec++;
                                identy = atoi(przec);
                                if(strcmp(nazwafir, usunfirme)==0)
                                {
                                    l++;
                                    printf("Usunieto pomyslnie\n\n");
                                }
                                else
                                {
                                    fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                }
                            }
                            if(l>0)
                                ileb--;
                            else
                                printf("nie ma takiej firmy w bazie danych\n");
                            fclose (bd);
                            fclose (zast);
                            remove("dos.txt");
                            rename("zast.txt","dos.txt");
                            break;
                        case 'e':
                            printf("podaj nazwe firmy ktora chcesz edytowac ");
                            scanf("%s",&usunfirme);
                            bd=fopen("dos.txt","r");
                            zast=fopen("zast.txt","a");
                            for(i=0;i<ileb;i++)
                            {
                                fscanf(bd,"%s",nazwafir);
                                char *przecinek = strchr(nazwafir, ',');
                                *przecinek = 0;
                                przecinek++;
                                char *przecine = strchr(przecinek, ',');
                                *przecine = 0;
                                przecine++;
                                char *przecin = strchr(przecine, ',');
                                *przecin = 0;
                                przecin++;
                                char *przeci = strchr(przecin, ',');
                                *przeci = 0;
                                przeci++;
                                char *przec = strchr(przeci, ',');
                                *przec = 0;
                                przec++;
                                identy = atoi(przec);
                                k=0;
                                if(strcmp(nazwafir, usunfirme)==0)
                                {
                                    k=1;
                                    printf("podaj nowa nazwe firmy ");
                                    scanf("%s",&nazwafir);
                                    printf("podaj nowe imie ");
                                    scanf("%s",&imie);
                                    printf("Podaj nowe nazwisko ");
                                    scanf("%s",&nazwisko);
                                    printf("Podaj nowy adres ");
                                    scanf("%s",&miejsce);
                                    printf("Podaj nowa nazwe dostarczanego asortymentu ");
                                    scanf("%s",&asorty);
                                    printf("Podaj nowy identyfikator ");
                                    scanf("%d",&identy);
                                    fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,imie,nazwisko,miejsce,asorty,identy);
                                    printf("Pomyslnie zamieniono\n\n");
                                }


                                else
                                {
                                    fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                }
                            }
                            fclose (bd);
                            fclose (zast);
                            remove("dos.txt");
                            rename("zast.txt","dos.txt");
                            if(k==0)
                            {
                                printf("Nie ma takiej firmy\n\n");
                            }
                            break;
                        default:
                            printf("Podano bledna litere, sprobuj ponownie");
                            break;
                    }
                }
                break;
            case 'w':
                while(1)
                {
                    printf("Lista towarow posortowana po nazwie(t)   Lista dostawcow(d)    Powrot do wczesniejszego menu(w)\n");
                    scanf("%s",&q);
                    if(q=='w')break;
                    switch(q)
                    {
                        case 't':
                            if(ile%2==0)
                            {fflush(stdin);
                                for(t=0;t<ile;t++)
                                {
                                    bt=fopen("tow.txt","r");
                                    zast=fopen("zast.txt","a");
                                    for(i=0;i<ile;i++)
                                    {
                                        fscanf(bt,"%d,%s",&id,nazwatow);
                                        char *przecinek = strchr(nazwatow, ',');
                                        *przecinek = 0;
                                        przecinek++;
                                        liczbaszt = atoi(przecinek);
                                        i++;
                                        fscanf(bt,"%d,%s",&id1,nazwatow1);
                                        char *przecinek1 = strchr(nazwatow1, ',');
                                        *przecinek1 = 0;
                                        przecinek1++;
                                        liczbaszt1 = atoi(przecinek1);
                                        if(strcmp(nazwatow, nazwatow1)<0)
                                        {

                                            fprintf(zast,"%d,%s,%d\n",id,nazwatow,liczbaszt);
                                            fprintf(zast,"%d,%s,%d\n",id1,nazwatow1,liczbaszt1);
                                        }
                                        else
                                        {
                                            fprintf(zast,"%d,%s,%d\n",id1,nazwatow1,liczbaszt1);
                                            fprintf(zast,"%d,%s,%d\n",id,nazwatow,liczbaszt);
                                        }
                                    }
                                    fclose (bt);
                                    fclose (zast);
                                    remove("tow.txt");
                                    rename("zast.txt","tow.txt");
                                    bt=fopen("tow.txt","r");
                                    zast=fopen("zast.txt","a");
                                    fscanf(bt,"%d,%s",&id,nazwatow);
                                    char *przecinek = strchr(nazwatow, ',');
                                    *przecinek = 0;
                                    przecinek++;
                                    liczbaszt = atoi(przecinek);
                                    fprintf(zast,"%d,%s,%d\n",id,nazwatow,liczbaszt);
                                    for(i=2;i<ile;i++)
                                    {
                                        fscanf(bt,"%d,%s",&id,nazwatow);
                                        char *przecine = strchr(nazwatow, ',');
                                        *przecine = 0;
                                        przecine++;
                                        liczbaszt = atoi(przecine);
                                        i++;
                                        fscanf(bt,"%d,%s",&id1,nazwatow1);
                                        char *przecinek1 = strchr(nazwatow1, ',');
                                        *przecinek1 = 0;
                                        przecinek1++;
                                        liczbaszt1 = atoi(przecinek1);
                                        if(strcmp(nazwatow, nazwatow1)<0)
                                        {
                                            fprintf(zast,"%d,%s,%d\n",id,nazwatow,liczbaszt);
                                            fprintf(zast,"%d,%s,%d\n",id1,nazwatow1,liczbaszt1);
                                        }
                                        else
                                        {
                                            fprintf(zast,"%d,%s,%d\n",id1,nazwatow1,liczbaszt1);
                                            fprintf(zast,"%d,%s,%d\n",id,nazwatow,liczbaszt);
                                        }
                                    }
                                    fscanf(bt,"%d,%s",&id,nazwatow);
                                    char *przecine = strchr(nazwatow, ',');
                                    przecine++;
                                    liczbaszt = atoi(przecine);
                                    fprintf(zast,"%d,%s,%d\n",id,nazwatow,liczbaszt);
                                    fclose (bt);
                                    fclose (zast);
                                    remove("tow.txt");
                                    rename("zast.txt","tow.txt");
                                }
                            }
                            else
                            {
                                for(t=0;t<ile;t++)
                                {
                                    bt=fopen("tow.txt","r");
                                    zast=fopen("zast.txt","a");
                                    for(i=1;i<ile;i++)
                                    {
                                        fscanf(bt,"%d,%s",&id,nazwatow);
                                        char *przecinek = strchr(nazwatow, ',');
                                        *przecinek = 0;
                                        przecinek++;
                                        liczbaszt = atoi(przecinek);
                                        i++;
                                        fscanf(bt,"%d,%s",&id1,nazwatow1);
                                        char *przecinek1 = strchr(nazwatow1, ',');
                                        *przecinek1 = 0;
                                        przecinek1++;
                                        liczbaszt1 = atoi(przecinek1);
                                        if(strcmp(nazwatow, nazwatow1)<0)
                                        {
                                            fprintf(zast,"%d,%s,%d\n",id,nazwatow,liczbaszt);
                                            fprintf(zast,"%d,%s,%d\n",id1,nazwatow1,liczbaszt1);
                                        }
                                        else
                                        {
                                            fprintf(zast,"%d,%s,%d\n",id1,nazwatow1,liczbaszt1);
                                            fprintf(zast,"%d,%s,%d\n",id,nazwatow,liczbaszt);
                                        }
                                    }
                                    fscanf(bt,"%d,%s",&id,nazwatow);
                                    char *przecin = strchr(nazwatow, ',');
                                    *przecin = 0;
                                    przecin++;
                                    liczbaszt = atoi(przecin);
                                    fprintf(zast,"%d,%s,%d\n",id,nazwatow,liczbaszt);
                                    fclose (bt);
                                    fclose (zast);
                                    remove("tow.txt");
                                    rename("zast.txt","tow.txt");
                                    bt=fopen("tow.txt","r");
                                    zast=fopen("zast.txt","a");
                                    fscanf(bt,"%d,%s",&id,nazwatow);
                                    char *przecine = strchr(nazwatow, ',');
                                    *przecine = 0;
                                    przecine++;
                                    liczbaszt = atoi(przecine);
                                    fprintf(zast,"%d,%s,%d\n",id,nazwatow,liczbaszt);
                                    for(i=1;i<ile;i++)
                                    {
                                        fscanf(bt,"%d,%s",&id,nazwatow);
                                        char *przecine = strchr(nazwatow, ',');
                                        przecine++;
                                        liczbaszt = atoi(przecine);
                                        i++;
                                        fscanf(bt,"%d,%s",&id1,nazwatow1);
                                        char *przecinek1 = strchr(nazwatow1, ',');
                                        *przecinek1 = 0;
                                        przecinek1++;
                                        liczbaszt1 = atoi(przecinek1);
                                        if(strcmp(nazwatow, nazwatow1)<0)
                                        {
                                            fprintf(zast,"%d,%s,%d\n",id,nazwatow,liczbaszt);
                                            fprintf(zast,"%d,%s,%d\n",id1,nazwatow1,liczbaszt1);
                                        }
                                        else
                                        {
                                            fprintf(zast,"%d,%s,%d\n",id1,nazwatow1,liczbaszt1);
                                            fprintf(zast,"%d,%s,%d\n",id,nazwatow,liczbaszt);
                                        }
                                    }
                                    fclose (bt);
                                    fclose (zast);
                                    remove("tow.txt");
                                    rename("zast.txt","tow.txt");
                                }
                            }
                            bt=fopen("tow.txt","r");
                            printf("\n");
                            for(i=0;i<ile;i++)
                            {

                                fscanf(bt,"%d,%s",&id,nazwatow);
                                char *przecine = strchr(nazwatow, ',');
                                *przecine=0;
                                przecine++;
                                liczbaszt = atoi(przecine);
                                printf("%d, %s, %d\n",id,nazwatow,liczbaszt);
                            }
                            fclose (bt);
                            printf("\n");
                            break;
                        case 'd':
                            while(1)
                            {
                                printf("Lista posortowana po nazwie firmy(t)\nLista posortowana po asortymencie(s)\nLista posortowana po nazwisku(d)\nPowrot do wczesniejszego menu(w)\n");
                                scanf("%s",&z);
                                if(z=='w')break;
                                switch(z)
                                {
                                    case 't':
                                        if(ileb%2==0)
                                        {
                                            for(t=0;t<ileb;t++)
                                            {
                                                bd=fopen("dos.txt","r");
                                                zast=fopen("zast.txt","a");
                                                for(i=0;i<ileb;i++)
                                                {
                                                    fscanf(bd,"%s",nazwafir);
                                                    char *przecinek = strchr(nazwafir, ',');
                                                    *przecinek = 0;
                                                    przecinek++;
                                                    char *przecine = strchr(przecinek, ',');
                                                    *przecine = 0;
                                                    przecine++;
                                                    char *przecin = strchr(przecine, ',');
                                                    *przecin = 0;
                                                    przecin++;
                                                    char *przeci = strchr(przecin, ',');
                                                    *przeci = 0;
                                                    przeci++;
                                                    char *przec = strchr(przeci, ',');
                                                    *przec = 0;
                                                    przec++;
                                                    identy = atoi(przec);
                                                    i++;
                                                    fscanf(bd,"%s",nazwafir1);
                                                    char *przecinek1 = strchr(nazwafir1, ',');
                                                    *przecinek1 = 0;
                                                    przecinek1++;
                                                    char *przecine1 = strchr(przecinek1, ',');
                                                    *przecine1 = 0;
                                                    przecine1++;
                                                    char *przecin1 = strchr(przecine1, ',');
                                                    *przecin1 = 0;
                                                    przecin1++;
                                                    char *przeci1 = strchr(przecin1, ',');
                                                    *przeci1 = 0;
                                                    przeci1++;
                                                    char *przec1 = strchr(przeci1, ',');
                                                    *przec1 = 0;
                                                    przec1++;
                                                    identy1 = atoi(przec1);
                                                    if(strcmp(nazwafir, nazwafir1)<0)
                                                    {

                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                    }
                                                    else
                                                    {
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                    }
                                                }
                                                fclose (bd);
                                                fclose (zast);
                                                remove("dos.txt");
                                                rename("zast.txt","dos.txt");
                                                bd=fopen("dos.txt","r");
                                                zast=fopen("zast.txt","a");
                                                fscanf(bd,"%s",nazwafir);
                                                char *przecinek = strchr(nazwafir, ',');
                                                *przecinek = 0;
                                                przecinek++;
                                                char *przecine = strchr(przecinek, ',');
                                                *przecine = 0;
                                                przecine++;
                                                char *przecin = strchr(przecine, ',');
                                                *przecin = 0;
                                                przecin++;
                                                char *przeci = strchr(przecin, ',');
                                                *przeci = 0;
                                                przeci++;
                                                char *przec = strchr(przeci, ',');
                                                *przec = 0;
                                                przec++;
                                                identy = atoi(przec);
                                                fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                for(i=2;i<ileb;i++)
                                                {
                                                    fscanf(bd,"%s",nazwafir);
                                                    char *przecinek = strchr(nazwafir, ',');
                                                    *przecinek = 0;
                                                    przecinek++;
                                                    char *przecine = strchr(przecinek, ',');
                                                    *przecine = 0;
                                                    przecine++;
                                                    char *przecin = strchr(przecine, ',');
                                                    *przecin = 0;
                                                    przecin++;
                                                    char *przeci = strchr(przecin, ',');
                                                    *przeci = 0;
                                                    przeci++;
                                                    char *przec = strchr(przeci, ',');
                                                    *przec = 0;
                                                    przec++;
                                                    identy = atoi(przec);
                                                    i++;
                                                    fscanf(bd,"%s",nazwafir1);
                                                    char *przecinek1 = strchr(nazwafir1, ',');
                                                    *przecinek1 = 0;
                                                    przecinek1++;
                                                    char *przecine1 = strchr(przecinek1, ',');
                                                    *przecine1 = 0;
                                                    przecine1++;
                                                    char *przecin1 = strchr(przecine1, ',');
                                                    *przecin1 = 0;
                                                    przecin1++;
                                                    char *przeci1 = strchr(przecin1, ',');
                                                    *przeci1 = 0;
                                                    przeci1++;
                                                    char *przec1 = strchr(przeci1, ',');
                                                    *przec1 = 0;
                                                    przec1++;
                                                    identy1 = atoi(przec1);
                                                    if(strcmp(nazwafir, nazwafir1)<0)
                                                    {
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                    }
                                                    else
                                                    {
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                    }
                                                }
                                                fscanf(bd,"%s",nazwafir1);
                                                char *przecinek1 = strchr(nazwafir1, ',');
                                                *przecinek1 = 0;
                                                przecinek1++;
                                                char *przecine1 = strchr(przecinek1, ',');
                                                *przecine1 = 0;
                                                przecine1++;
                                                char *przecin1 = strchr(przecine1, ',');
                                                *przecin1 = 0;
                                                przecin1++;
                                                char *przeci1 = strchr(przecin1, ',');
                                                *przeci1 = 0;
                                                przeci1++;
                                                char *przec1 = strchr(przeci1, ',');
                                                *przec1 = 0;
                                                przec1++;
                                                identy1 = atoi(przec1);
                                                fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                fclose (bd);
                                                fclose (zast);
                                                remove("dos.txt");
                                                rename("zast.txt","dos.txt");
                                            }
                                        }
                                        else
                                        {
                                            for(t=0;t<ileb;t++)
                                            {
                                                bd=fopen("dos.txt","r");
                                                zast=fopen("zast.txt","a");
                                                for(i=1;i<ileb;i++)
                                                {
                                                    fscanf(bd,"%s",nazwafir);
                                                    char *przecinek = strchr(nazwafir, ',');
                                                    *przecinek = 0;
                                                    przecinek++;
                                                    char *przecine = strchr(przecinek, ',');
                                                    *przecine = 0;
                                                    przecine++;
                                                    char *przecin = strchr(przecine, ',');
                                                    *przecin = 0;
                                                    przecin++;
                                                    char *przeci = strchr(przecin, ',');
                                                    *przeci = 0;
                                                    przeci++;
                                                    char *przec = strchr(przeci, ',');
                                                    *przec = 0;
                                                    przec++;
                                                    identy = atoi(przec);
                                                    i++;
                                                    fscanf(bd,"%s",nazwafir1);
                                                    char *przecinek1 = strchr(nazwafir1, ',');
                                                    *przecinek1 = 0;
                                                    przecinek1++;
                                                    char *przecine1 = strchr(przecinek1, ',');
                                                    *przecine1 = 0;
                                                    przecine1++;
                                                    char *przecin1 = strchr(przecine1, ',');
                                                    *przecin1 = 0;
                                                    przecin1++;
                                                    char *przeci1 = strchr(przecin1, ',');
                                                    *przeci1 = 0;
                                                    przeci1++;
                                                    char *przec1 = strchr(przeci1, ',');
                                                    *przec1 = 0;
                                                    przec1++;
                                                    identy1 = atoi(przec1);
                                                    if(strcmp(nazwafir, nazwafir1)<0)
                                                    {
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                    }
                                                    else
                                                    {
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                    }
                                                }
                                                fscanf(bd,"%s",nazwafir);
                                                char *przecinek = strchr(nazwafir, ',');
                                                *przecinek = 0;
                                                przecinek++;
                                                char *przecine = strchr(przecinek, ',');
                                                *przecine = 0;
                                                przecine++;
                                                char *przecin = strchr(przecine, ',');
                                                *przecin = 0;
                                                przecin++;
                                                char *przeci = strchr(przecin, ',');
                                                *przeci = 0;
                                                przeci++;
                                                char *przec = strchr(przeci, ',');
                                                *przec = 0;
                                                przec++;
                                                identy = atoi(przec);
                                                fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                fclose (bd);
                                                fclose (zast);
                                                remove("dos.txt");
                                                rename("zast.txt","dos.txt");
                                                bd=fopen("dos.txt","r");
                                                zast=fopen("zast.txt","a");
                                                fscanf(bd,"%s",nazwafir1);
                                                char *przecinek1 = strchr(nazwafir1, ',');
                                                *przecinek1 = 0;
                                                przecinek1++;
                                                char *przecine1 = strchr(przecinek1, ',');
                                                *przecine1 = 0;
                                                przecine1++;
                                                char *przecin1 = strchr(przecine1, ',');
                                                *przecin1 = 0;
                                                przecin1++;
                                                char *przeci1 = strchr(przecin1, ',');
                                                *przeci1 = 0;
                                                przeci1++;
                                                char *przec1 = strchr(przeci1, ',');
                                                *przec1 = 0;
                                                przec1++;
                                                identy1 = atoi(przec1);
                                                fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                for(i=1;i<ileb;i++)
                                                {
                                                    fscanf(bd,"%s",nazwafir);
                                                    char *przecinek = strchr(nazwafir, ',');
                                                    *przecinek = 0;
                                                    przecinek++;
                                                    char *przecine = strchr(przecinek, ',');
                                                    *przecine = 0;
                                                    przecine++;
                                                    char *przecin = strchr(przecine, ',');
                                                    *przecin = 0;
                                                    przecin++;
                                                    char *przeci = strchr(przecin, ',');
                                                    *przeci = 0;
                                                    przeci++;
                                                    char *przec = strchr(przeci, ',');
                                                    *przec = 0;
                                                    przec++;
                                                    identy = atoi(przec);
                                                    i++;
                                                    fscanf(bd,"%s",nazwafir1);
                                                    char *przecinek1 = strchr(nazwafir1, ',');
                                                    *przecinek1 = 0;
                                                    przecinek1++;
                                                    char *przecine1 = strchr(przecinek1, ',');
                                                    *przecine1 = 0;
                                                    przecine1++;
                                                    char *przecin1 = strchr(przecine1, ',');
                                                    *przecin1 = 0;
                                                    przecin1++;
                                                    char *przeci1 = strchr(przecin1, ',');
                                                    *przeci1 = 0;
                                                    przeci1++;
                                                    char *przec1 = strchr(przeci1, ',');
                                                    *przec1 = 0;
                                                    przec1++;
                                                    identy1 = atoi(przec1);
                                                    if(strcmp(nazwafir, nazwafir1)<0)
                                                    {
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                    }
                                                    else
                                                    {
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                    }
                                                }
                                                fclose (bd);
                                                fclose (zast);
                                                remove("dos.txt");
                                                rename("zast.txt","dos.txt");
                                            }
                                        }
                                        bd=fopen("dos.txt","r");
                                        printf("\n");
                                        for(i=0;i<ileb;i++)
                                        {
                                            fscanf(bd,"%s",nazwafir);
                                            char *przecinek = strchr(nazwafir, ',');
                                            *przecinek = 0;
                                            przecinek++;
                                            char *przecine = strchr(przecinek, ',');
                                            *przecine = 0;
                                            przecine++;
                                            char *przecin = strchr(przecine, ',');
                                            *przecin = 0;
                                            przecin++;
                                            char *przeci = strchr(przecin, ',');
                                            *przeci = 0;
                                            przeci++;
                                            char *przec = strchr(przeci, ',');
                                            *przec = 0;
                                            przec++;
                                            identy = atoi(przec);
                                            fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                        }
                                        fclose (bd);
                                        bd=fopen("dos.txt","r");
                                        printf("\n");
                                        for(i=0;i<ileb;i++)
                                        {
                                            fscanf(bd,"%s",nazwafir);
                                            char *przecinek = strchr(nazwafir, ',');
                                            *przecinek = 0;
                                            przecinek++;
                                            char *przecine = strchr(przecinek, ',');
                                            *przecine = 0;
                                            przecine++;
                                            char *przecin = strchr(przecine, ',');
                                            *przecin = 0;
                                            przecin++;
                                            char *przeci = strchr(przecin, ',');
                                            *przeci = 0;
                                            przeci++;
                                            char *przec = strchr(przeci, ',');
                                            *przec = 0;
                                            przec++;
                                            identy = atoi(przec);
                                            printf("%s, %s, %s, %s, %s, %d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                        }
                                        fclose (bd);

                                        break;
                                    case 's':
                                        if(ileb%2==0)
                                        {
                                            for(t=0;t<ileb;t++)
                                            {
                                                bd=fopen("dos.txt","r");
                                                zast=fopen("zast.txt","a");
                                                for(i=0;i<ileb;i++)
                                                {
                                                    fscanf(bd,"%s",nazwafir);
                                                    char *przecinek = strchr(nazwafir, ',');
                                                    *przecinek = 0;
                                                    przecinek++;
                                                    char *przecine = strchr(przecinek, ',');
                                                    *przecine = 0;
                                                    przecine++;
                                                    char *przecin = strchr(przecine, ',');
                                                    *przecin = 0;
                                                    przecin++;
                                                    char *przeci = strchr(przecin, ',');
                                                    *przeci = 0;
                                                    przeci++;
                                                    char *przec = strchr(przeci, ',');
                                                    *przec = 0;
                                                    przec++;
                                                    identy = atoi(przec);
                                                    i++;
                                                    fscanf(bd,"%s",nazwafir1);
                                                    char *przecinek1 = strchr(nazwafir1, ',');
                                                    *przecinek1 = 0;
                                                    przecinek1++;
                                                    char *przecine1 = strchr(przecinek1, ',');
                                                    *przecine1 = 0;
                                                    przecine1++;
                                                    char *przecin1 = strchr(przecine1, ',');
                                                    *przecin1 = 0;
                                                    przecin1++;
                                                    char *przeci1 = strchr(przecin1, ',');
                                                    *przeci1 = 0;
                                                    przeci1++;
                                                    char *przec1 = strchr(przeci1, ',');
                                                    *przec1 = 0;
                                                    przec1++;
                                                    identy1 = atoi(przec1);
                                                    if(strcmp(przeci, przeci1)<0)
                                                    {

                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                    }
                                                    else
                                                    {
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                    }
                                                }
                                                fclose (bd);
                                                fclose (zast);
                                                remove("dos.txt");
                                                rename("zast.txt","dos.txt");
                                                bd=fopen("dos.txt","r");
                                                zast=fopen("zast.txt","a");
                                                fscanf(bd,"%s",nazwafir);
                                                char *przecinek = strchr(nazwafir, ',');
                                                *przecinek = 0;
                                                przecinek++;
                                                char *przecine = strchr(przecinek, ',');
                                                *przecine = 0;
                                                przecine++;
                                                char *przecin = strchr(przecine, ',');
                                                *przecin = 0;
                                                przecin++;
                                                char *przeci = strchr(przecin, ',');
                                                *przeci = 0;
                                                przeci++;
                                                identy = atoi(przeci);
                                                fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                for(i=2;i<ileb;i++)
                                                {
                                                    fscanf(bd,"%s",nazwafir);
                                                    char *przecinek = strchr(nazwafir, ',');
                                                    *przecinek = 0;
                                                    przecinek++;
                                                    char *przecine = strchr(przecinek, ',');
                                                    *przecine = 0;
                                                    przecine++;
                                                    char *przecin = strchr(przecine, ',');
                                                    *przecin = 0;
                                                    przecin++;
                                                    char *przeci = strchr(przecin, ',');
                                                    *przeci = 0;
                                                    przeci++;
                                                    char *przec = strchr(przeci, ',');
                                                    *przec = 0;
                                                    przec++;
                                                    identy = atoi(przec);
                                                    i++;
                                                    fscanf(bd,"%s",nazwafir1);
                                                    char *przecinek1 = strchr(nazwafir1, ',');
                                                    *przecinek1 = 0;
                                                    przecinek1++;
                                                    char *przecine1 = strchr(przecinek1, ',');
                                                    *przecine1 = 0;
                                                    przecine1++;
                                                    char *przecin1 = strchr(przecine1, ',');
                                                    *przecin1 = 0;
                                                    przecin1++;
                                                    char *przeci1 = strchr(przecin1, ',');
                                                    *przeci1 = 0;
                                                    przeci1++;
                                                    char *przec1 = strchr(przeci1, ',');
                                                    *przec1 = 0;
                                                    przec1++;
                                                    identy1 = atoi(przec1);
                                                    if(strcmp(przeci, przeci1)<0)
                                                    {
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                    }
                                                    else
                                                    {
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                    }
                                                }
                                                fscanf(bd,"%s",nazwafir1);
                                                char *przecinek1 = strchr(nazwafir1, ',');
                                                *przecinek1 = 0;
                                                przecinek1++;
                                                char *przecine1 = strchr(przecinek1, ',');
                                                *przecine1 = 0;
                                                przecine1++;
                                                char *przecin1 = strchr(przecine1, ',');
                                                *przecin1 = 0;
                                                przecin1++;
                                                char *przeci1 = strchr(przecin1, ',');
                                                *przeci1 = 0;
                                                przeci1++;
                                                char *przec1 = strchr(przeci1, ',');
                                                *przec1 = 0;
                                                przec1++;
                                                identy1 = atoi(przec1);
                                                fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                fclose (bd);
                                                fclose (zast);
                                                remove("dos.txt");
                                                rename("zast.txt","dos.txt");
                                            }
                                        }
                                        else
                                        {
                                            for(t=0;t<ileb;t++)
                                            {
                                                bd=fopen("dos.txt","r");
                                                zast=fopen("zast.txt","a");
                                                for(i=1;i<ileb;i++)
                                                {
                                                    fscanf(bd,"%s",nazwafir);
                                                    char *przecinek = strchr(nazwafir, ',');
                                                    *przecinek = 0;
                                                    przecinek++;
                                                    char *przecine = strchr(przecinek, ',');
                                                    *przecine = 0;
                                                    przecine++;
                                                    char *przecin = strchr(przecine, ',');
                                                    *przecin = 0;
                                                    przecin++;
                                                    char *przeci = strchr(przecin, ',');
                                                    *przeci = 0;
                                                    przeci++;
                                                    char *przec = strchr(przeci, ',');
                                                    *przec = 0;
                                                    przec++;
                                                    identy = atoi(przec);
                                                    i++;
                                                    fscanf(bd,"%s",nazwafir1);
                                                    char *przecinek1 = strchr(nazwafir1, ',');
                                                    *przecinek1 = 0;
                                                    przecinek1++;
                                                    char *przecine1 = strchr(przecinek1, ',');
                                                    *przecine1 = 0;
                                                    przecine1++;
                                                    char *przecin1 = strchr(przecine1, ',');
                                                    *przecin1 = 0;
                                                    przecin1++;
                                                    char *przeci1 = strchr(przecin1, ',');
                                                    *przeci1 = 0;
                                                    przeci1++;
                                                    char *przec1 = strchr(przeci1, ',');
                                                    *przec1 = 0;
                                                    przec1++;
                                                    identy1 = atoi(przec1);
                                                    if(strcmp(przeci, przeci1)<0)
                                                    {
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                    }
                                                    else
                                                    {
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                    }
                                                }
                                                fscanf(bd,"%s",nazwafir);
                                                char *przecinek = strchr(nazwafir, ',');
                                                *przecinek = 0;
                                                przecinek++;
                                                char *przecine = strchr(przecinek, ',');
                                                *przecine = 0;
                                                przecine++;
                                                char *przecin = strchr(przecine, ',');
                                                *przecin = 0;
                                                przecin++;
                                                char *przeci = strchr(przecin, ',');
                                                *przeci = 0;
                                                przeci++;
                                                char *przec = strchr(przeci, ',');
                                                *przec = 0;
                                                przec++;
                                                identy = atoi(przec);
                                                fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                fclose (bd);
                                                fclose (zast);
                                                remove("dos.txt");
                                                rename("zast.txt","dos.txt");
                                                bd=fopen("dos.txt","r");
                                                zast=fopen("zast.txt","a");
                                                fscanf(bd,"%s",nazwafir1);
                                                char *przecinek1 = strchr(nazwafir1, ',');
                                                *przecinek1 = 0;
                                                przecinek1++;
                                                char *przecine1 = strchr(przecinek1, ',');
                                                *przecine1 = 0;
                                                przecine1++;
                                                char *przecin1 = strchr(przecine1, ',');
                                                *przecin1 = 0;
                                                przecin1++;
                                                char *przeci1 = strchr(przecin1, ',');
                                                *przeci1 = 0;
                                                przeci1++;
                                                char *przec1 = strchr(przeci1, ',');
                                                *przec1 = 0;
                                                przec1++;
                                                identy1 = atoi(przec1);
                                                fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                for(i=1;i<ileb;i++)
                                                {
                                                    fscanf(bd,"%s",nazwafir);
                                                    char *przecinek = strchr(nazwafir, ',');
                                                    *przecinek = 0;
                                                    przecinek++;
                                                    char *przecine = strchr(przecinek, ',');
                                                    *przecine = 0;
                                                    przecine++;
                                                    char *przecin = strchr(przecine, ',');
                                                    *przecin = 0;
                                                    przecin++;
                                                    char *przeci = strchr(przecin, ',');
                                                    *przeci = 0;
                                                    przeci++;
                                                    char *przec = strchr(przeci, ',');
                                                    *przec = 0;
                                                    przec++;
                                                    identy = atoi(przec);
                                                    i++;
                                                    fscanf(bd,"%s",nazwafir1);
                                                    char *przecinek1 = strchr(nazwafir1, ',');
                                                    *przecinek1 = 0;
                                                    przecinek1++;
                                                    char *przecine1 = strchr(przecinek1, ',');
                                                    *przecine1 = 0;
                                                    przecine1++;
                                                    char *przecin1 = strchr(przecine1, ',');
                                                    *przecin1 = 0;
                                                    przecin1++;
                                                    char *przeci1 = strchr(przecin1, ',');
                                                    *przeci1 = 0;
                                                    przeci1++;
                                                    char *przec1 = strchr(przeci1, ',');
                                                    *przec1 = 0;
                                                    przec1++;
                                                    identy1 = atoi(przec1);
                                                    if(strcmp(przeci, przeci1)<0)
                                                    {
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                    }
                                                    else
                                                    {
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                    }
                                                }
                                                fclose (bd);
                                                fclose (zast);
                                                remove("dos.txt");
                                                rename("zast.txt","dos.txt");
                                            }
                                        }
                                        bd=fopen("dos.txt","r");
                                        printf("\n");
                                        for(i=0;i<ileb;i++)
                                        {
                                            fscanf(bd,"%s",nazwafir);
                                            char *przecinek = strchr(nazwafir, ',');
                                            *przecinek = 0;
                                            przecinek++;
                                            char *przecine = strchr(przecinek, ',');
                                            *przecine = 0;
                                            przecine++;
                                            char *przecin = strchr(przecine, ',');
                                            *przecin = 0;
                                            przecin++;
                                            char *przeci = strchr(przecin, ',');
                                            *przeci = 0;
                                            przeci++;
                                            char *przec = strchr(przeci, ',');
                                            *przec = 0;
                                            przec++;
                                            identy = atoi(przec);
                                            printf("%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                        }
                                        printf("\n");
                                        fclose (bd);
                                        break;
                                    case 'd':
                                        if(ileb%2==0)
                                        {
                                            for(t=0;t<ileb;t++)
                                            {
                                                bd=fopen("dos.txt","r");
                                                zast=fopen("zast.txt","a");
                                                for(i=0;i<ileb;i++)
                                                {
                                                    fscanf(bd,"%s",nazwafir);
                                                    char *przecinek = strchr(nazwafir, ',');
                                                    *przecinek = 0;
                                                    przecinek++;
                                                    char *przecine = strchr(przecinek, ',');
                                                    *przecine = 0;
                                                    przecine++;
                                                    char *przecin = strchr(przecine, ',');
                                                    *przecin = 0;
                                                    przecin++;
                                                    char *przeci = strchr(przecin, ',');
                                                    *przeci = 0;
                                                    przeci++;
                                                    char *przec = strchr(przeci, ',');
                                                    *przec = 0;
                                                    przec++;
                                                    identy = atoi(przec);
                                                    i++;
                                                    fscanf(bd,"%s",nazwafir1);
                                                    char *przecinek1 = strchr(nazwafir1, ',');
                                                    *przecinek1 = 0;
                                                    przecinek1++;
                                                    char *przecine1 = strchr(przecinek1, ',');
                                                    *przecine1 = 0;
                                                    przecine1++;
                                                    char *przecin1 = strchr(przecine1, ',');
                                                    *przecin1 = 0;
                                                    przecin1++;
                                                    char *przeci1 = strchr(przecin1, ',');
                                                    *przeci1 = 0;
                                                    przeci1++;
                                                    char *przec1 = strchr(przeci1, ',');
                                                    *przec1 = 0;
                                                    przec1++;
                                                    identy1 = atoi(przec1);
                                                    if(strcmp(przeci, przeci1)<0)
                                                    {

                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                    }
                                                    else
                                                    {
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                    }
                                                }
                                                fclose (bd);
                                                fclose (zast);
                                                remove("dos.txt");
                                                rename("zast.txt","dos.txt");
                                                bd=fopen("dos.txt","r");
                                                zast=fopen("zast.txt","a");
                                                fscanf(bd,"%s",nazwafir);
                                                char *przecinek = strchr(nazwafir, ',');
                                                *przecinek = 0;
                                                przecinek++;
                                                char *przecine = strchr(przecinek, ',');
                                                *przecine = 0;
                                                przecine++;
                                                char *przecin = strchr(przecine, ',');
                                                *przecin = 0;
                                                przecin++;
                                                char *przeci = strchr(przecin, ',');
                                                *przeci = 0;
                                                przeci++;
                                                char *przec = strchr(przeci, ',');
                                                *przec = 0;
                                                przec++;
                                                identy = atoi(przec);
                                                fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                for(i=2;i<ileb;i++)
                                                {
                                                    fscanf(bd,"%s",nazwafir);
                                                    char *przecinek = strchr(nazwafir, ',');
                                                    *przecinek = 0;
                                                    przecinek++;
                                                    char *przecine = strchr(przecinek, ',');
                                                    *przecine = 0;
                                                    przecine++;
                                                    char *przecin = strchr(przecine, ',');
                                                    *przecin = 0;
                                                    przecin++;
                                                    char *przeci = strchr(przecin, ',');
                                                    *przeci = 0;
                                                    przeci++;
                                                    char *przec = strchr(przeci, ',');
                                                    *przec = 0;
                                                    przec++;
                                                    identy = atoi(przec);
                                                    i++;
                                                    fscanf(bd,"%s",nazwafir1);
                                                    char *przecinek1 = strchr(nazwafir1, ',');
                                                    *przecinek1 = 0;
                                                    przecinek1++;
                                                    char *przecine1 = strchr(przecinek1, ',');
                                                    *przecine1 = 0;
                                                    przecine1++;
                                                    char *przecin1 = strchr(przecine1, ',');
                                                    *przecin1 = 0;
                                                    przecin1++;
                                                    char *przeci1 = strchr(przecin1, ',');
                                                    *przeci1 = 0;
                                                    przeci1++;
                                                    char *przec1 = strchr(przeci1, ',');
                                                    *przec1 = 0;
                                                    przec1++;
                                                    identy1 = atoi(przec1);
                                                    if(strcmp(przecine, przecine1)<0)
                                                    {
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                    }
                                                    else
                                                    {
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                    }
                                                }
                                                fscanf(bd,"%s",nazwafir1);
                                                char *przecinek1 = strchr(nazwafir1, ',');
                                                *przecinek1 = 0;
                                                przecinek1++;
                                                char *przecine1 = strchr(przecinek1, ',');
                                                *przecine1 = 0;
                                                przecine1++;
                                                char *przecin1 = strchr(przecine1, ',');
                                                *przecin1 = 0;
                                                przecin1++;
                                                char *przeci1 = strchr(przecin1, ',');
                                                *przeci1 = 0;
                                                przeci1++;
                                                char *przec1 = strchr(przeci1, ',');
                                                *przec1 = 0;
                                                przec1++;
                                                identy1 = atoi(przec1);
                                                fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                fclose (bd);
                                                fclose (zast);
                                                remove("dos.txt");
                                                rename("zast.txt","dos.txt");
                                            }
                                        }
                                        else
                                        {
                                            for(t=0;t<ileb;t++)
                                            {
                                                bd=fopen("dos.txt","r");
                                                zast=fopen("zast.txt","a");
                                                for(i=1;i<ileb;i++)
                                                {
                                                    fscanf(bd,"%s",nazwafir);
                                                    char *przecinek = strchr(nazwafir, ',');
                                                    *przecinek = 0;
                                                    przecinek++;
                                                    char *przecine = strchr(przecinek, ',');
                                                    *przecine = 0;
                                                    przecine++;
                                                    char *przecin = strchr(przecine, ',');
                                                    *przecin = 0;
                                                    przecin++;
                                                    char *przeci = strchr(przecin, ',');
                                                    *przeci = 0;
                                                    przeci++;
                                                    char *przec = strchr(przeci, ',');
                                                    *przec = 0;
                                                    przec++;
                                                    identy = atoi(przec);
                                                    i++;
                                                    fscanf(bd,"%s",nazwafir1);
                                                    char *przecinek1 = strchr(nazwafir1, ',');
                                                    *przecinek1 = 0;
                                                    przecinek1++;
                                                    char *przecine1 = strchr(przecinek1, ',');
                                                    *przecine1 = 0;
                                                    przecine1++;
                                                    char *przecin1 = strchr(przecine1, ',');
                                                    *przecin1 = 0;
                                                    przecin1++;
                                                    char *przeci1 = strchr(przecin1, ',');
                                                    *przeci1 = 0;
                                                    przeci1++;
                                                    char *przec1 = strchr(przeci1, ',');
                                                    *przec1 = 0;
                                                    przec1++;
                                                    identy1 = atoi(przec1);
                                                    if(strcmp(przecine, przecine1)<0)
                                                    {
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                    }
                                                    else
                                                    {
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                    }
                                                }
                                                fscanf(bd,"%s",nazwafir);
                                                char *przecinek = strchr(nazwafir, ',');
                                                *przecinek = 0;
                                                przecinek++;
                                                char *przecine = strchr(przecinek, ',');
                                                *przecine = 0;
                                                przecine++;
                                                char *przecin = strchr(przecine, ',');
                                                *przecin = 0;
                                                przecin++;
                                                char *przeci = strchr(przecin, ',');
                                                *przeci = 0;
                                                przeci++;
                                                char *przec = strchr(przeci, ',');
                                                *przec = 0;
                                                przec++;
                                                identy = atoi(przec);
                                                fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                fclose (bd);
                                                fclose (zast);
                                                remove("dos.txt");
                                                rename("zast.txt","dos.txt");
                                                bd=fopen("dos.txt","r");
                                                zast=fopen("zast.txt","a");
                                                fscanf(bd,"%s",nazwafir1);
                                                char *przecinek1 = strchr(nazwafir1, ',');
                                                *przecinek1 = 0;
                                                przecinek1++;
                                                char *przecine1 = strchr(przecinek1, ',');
                                                *przecine1 = 0;
                                                przecine1++;
                                                char *przecin1 = strchr(przecine1, ',');
                                                *przecin1 = 0;
                                                przecin1++;
                                                char *przeci1 = strchr(przecin1, ',');
                                                *przeci1 = 0;
                                                przeci1++;
                                                char *przec1 = strchr(przeci1, ',');
                                                *przec1 = 0;
                                                przec1++;
                                                identy1 = atoi(przec1);
                                                fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                for(i=1;i<ileb;i++)
                                                {
                                                    fscanf(bd,"%s",nazwafir);
                                                    char *przecinek = strchr(nazwafir, ',');
                                                    *przecinek = 0;
                                                    przecinek++;
                                                    char *przecine = strchr(przecinek, ',');
                                                    *przecine = 0;
                                                    przecine++;
                                                    char *przecin = strchr(przecine, ',');
                                                    *przecin = 0;
                                                    przecin++;
                                                    char *przeci = strchr(przecin, ',');
                                                    *przeci = 0;
                                                    przeci++;
                                                    char *przec = strchr(przeci, ',');
                                                    *przec = 0;
                                                    przec++;
                                                    identy = atoi(przec);
                                                    i++;
                                                    fscanf(bd,"%s",nazwafir1);
                                                    char *przecinek1 = strchr(nazwafir1, ',');
                                                    *przecinek1 = 0;
                                                    przecinek1++;
                                                    char *przecine1 = strchr(przecinek1, ',');
                                                    *przecine1 = 0;
                                                    przecine1++;
                                                    char *przecin1 = strchr(przecine1, ',');
                                                    *przecin1 = 0;
                                                    przecin1++;
                                                    char *przeci1 = strchr(przecin1, ',');
                                                    *przeci1 = 0;
                                                    przeci1++;
                                                    char *przec1 = strchr(przeci1, ',');
                                                    *przec1 = 0;
                                                    przec1++;
                                                    identy1 = atoi(przec1);
                                                    if(strcmp(przecine, przecine1)<0)
                                                    {
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                    }
                                                    else
                                                    {
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                                        fprintf(zast,"%s,%s,%s,%s,%s,%d\n",nazwafir,przecinek,przecine,przecin,przeci,identy);
                                                    }
                                                }
                                                fclose (bd);
                                                fclose (zast);
                                                remove("dos.txt");
                                                rename("zast.txt","dos.txt");
                                            }
                                        }
                                        bd=fopen("dos.txt","r");
                                        printf("\n");
                                        for(i=0;i<ileb;i++)
                                        {
                                            fscanf(bd,"%s",nazwafir1);
                                            char *przecinek1 = strchr(nazwafir1, ',');
                                            *przecinek1 = 0;
                                            przecinek1++;
                                            char *przecine1 = strchr(przecinek1, ',');
                                            *przecine1 = 0;
                                            przecine1++;
                                            char *przecin1 = strchr(przecine1, ',');
                                            *przecin1 = 0;
                                            przecin1++;
                                            char *przeci1 = strchr(przecin1, ',');
                                            *przeci1 = 0;
                                            przeci1++;
                                            char *przec1 = strchr(przeci1, ',');
                                            *przec1 = 0;
                                            przec1++;
                                            identy = atoi(przec1);
                                            printf("%s,%s,%s,%s,%s,%d\n",nazwafir1,przecinek1,przecine1,przecin1,przeci1,identy1);
                                        }
                                        printf("\n");
                                        fclose (bd);
                                        break;
                                    default:
                                        printf("Podano bledna litere, sprobuj ponownie");
                                        break;
                                }
                            }
                            break;
                        default:
                            printf("Podano bledna litere, sprobuj ponownie");
                            break;
                    }
                }
                break;
            case 'b':
                bt=fopen("tow.txt","r");
                printf("\nBrakuje towarow:\n");
                for(i=0;i<ile;i++)
                {
                    fscanf(bt,"%d,%s",&id,nazwatow);
                    char *przecinek = strchr(nazwatow, ',');
                    *przecinek = 0;
                    przecinek++;
                    liczbaszt = atoi(przecinek);
                    if(liczbaszt==0)
                    {
                        printf("%s\n",nazwatow);
                        v++;
                    }
                }
                printf("\n");
                if(v==0)
                    printf("Nie brakuje zadnego towaru\n\n");
                fclose (bt);

                break;
            default:
                printf("Podano bledna litere, sprobuj ponownie\n");
                break;
        }
    }
    return 0;
}