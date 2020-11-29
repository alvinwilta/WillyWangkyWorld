#include <stdlib.h>
#include <stdio.h>
#include "../boolean.h"
#include "../point/point.h"
#include "../jam/jam.h"
#include "../array/array.h"
#include "../graph/graph.h"
#include "player.h"

/* *** Primitif-primitif yang harus direalisasikan *** */
Player NewPlayer(POINT pos, JAM wkt, int money)
{
    /* I.S. pos, wkt, money terdefinisi, material belum terdefinisi */
    /* F.S. Player terdefinisi dengan Pos(P), Wkt(P), Money(P), Mat(P) terdefinisi secara default */
    /* Proses : Membuat TabInt dengan ukuran 3 dan isi default, 
kemudian assign Pos(P), Wkt(P), Money(P) sesuai default valuenya */
    Player P;
    TabInt material;
    Absis(Pos(&P)) = DefPos;
    Ordinat(Pos(&P)) = DefPos;
    Hour(Wkt(&P)) = DefJamHH;
    Minute(Wkt(&P)) = DefJamMM;
    Money(&P) = DefMoney;

    Elmt(material, 0) = DefMat;
    Elmt(material, 1) = DefMat;
    Elmt(material, 2) = DefMat;
    for (int i = 3; i <= IdxMax; i++)
    {
        Elmt(material, i) = ValUndef;
    }
    Mat(&P) = material;

    return P;
}

/* ** CONTROLS ** */
void Maju(Player *P)
{
    /* I.S. P terdefinisi */
    /* F.S. absis bertambah 1 poin, mengubah matriks map */
    Ordinat(Pos(P)) -= 1;
}

void Mundur(Player *P)
{
    /* I.S. P terdefinisi */
    /* F.S. absis berkurang 1 poin, mengubah matriks map */
    Ordinat(Pos(P)) += 1;
}

void Kanan(Player *P)
{
    /* I.S. P terdefinisi */
    /* F.S. ordinat bertambah 1 poin, mengubah matriks map */
    Absis(Pos(P)) += 1;
}

void Kiri(Player *P)
{
    /* I.S. P terdefinisi */
    /* F.S. ordinat berkurang 1 poin, mengubah matriks map */
    // Absis(Pos(&P)) -= 1;
    Absis(Pos(P)) -= 1;
}

/* ** WAKTU ** */
void AddWaktu(Player *P, int MM)
{
    /* I.S. P, MM terdefinisi */
    /* F.S. Waktu bertambah sebanyak MM menit */
    int MMResult = (Minute(Wkt(P)) + MM) % 60;
    int HourAdded = (Minute(Wkt(P)) + MM) / 60;
    if (Minute(Wkt(P)) + MM >= 60)
    {
        Hour(Wkt(P)) += HourAdded;
        printf("%d \n", MMResult);
    }
    Minute(Wkt(P)) = MMResult;
}

/* ** UANG ** */
void AddUang(Player *P, ElType X)
{
    /* I.S. P, X terdefinisi */
    /* F.S. Jumlah uang bertambah sebanyak X */
    /* Proses: menambah uang sebanyak X */
    Money(P) += X;
}

void SubUang(Player *P, ElType X)
{
    /* I.S. P, X terdefinisi, jumlah uang cukup */
    /* F.S. Jumlah uang berkurangsebanyak X */
    /* Proses: mengurangi uang sebanyak X */
    Money(P) -= X;
}

boolean IsUangCukup(Player P, ElType X, int jenis)
{
    /* I.S. P, X terdefinisi */
    /* F.S. return true jika uang cukup false jika tidak, jenis adalah indeks */
    /* Proses: mengecek uang cukup */
    boolean cukup = false;
    switch (jenis)
    {
    case 0:
        if (Money(&P) - X * 10 >= 0)
        {
            cukup = true;
        }
        break;

    case 1:
        if (Money(&P) - X * 20 >= 0)
        {
            cukup = true;
        }
    case 2:
        if (Money(&P) - X * 30 >= 0)
        {
            cukup = true;
        }
    }
}
/* ** MATERIAL ** */
/* Untuk tambah kurang material, urutan sesuai indeksnya[0..2] adalah kayu, batu, kaca */
void AddKayu(Player *P, ElType X)
{
    /* I.S. P, X terdefinisi */
    /* F.S. Jumlah kayu bertambah sebanyak X (elemen indeks 0 tambah X) */
    /* Proses: mengecek uang cukup, jika cukup maka Elmt(P,0) ditambah X, uang dikurang*/
    if (IsUangCukup(*P, X, 0))
    {
        int total = X * 10;
        SubUang(P, total);
        Elmt(Mat(P), 0) += X;
    }
}

void AddBatu(Player *P, ElType X)
{
    /* I.S. P, X terdefinisi */
    /* F.S. Jumlah batu bertambah sebanyak X (elemen indeks 1 tambah X) */
    /* Proses: mengecek uang cukup, jika cukup maka Elmt(P,1) ditambah X, uang dikurang*/
    if (IsUangCukup(*P, X, 1))
    {
        int total = X * 20;
        SubUang(P, total);
        Elmt(Mat(P), 1) += X;
    }
}

void AddPaku(Player *P, ElType X)
{
    /* I.S. P, X terdefinisi */
    /* F.S. Jumlah paku bertambah sebanyak X (elemen indeks 2 tambah X) */
    /* Proses: mengecek uang cukup, jika cukup maka Elmt(P,2) ditambah X, uang dikurang*/
    if (IsUangCukup(*P, X, 2))
    {
        int total = X * 30;
        SubUang(P, total);
        Elmt(Mat(P), 2) += X;
    }
}

void SubKayu(Player *P, ElType X)
{
    /* I.S. P, X terdefinisi */
    /* F.S. Jumlah kayu berkurang sebanyak X (elemen indeks 0 kurang X) */
    /* Proses: mengecek material cukup, jika cukup maka Elmt(P,0) dikurang X, uang ditambah */
    if (Elmt(Mat(P), 0) - X >= 0)
    {
        int total = X * 10;
        AddUang(P, total);
        Elmt(Mat(P), 0) -= X;
    }
}

void SubBatu(Player *P, ElType X)
{
    /* I.S. P, X terdefinisi */
    /* F.S. Jumlah batu berkurang sebanyak X (elemen indeks 1 kurang X) */
    /* Proses: mengecek material cukup, jika cukup maka Elmt(P,1) dikurang X, uang ditambah */
    if (Elmt(Mat(P), 1) - X >= 0)
    {
        int total = X * 20;
        AddUang(P, total);
        Elmt(Mat(P), 1) -= X;
    }
}

void SubPaku(Player *P, ElType X)
{
    /* I.S. P, X terdefinisi */
    /* F.S. Jumlah paku berkurang sebanyak X (elemen indeks 2 tambah X) */
    /* Proses: mengecek material cukup, jika cukup maka Elmt(P,2) dikurang X, uang ditambah */
    if (Elmt(Mat(P), 2) - X >= 0)
    {
        int total = X * 30;
        Elmt(Mat(P), 2) -= X;
    }
}
