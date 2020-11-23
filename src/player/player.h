/* File: listrek.h */
/* ADT list linier dengan representasi pointer */
/* Implementasi list linier secara rekursif */

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../boolean.h"
#include "../point/point.h"
#include "../jam/jam.h"
#include "../array/array.h"

/* Definisi Type */
typedef int ElType;
typedef struct
{
    POINT pos;
    JAM wkt;
    ElType money;
    TabInt material;
} Player;

/* Default value dari data Player */
#define DefPos 9     //untuk absis atau ordinat
#define DefJamHH 9   //jam awal main
#define DefJamMM 00  //menit awal main
#define DefMoney 100 //uang player baru
#define DefMat 5     //jumlah material awal (semua jenis)

/* Selektor */
#define Pos(P) (P)->pos
#define Wkt(P) (P)->wkt
#define Money(P) (P)->money
#define Mat(P) (P)->material

/* *** Manajemen Memori *** */

/* *** Primitif-primitif yang harus direalisasikan *** */
Player NewPlayer(POINT pos, JAM wkt, int money);
/* I.S. pos, wkt, money terdefinisi, material belum terdefinisi */
/* F.S. Player terdefinisi dengan Pos(P), Wkt(P), Money(P), Mat(P) terdefinisi secara default */
/* Proses : Membuat TabInt dengan ukuran 3 dan isi default, 
kemudian assign Pos(P), Wkt(P), Money(P) sesuai default valuenya */

/* ** CONTROLS ** */
void Maju(Player *P);
/* I.S. P terdefinisi */
/* F.S. absis bertambah 1 poin, mengubah matriks map */

void Mundur(Player *P);
/* I.S. P terdefinisi */
/* F.S. absis berkurang 1 poin, mengubah matriks map */

void Kanan(Player *P);
/* I.S. P terdefinisi */
/* F.S. ordinat bertambah 1 poin, mengubah matriks map */

void Kiri(Player *P);
/* I.S. P terdefinisi */
/* F.S. ordinat berkurang 1 poin, mengubah matriks map */

/* ** WAKTU ** */
void AddWaktu(Player *P, int MM);
/* I.S. P, MM terdefinisi */
/* F.S. Waktu bertambah sebanyak MM menit */

/* ** UANG ** */
void AddUang(Player *P, ElType X);
/* I.S. P, X terdefinisi */
/* F.S. Jumlah uang bertambah sebanyak X */
/* Proses: menambah uang sebanyak X */

void SubUang(Player *P, ElType X);
/* I.S. P, X terdefinisi, jumlah uang cukup */
/* F.S. Jumlah uang berkurangsebanyak X */
/* Proses: mengurangi uang sebanyak X */

boolean IsUangCukup(Player P, ElType X, int jenis);
/* I.S. P, X terdefinisi */
/* F.S. return true jika uang cukup false jika tidak, jenis adalah indeks */
/* Proses: mengecek uang cukup */

/* ** MATERIAL ** */
/* Untuk tambah kurang material, urutan sesuai indeksnya[0..2] adalah kayu, batu, kaca */
void AddKayu(Player *P, ElType X);
/* I.S. P, X terdefinisi */
/* F.S. Jumlah kayu bertambah sebanyak X (elemen indeks 0 tambah X) */
/* Proses: mengecek uang cukup, jika cukup maka Elmt(P,0) ditambah X, uang dikurang*/

void AddBatu(Player *P, ElType X);
/* I.S. P, X terdefinisi */
/* F.S. Jumlah batu bertambah sebanyak X (elemen indeks 1 tambah X) */
/* Proses: mengecek uang cukup, jika cukup maka Elmt(P,1) ditambah X, uang dikurang*/

void AddPaku(Player *P, ElType X);
/* I.S. P, X terdefinisi */
/* F.S. Jumlah paku bertambah sebanyak X (elemen indeks 2 tambah X) */
/* Proses: mengecek uang cukup, jika cukup maka Elmt(P,2) ditambah X, uang dikurang*/

void SubKayu(Player *P, ElType X);
/* I.S. P, X terdefinisi */
/* F.S. Jumlah kayu berkurang sebanyak X (elemen indeks 0 kurang X) */
/* Proses: mengecek material cukup, jika cukup maka Elmt(P,0) dikurang X, uang ditambah*/

void SubBatu(Player *P, ElType X);
/* I.S. P, X terdefinisi */
/* F.S. Jumlah batu berkurang sebanyak X (elemen indeks 1 kurang X) */
/* Proses: mengecek material cukup, jika cukup maka Elmt(P,1) dikurang X, uang ditambah*/

void SubPaku(Player *P, ElType X);
/* I.S. P, X terdefinisi */
/* F.S. Jumlah paku berkurang sebanyak X (elemen indeks 2 tambah X) */
/* Proses: mengecek material cukup, jika cukup maka Elmt(P,2) dikurang X, uang ditambah */

#endif