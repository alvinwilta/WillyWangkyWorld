#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./wahana/wahana.h"
#include "./jam/jam.h"
#include "./tree/bintree.h"
#include "./matriks/matriks.h"
#include "./tree/listrek.h"
#include "./point/point.h"
#include "./player/player.h"
#include "./stack/stack.h"
#include "preparation.h"

int TotalUangPreparation = 0;
int TotalAksi = 0;
long TotalDetikJam = 0;
int TotalWahana = 0;
char ListNamaWahana[10][30] = {"halilintar", "bianglala", "niagara", "korakora", "tornado", "kicirkicir", "skydiver", "balloon", "freefall", "madhouse"};

// build = 10001, upgrade = 10002, buy = 10003, undo = 10004, execute = 10005, main = 10006
// build
// 10001, 1-10, x, y,       [10001,1,1,1]
// upgrade
// 10002, id, 1-2,
// buy
// 10003, 1-3, N            [10003,1,200]
// undo
// 10004
// execute
// 10005
// main
// 10006

extern MATRIKS M;
extern Player P1;
extern int menu1;
extern Kata name;
extern POINT PosPlayer;
extern int Money;
extern int currDay;
extern Stack S;
extern BinTree WahanaUpgrade;

Wahana Build(Player *P, POINT pos)
{

    printf("Pilih wahana yang akan dibangun:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("    - %s\n", ListNamaWahana[i]);
    }
    char wahanaName[30];
    scanf("%s", wahanaName);
    int id = TotalWahana + 1;
    Wahana W = NewWahana(wahanaName, id, pos);
    Mundur(P);
    Money(P) -= 350;
    TotalWahana += 1;
    TotalDetikJam += 7200;
    return W;

    // push [build,namawahana,pos,delimiter]
    Push(&S, Ordinat(Pos(P)));
    Push(&S, Absis(Pos(P)));
    if (!strcmp(wahanaName, "halilintar"))
    {
        Push(&S, 1);
    }
    else if (!strcmp(wahanaName, "bianglala"))
    {
        Push(&S, 2);
    }
    else if (!strcmp(wahanaName, "niagara"))
    {
        Push(&S, 3);
    }
    else if (!strcmp(wahanaName, "korakora"))
    {
        Push(&S, 4);
    }
    else if (!strcmp(wahanaName, "tornado"))
    {
        Push(&S, 5);
    }
    else if (!strcmp(wahanaName, "kicirkicir"))
    {
        Push(&S, 6);
    }
    else if (!strcmp(wahanaName, "skydiver"))
    {
        Push(&S, 7);
    }
    else if (!strcmp(wahanaName, "balloon"))
    {
        Push(&S, 8);
    }
    else if (!strcmp(wahanaName, "freefall"))
    {
        Push(&S, 9);
    }
    else if (!strcmp(wahanaName, "madhouse"))
    {
        Push(&S, 10);
    }
    Push(&S, 10001);
}

