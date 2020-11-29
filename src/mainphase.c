#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mainphase.h"

extern MATRIKS M;
extern Player P1;
extern int menu1;
extern Kata name;
extern POINT PosPlayer;
extern int Money;
extern int currDay;

void legendMain(Player P1, int TotalAksi, int TotalDetikJam, int TotalUangPreparation)
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