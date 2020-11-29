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

int TotalUangPreparation = 0;
int TotalAksi = 0;
long TotalDetikJam = 0;
int TotalWahana = 0;
char ListNamaWahana[10][30] = {"halilintar", "bianglala", "niagara", "korakora", "tornado", "kicirkicir", "skydiver", "balloon", "freefall", "madhouse"};

extern MATRIKS M;
extern Player P1;
extern int menu1;
extern Kata name;
extern POINT PosPlayer;
extern int Money;
extern int currDay;

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
    // pushstack ("buy,jenis,jumlah")
}

void deBuy(Player *P, int jenis, int N)
{
    int totalRefund = 0;
    if (jenis = 0)
    {
        totalRefund = 10 * N;
        AddUang(P, totalRefund);
        SubKayu(P, N);
    }
    else if (jenis = 1)
    {
        totalRefund = 20 * N;
        AddUang(P, totalRefund);
        SubBatu(P, N);
    }
    else
    { // jenis = 2 (paku)
        totalRefund = 30 * N;
        AddUang(&P, totalRefund);
        SubKayu(&P, N);
    }
    // popstack()
}
// void Upgrade(Wahana W, POINT p)
// {
//     printf("Ingin melakukan upgrade apa ?\n");
//     printf("List: \n");
//     printf("    - <wahana>\n");
//     printf("    - <wahana>\n");
//     char wahanaName[30];
//     scanf("%s", wahanaName);
//
//
// }

void legendPrep(Player P1, int TotalAksi, int TotalDetikJam, int TotalUangPreparation)
{
    JAM PrepTime;
    PrepTime = DetikToJAM(75600);
    int hour = TotalDetikJam / 3600;
    int menit = (TotalDetikJam % 3600) / 60;
    printMap(M);
    printf("Legend:\n");
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
    printf("Opening Time: 09.00\n");
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
//     deBuy(P, jenis, N);
//     TotalUangPreparation += totalUang;
//     TotalAksi += 1;
// }