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
extern int X;
extern Queue Q1;
extern PrioQ PQ1;
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
    printf("Deskripsi : %s\n", DeskripsiW(&W1));
    printf("Harga : %d\n", TarifW(&W1));
    printf("Kapasitas : %d \n", KapasitasW(&W1));
    printf("Upgrade(s) : \n");
    printf("Durasi : %d\n", DurasiW(&W1));
    if (Rusak(&W1))
        printf("Status : Rusak\n");
    else
        printf("Status : Berfungsi\n");
}

void Detail(Player P1, Wahana W1){
    if (Absis(Pos(&P1)) == Absis(PosW(&W1)) && Ordinat(Pos(&P1)) == Ordinat(PosW(&W1))+1) {
        // Wahana berada di atas player
        PrintDetail(W1);
    }
    else if (Absis(Pos(&P1)) == Absis(PosW(&W1)) && Ordinat(Pos(&P1)) == Ordinat(PosW(&W1))-1) {
        // Wahana berada di bawah player
        PrintDetail(W1);
    }
    else if (Absis(Pos(&P1)) == Absis(PosW(&W1))-1 && Ordinat(Pos(&P1))== Ordinat(PosW(&W1))) {
        // Wahana berada di kanan player
        PrintDetail(W1);
    }
    else if (Absis(Pos(&P1)) == Absis(PosW(&W1))+1 && Ordinat(Pos(&P1))== Ordinat(PosW(&W1))) {
        // Wahana berada di kiri player
        PrintDetail(W1);
    }
}

void Serve(int * ID){
    /*Serve sehingga dequeue*/
    Wahana W;
    IDW(&W) = ID;
    DequeueQ(&Q1,X);
    if(IsEmptyQ(Q1)){
        DequeuePrio(&PQ1, X);
    }
    AddWaktu(&P1,10);
}

void Prepare(){
    Hour(P1.wkt) = 21;
    Minute(P1.wkt) = 0;
    MakeEmptyPrio(&PQ1, 5);
    Preparation(P1);
}

void Repair(Wahana *W, PrioQ * PQ1){
    Rusak(W) = false;
    PrioQ(HeadPrio(*PQ1)) -= 1;
    
}

void Office () {
    

}








void Antrian(PrioQ PQ1){
    Queue QAntrian;
    int panjang_antrian = (rand()%5);
    CreateEmptyQ(&QAntrian);
    for (int i = 0; i<panjang_antrian; i++){
        /*Inisialisasi ID Wahana kita*/
        EnqueueQ(&QAntrian,(rand()%10));
    }
    EnqueuePrio(&PQ1,QAntrian);
}