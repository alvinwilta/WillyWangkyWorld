/* File: graph.h */
/* ADT graph dengan representasi multilist */

#ifndef GRAPH_H
#define GRAPH_H

#include "../boolean.h"
#include "../linkedlist/listlinier.h"
#include "../matriks/matriks.h"


// Maksimum simpul dari graph = maks bangunan
#define N 600;

// Struktur data pake list of list jancok
typedef struct tElmtgraph *addressGraph;
typedef struct tElmtgraph {
	MATRIKS info;
	List link;
	addressGraph next;
} ElmtGraph;
typedef struct {
	addressGraph First;
} Graph;

/* Definisi graph :
   Graph kosong : First(L) = Nil
   Setiap elemen dengan addressGraph P dapat diacu Info(P), Next(P)
   Elemen terakhir graph : jika addressnya Last, maka NextGraph(Last)=Nil */

/*	Penggunaan pada tubes:
	Graph digunakan untuk menyimpan indeks dari building pada array of building.
	contoh = graph untuk jumlah building 4
	file config =
   			0 1 1 1
   			1 0 0 0
   			1 0 0 1
   			1 0 1 0
	graph yang terjadi
		1 2->3->4
		2 1
		3 1->4
		4 1->3
*/

#define InfoGraph(P) (P)->info
#define NextGraph(P) (P)->next
#define Link(P) 	 (P)->link
#define FirstGraph(G) ((G).First)

void CreateEmptyGraph(Graph *G);
/* I.S. sembarang             */
/* F.S. Terbentuk graph kosong */

boolean IsGraphEmpty(Graph G);
/* Mengirimkan true jika graph kosong */

ElmtGraph CreateElmt(MATRIKS X, List L);
/* I.S. Matriks X dan List L tidak kosong, L dan X merupakan link dan matriks bacaan dari file */
/* F.S. menghasilkan ElmtGraph dengan next=NULL */

addressGraph AlokasiGraph(ElmtGraph E);
/* Mengirimkan addressGraph hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressGraph tidak NULL, dan misalnya */
/* menghasilkan P, maka InfoGraph(P)=X, NextGraph(P)=NULL, dan Link(P) berisi list kosong */
/* Jika alokasi gagal, mengirimkan NULL */

void addElmtGraph(Graph *G, ElmtGraph E);
/* I.S. Graph terdefinisi, ElmtGraph tidak mungkin kosong */
/* F.S. Menambahkan elemen graph berupa E */

void initGraph(Graph *G, MATRIKS X1, MATRIKS X2, MATRIKS X3, MATRIKS X4, List L1, List L2, List L3, List L4);
/* I. S. Graph G sembarang, matriks X1-X4, serta list L1-L4 adalah matriks dan list hasil bacaan dari file
   F. S. Terbentuk Graph utuh yang siap dipakai dalam game */

boolean IsLinked(Graph G, List n, List p);
/* Mengembalikan true jika pada link n ada p */

//void PrintGraph(Graph G);
/* I.S. Graph mungkin kosong */
/* F.S. Jika Graph tidak kosong, isi info Graph dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Graph kosong : menulis [] */

#endif