void UpgradeWahana(Player *P, Wahana *W)
{
    char pilihan[30];

    if (Money(P) <= 350)
    {
        printf("Uang anda tidak cukup untuk melakukan upgrade apapun!\n");
    }
    else if (!(JenisW(W), "halilintar"))
    {
        printf("List upgrade:\n");
        printf("    - listrikhalilintar\n");
        printf("    - attahalilintar\n");
        scanf("%s", pilihan);
        if (!strcmp(pilihan, "listrikhalilintar"))
        {
            upgrade(W, 0, WahanaUpgrade);
            Push(&S, 0);
        }
        else
        {
            upgrade(W, 1, WahanaUpgrade);
            Push(&S, 1);
        }
    }
    else if (!(JenisW(W), "bianglala"))
    {
        printf("List upgrade:\n");
        printf("    - listrikbianglala\n");
        printf("    - attabianglala\n");
        scanf("%s", pilihan);
        if (!strcmp(pilihan, "listrikbianglala"))
        {
            upgrade(W, 0, WahanaUpgrade);
            Push(&S, 0);
        }
        else
        {
            upgrade(W, 1, WahanaUpgrade);
            Push(&S, 1);
        }
    }
    else if (!(JenisW(W), "niagara"))
    {
        printf("List upgrade:\n");
        printf("    - listrikniagara\n");
        printf("    - attaniagara\n");
        scanf("%s", pilihan);
        if (!strcmp(pilihan, "listrikniagara"))
        {
            upgrade(W, 0, WahanaUpgrade);
            Push(&S, 0);
        }
        else
        {
            upgrade(W, 1, WahanaUpgrade);
            Push(&S, 1);
        }
    }
    else if (!(JenisW(W), "korakora"))
    {
        printf("List upgrade:\n");
        printf("    - listrikkorakora\n");
        printf("    - attakorakora\n");
        scanf("%s", pilihan);
        if (!strcmp(pilihan, "listrikkorakora"))
        {
            upgrade(W, 0, WahanaUpgrade);
            Push(&S, 0);
        }
        else
        {
            upgrade(W, 1, WahanaUpgrade);
            Push(&S, 1);
        }
    }
    else if (!(JenisW(W), "tornado"))
    {
        printf("List upgrade:\n");
        printf("    - listriktornado\n");
        printf("    - attatornado\n");
        scanf("%s", pilihan);
        if (!strcmp(pilihan, "listriktornado"))
        {
            upgrade(W, 0, WahanaUpgrade);
            Push(&S, 0);
        }
        else
        {
            upgrade(W, 1, WahanaUpgrade);
            Push(&S, 1);
        }
    }
    else if (!(JenisW(W), "kicirkicir"))
    {
        printf("List upgrade:\n");
        printf("    - listrikkicirkicir\n");
        printf("    - attakicirkicir\n");
        scanf("%s", pilihan);
        if (!strcmp(pilihan, "listrikkicirkicir"))
        {
            upgrade(W, 0, WahanaUpgrade);
            Push(&S, 0);
        }
        else
        {
            upgrade(W, 1, WahanaUpgrade);
            Push(&S, 1);
        }
    }
    else if (!(JenisW(W), "skydiver"))
    {
        printf("List upgrade:\n");
        printf("    - listrikskydiver\n");
        printf("    - attaskydiver\n");
        scanf("%s", pilihan);
        if (!strcmp(pilihan, "listrikskydiver"))
        {
            upgrade(W, 0, WahanaUpgrade);
            Push(&S, 0);
        }
        else
        {
            upgrade(W, 1, WahanaUpgrade);
            Push(&S, 1);
        }
    }
    else if (!(JenisW(W), "balloon"))
    {
        printf("List upgrade:\n");
        printf("    - listrikballoon\n");
        printf("    - attaballoon\n");
        scanf("%s", pilihan);
        if (!strcmp(pilihan, "listrikballoon"))
        {
            upgrade(W, 0, WahanaUpgrade);
            Push(&S, 0);
        }
        else
        {
            upgrade(W, 1, WahanaUpgrade);
            Push(&S, 1);
        }
    }
    else if (!(JenisW(W), "freefall"))
    {
        printf("List upgrade:\n");
        printf("    - listrikfreefall\n");
        printf("    - attafreefall\n");
        scanf("%s", pilihan);
        if (!strcmp(pilihan, "listrikfreefall"))
        {
            upgrade(W, 0, WahanaUpgrade);
            Push(&S, 0);
        }
        else
        {
            upgrade(W, 1, WahanaUpgrade);
            Push(&S, 1);
        }
    }
    else if (!(JenisW(W), "madhouse"))
    {
        printf("List upgrade:\n");
        printf("    - listrikmadhouse\n");
        printf("    - attamadhouse\n");
        scanf("%s", pilihan);
        if (!strcmp(pilihan, "listrikmadhouse"))
        {
            upgrade(W, 0, WahanaUpgrade);
            Push(&S, 0);
        }
        else
        {
            upgrade(W, 1, WahanaUpgrade);
            Push(&S, 1);
        }
    }

    Push(&S, IDW(W));
    Push(&S, 10002);
}

