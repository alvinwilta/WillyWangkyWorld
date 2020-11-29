/* File: graph.h */
/* ADT graph dengan representasi multilist */

#ifndef GRAPH_H
#define GRAPH_H

#include "../boolean.h"
#include "../linkedlist/listlinier.h"
#include "../matriks/matriks.h"
#include "../point/point.h"

#define Nil NULL

typedef struct adrNode *addressNode;
typedef struct succNode *addressSuccNode;
typedef struct adrNode {
	int id;
	MATRIKS info;
	addressNode next;
	addressSuccNode trail;
} ElmtGraph;
typedef struct succNode {
	addressSuccNode nexts;
	addressNode succ;
} ElmtSucc;
typedef struct {
	addressNode First;
} Graph;

// P adalah pointer node
// Ps adalah pointer trail

#define ID(P) (P)->id
#define MatriksGraph(P) (P)->info
#define NextNode(P) (P)->next
#define Trail(P) 	 (P)->trail
#define NextSucc(Ps) (Ps)->nexts
#define Succ(Ps) (Ps)->succ
#define FirstGraph(G) ((G).First)

void CreateEmptyGraph(Graph *G);
/* I.S. sembarang */
/* F.S. Terbentuk graph kosong */

boolean IsGraphEmpty(Graph G);
/* Mengirimkan true jika graph kosong */

addressNode AlokasiNode(MATRIKS X, int Id);
/* Mengirimkan addressNode hasil alokasi sebuah matriks */
/* Jika alokasi berhasil, maka addressNode tidak NULL, dan misalnya */
/* menghasilkan P, maka MatriksGraph(P)=X, NextNode(P)=NULL, dan Trail(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */

void DealokasiGraph(addressNode *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

addressSuccNode AlokasiSuccNode(addressNode P);
/* Mengirimkan addressNode hasil alokasi sebuah matriks */
/* Jika alokasi berhasil, maka addressSuccNode tidak NULL, dan misalnya */
/* menghasilkan Ps, maka Succ(Ps)=P, NextSucc(Ps)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */

addressNode searchNodeId(Graph *G, int Id);
/* I.S. Graf dan Id terdefinisi, Id pasti terdapat pada graf */
/* F.S. Mengeluarkan addressNode yang mengandung Id terkait */

void addElmtGraph(Graph *G, MATRIKS X, int Id);
/* I.S. Graph terdefinisi, ElmtGraph tidak mungkin kosong */
/* F.S. Menambahkan elemen graph berisi matriks X */

void addPanahGraph(Graph *G, int A, int B);
/* I.S. Graph A dan B mungkin sudah ada koneksi, ElmtGraph A dan B tidak mungkin kosong */
/* F.S. Terbentuk panah dari node A ke B */

Graph initGraphMap(Graph *G, MATRIKS A, MATRIKS B, MATRIKS C, MATRIKS D);
/* I.S. semua matriks terdefinisi, matriks tidak mungkin kosong, digunakan untuk init graph */
/* F.S. Terbentuk graf fungsional yang dapat dipakai dalam peta */

POINT lokasiPlayer(Graph *G, int A, int B);
/* menunjukkan lokasi player setelah berpindah dari area ID A ke area ID B*/

addressNode moveGraph(Graph *G, addressNode CurrNode, int Gerbang);
/* Mengeluarkan address graph berikutnya setelah memasuki gerbang dengan nomor gerbang (di matriks) */
/* CurrNode dibutuhkan agar mengetahui kemana player akan pergi setelah memasuki gerbang */
/* kalau ID(CurrNode)=1 dan Gerbang=3, maka akan mengeluarkan address graph dengan ID=2 */
/* kalau ID(CurrNode)=4 dan Gerbang=3, maka akan mengeluarkan address graph dengan ID=3 */

#endif