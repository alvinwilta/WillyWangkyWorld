#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mainphase.h"

PrioQ PQ1;
extern MATRIKS M;
extern Player P1;
extern int menu1;
extern Kata name;
extern POINT PosPlayer;
extern int Money;
extern int currDay;
extern int X;
extern Queue Q1;
Wahana W1;

void legendMain(Player P1)
{
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
    printf("Current Time: "); printf("%02d",Hour(Wkt(&P1)));printf(".%02d\n",Minute(Wkt(&P1)));
    printf("\nOpening Time: 09.00\n");
    printf("Time Remaining: 12 hour(s)\n");
    printf("Antrian [");printf("%d",NBElmtPrio(PQ1));printf("/5]\n");
    PrintPrioQueue(PQ1);
    printf("\n");
}

void PrintDetail(Wahana W1){
    printf("Nama : %s\n", JenisW(&W1));
    printf("Lokasi : (%d,%d)\n", Absis(PosW(&W1)),Ordinat(PosW(&W1)));
    //printf("Upgrades(s) : %s\n", DeskripsiW(W));
    printf("Harga : \n",);
    if (Rusak(&W1))
        printf("Status : Rusak\n");
    else
        printf("Status : Berfungsi\n");
}

void Detail(Player P1, Wahana W1){
    
    //if (Absis(Pos(&P1)) == Absis(PosW(&W1)) && Ordinat(Pos(&P1)) == Ordinat(PosW(&W1))+1 {
        // Wahana berada di atas player
        
    }
    /*
    else if (Absis(Pos(&P1)) == Absis(PosW(&W1)) && Ordinat(Pos(&P1)) == Ordinat(PosW(&W1))-1 {
        // Wahana berada di bawah player
    }
    else if (Absis(Pos(&P1)) == Absis(PosW(&W1))-1 && Ordinat(Pos(&P1))== Ordinat(PosW(&W1))) {
        // Wahana berada di kanan player
    }
    else if (Absis(Pos(&P1)) == Absis(PosW(&W1))+1 && Ordinat(Pos(&P1))== Ordinat(PosW(&W1))) {
        // Wahana berada di kiri player
    }
    */
}

void Serve(int * ID){
    /*Serve sehingga dequeue*/
    Wahana W;
    IDW(&W) = ID;
    DequeueQ(&Q1,X);
    if(IsEmptyQ(Q1)){
        DequeuePrio()
    }
    AddWaktu(&P1,10);
}