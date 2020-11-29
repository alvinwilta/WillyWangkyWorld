#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mainphase.h"

extern MATRIKS M;
extern Player P1;
extern Stack S1;
extern int menu1;
extern char name[20];
extern POINT PosPlayer;
extern int Money;
extern int currDay;
extern int X;
extern Queue Q1;
extern PrioQ PQ1;
extern Wahana ListWahana[20];
//Wahana W1;
POINT PosOffice;

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
    printf("%s",name);
    printf("Money: ");
    printf("%d\n", Money(&P1));
    printf("Current Time: ");
    printf("%02d", Hour(Wkt(&P1)));
    printf(".%02d\n", Minute(Wkt(&P1)));
    printf("\nOpening Time: 09.00\n");
    printf("Time Remaining: 12 hour(s)\n");
    printf("Antrian [");
    printf("%d", NBElmtPrio(PQ1));
    printf("/5]\n");
    PrintPrioQueue(PQ1);
    printf("\n");
}

void PrintDetail(Wahana ListWahana[], int i)
{
    printf("Nama : %s \n", JenisW(&ListWahana[i]));
    printf("Lokasi : (%d,%d) \n", Absis(PosW(&ListWahana[i])), Ordinat(PosW(&ListWahana[i])));
    printf("Deskripsi : %s \n", DeskripsiW(&ListWahana[i]));
    printf("Harga : %d \n", TarifW(&ListWahana[i]));
    printf("Kapasitas : %d \n", KapasitasW(&ListWahana[i]));
    printf("Upgrade(s) : "); PrintList(HistoryW(&ListWahana[i])); printf("\n");
    printf("Durasi : %d \n", DurasiW(&ListWahana[i]));
    if (Rusak(&ListWahana[i]))
        printf("Status : Rusak \n");
    else
        printf("Status : Berfungsi \n");
}

void PrintOffice(Wahana ListWahana[], int i)
{
    printf("Nama : %s \n", JenisW(&ListWahana[i]));
    printf("Lokasi : (%d,%d) \n", Absis(PosW(&ListWahana[i])), Ordinat(PosW(&ListWahana[i])));
    printf("Deskripsi : %s \n", DeskripsiW(&ListWahana[i]));
    printf("Harga : %d \n", TarifW(&ListWahana[i]));
    printf("Kapasitas : %d \n", KapasitasW(&ListWahana[i]));
    printf("Upgrade(s) : "); PrintList(HistoryW(&ListWahana[i])); printf("\n");
    printf("Durasi : %d \n", DurasiW(&ListWahana[i]));
    if (Rusak(&ListWahana[i]))
        printf("Status : Rusak \n");
    else
        printf("Status : Berfungsi \n");
    
    printf("Berapa kali wahana dinaiki : %d \n", TotalPenggunaan(&ListWahana[i]));
    printf("Total penghasilan wahana : %d \n", TotalPendapatan(&ListWahana[i]));
    printf("Berapa kali wahana dinaiki hari ini : %d \n", CurrentPenggunaan(&ListWahana[i]));
    printf("Total penghasilan wahana dinaiki hari ini : %d \n", CurrentPendapatan(&ListWahana[i]));
}

void Detail(Player P1, Wahana W[])
{
    int i=0;
    while (i<sizeof (W)/sizeof (W[0])){
        if (Absis(Pos(&P1)) == Absis(PosW(&W[i])) && Ordinat(Pos(&P1)) == Ordinat(PosW(&W[i])) + 1)
        {
            // Wahana berada di atas player
            PrintDetail(W, i);
        }
        else if (Absis(Pos(&P1)) == Absis(PosW(&W[i])) && Ordinat(Pos(&P1)) == Ordinat(PosW(&W[i])) - 1)
        {
            // Wahana berada di bawah player
            PrintDetail(W, i);
        }
        else if (Absis(Pos(&P1)) == Absis(PosW(&W[i])) - 1 && Ordinat(Pos(&P1)) == Ordinat(PosW(&W[i])))
        {
            // Wahana berada di kanan player
            PrintDetail(W, i);
        }
        else if (Absis(Pos(&P1)) == Absis(PosW(&W[i])) + 1 && Ordinat(Pos(&P1)) == Ordinat(PosW(&W[i])))
        {
            // Wahana berada di kiri player
            PrintDetail(W, i);
        }
        i++;
    }
    
}

void Serve(int *ID)
{
    /*Serve sehingga dequeue
    Wahana W;
    IDW(&W) = ID;
    DequeueQ(&Q1, X);
    if (IsEmptyQ(Q1))
    {
        DequeuePrio(&PQ1, X);
    }
    AddWaktu(&P1, 10);*/
    return;
}

void Prepare()
{/*
    Hour(P1.wkt) = 21;
    Minute(P1.wkt) = 0;
    MakeEmptyPrio(&PQ1, 5);
    Preparation(P1, name, currDay, S1);*/
}

void Repair(Wahana *W, PrioQ *PQ1)
{/*
    Rusak(W) = false;
    PrioQ(HeadPrio(*PQ1)) -= 1;*/
}

void GameOver(){
    /*
    if(PrioQ(HeadPrio(*PQ1))==0){ 
        quit();
    }*/
}

void Office(Player P, Wahana ListWahana[])
{
    if (Ordinat(Pos(&P)) == Ordinat(PosOffice)){
        if (Absis(Pos(&P)) == Absis(PosOffice)) {
            int i=0;
            while (i<sizeof (ListWahana)/sizeof (ListWahana[0])){
                PrintOffice(ListWahana, i);
                i++;
            }
        //PosW(ListWahana[i])
        //JenisW(ListWahana[i])
        }
    }
    
}

void Antrian(PrioQ PQ1)
{
    /*
    Queue QAntrian;
    int panjang_antrian = (rand() % 5);
    CreateEmptyQ(&QAntrian);
    for (int i = 0; i < panjang_antrian; i++)
    {
        Inisialisasi ID Wahana kita
        EnqueueQ(&QAntrian, (rand() % 10));
    }
    EnqueuePrio(&PQ1, QAntrian);*/
    return;
}

void kePrepare(){
    if (Hour(P1.wkt)>21){
        Preparation(P1, name, currDay, S1);
    }
}