void Buy(Player *P)
{
    char BuyItem[5];
    int TotalItem;
    do
    {
        printf("Ingin membeli apa?\n");
        printf("    - kayu\n");
        printf("    - batu\n");
        printf("    - paku\n");
        scanf("%d", &TotalItem);
        scanf("%s", BuyItem);
    } while (strcmp(BuyItem, "kayu") || strcmp(BuyItem, "batu") || strcmp(BuyItem, "paku") || TotalItem <= 0);

    boolean UangCukup;
    int totalUang = 0;
    if (!strcmp(BuyItem, "kayu"))
    {
        UangCukup = IsUangCukup(*P, TotalItem, 0);
        if (UangCukup)
        {
            totalUang = 10 * TotalItem;
            AddKayu(P, TotalItem);
        }
        else
        {
            printf("Uang anda tidak cukup!\n");
        }
    }
    else if (!strcmp(BuyItem, "batu"))
    {
        UangCukup = IsUangCukup(*P, TotalItem, 1);
        if (UangCukup)
        {
            totalUang = 20 * TotalItem;
            AddBatu(P, TotalItem);
        }
        else
        {
            printf("Uang anda tidak cukup!\n");
        }
    }
    else // BuyItem == "paku"
    {
        UangCukup = IsUangCukup(*P, TotalItem, 2);
        if (UangCukup)
        {
            totalUang = 30 * TotalItem;
            AddPaku(P, TotalItem);
        }
        else
        {
            printf("Uang anda tidak cukup!\n");
        }
    }
    TotalUangPreparation += totalUang;
    TotalAksi += 1;
    TotalDetikJam += 3600;

    // pushstack [buy,material,jumlah]
    Push(&S, TotalItem);
    if (!strcmp(BuyItem, "kayu"))
    {
        Push(&S, 1);
    }
    else if (!strcmp(BuyItem, "batu"))
    {
        Push(&S, 2);
    }
    else if (!strcmp(BuyItem, "paku"))
    {
        Push(&S, 3);
    }
    Push(&S, 10003);
}

void deBuy(Player *P, int wahanaName, int N)
{
    int totalRefund = 0;
    if (wahanaName = 0)
    {
        totalRefund = 10 * N;
        AddUang(P, totalRefund);
        SubKayu(P, N);
    }
    else if (wahanaName = 1)
    {
        totalRefund = 20 * N;
        AddUang(P, totalRefund);
        SubBatu(P, N);
    }
    else
    { // wahanaName = 2 (paku)
        totalRefund = 30 * N;
        AddUang(P, totalRefund);
        SubKayu(P, N);
    }
}

void legendPrep(Player P1, int TotalAksi, int TotalDetikJam, int TotalUangPreparation)
{
    JAM PrepTime;
    PrepTime = DetikToJAM(75600);
    int hour = TotalDetikJam / 3600;
    int menit = (TotalDetikJam % 3600) / 60;
    // printMap(M); // harusnya prosedure print map yang dipakai di main, akan ditambahkan di extern
    printf("\nLegend:\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<, ^, >, V = Gerbang\n");
    printf("\n");
    printf("Nama: ");
    printKata(name);
    printf("Money: ");
    printf("%d\n", Money(&P1));
    printf("Current Time: ");
    TulisJAM(PrepTime);
    printf("\nOpening Time: 09.00\n");
    printf("Time Remaining: 12 hour(s)\n");
    printf("Total aksi yang akan dilakukan: ");
    printf("%d", TotalAksi);
    printf("\n");
    printf("Total waktu yang dibutuhkan: ");
    printf("%d", hour);
    printf(" hour(s) ");
    printf("%d", menit);
    printf(" minute(s)\n");
    printf("Total uang yang dibutuhkan: ");
    printf("%d", TotalUangPreparation);
    printf("\n");
}

void Preparation(Player P)
{
    char perintah[40];
    printf("Preparation phase day %d", currDay);
    int cekTotalDetikJam = TotalDetikJam;
    do
    {
        legendPrep(P, TotalAksi, TotalDetikJam, TotalUangPreparation);
        printf("\nMasukkan Perintah:\n");
        scanf("%s", perintah);
        if (!strcmp(perintah, "build"))
        {
            if (cekTotalDetikJam + 7200 <= 75600)
                Build(&P, Pos(&P));
            else
            {
                printf("Waktu preparation tidak mencukupi untuk melakukan aksi!\n");
            }
        }
        else if (!strcmp(perintah, "buy"))
        {
            if (cekTotalDetikJam + 7200 <= 75600)
                if (Money(&P) >= 350)
                {
                    Buy(&P);
                }
                else
                {
                    printf("Uang anda tidak cukup untuk membangun wahana apapun!\n");
                }
            else
            {
                printf("Waktu preparation tidak mencukupi untuk melakukan aksi!\n");
            }
        }

    } while (TotalDetikJam <= 75600 && strcmp(perintah, "main"));
}

// void Undo(Wahana W) // belum selesai
// {
//     pop(W);
//     deBuy(P, wahanaName, N);
//     TotalUangPreparation += totalUang;
//     TotalAksi += 1;
// }