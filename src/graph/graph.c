#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "graph.h"


void CreateEmptyGraph(Graph *G);
/* I.S. sembarang */
/* F.S. Terbentuk graph kosong */

boolean IsGraphEmpty(Graph G);
/* Mengirimkan true jika graph kosong */

addressNode AlokasiNode(MATRIKS X);
/* Mengirimkan addressNode hasil alokasi sebuah matriks */
/* Jika alokasi berhasil, maka addressNode tidak NULL, dan misalnya */
/* menghasilkan P, maka MatriksGraph(P)=X, NextNode(P)=NULL, dan Trail(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */

void DealokasiNode(addressNode P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

addressSuccNode AlokasiSuccNode(ElmtGraph P);
/* Mengirimkan addressNode hasil alokasi sebuah matriks */
/* Jika alokasi berhasil, maka addressSuccNode tidak NULL, dan misalnya */
/* menghasilkan Ps, maka Succ(Ps)=P, NextSucc(Ps)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */

void DealokasiSuccNode(addressSuccNode Ps);
/* I.S. Ps terdefinisi */
/* F.S. Ps dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address Ps */

void addElmtGraph(Graph *G, MATRIKS X);
/* I.S. Graph terdefinisi, ElmtGraph tidak mungkin kosong */
/* F.S. Menambahkan elemen graph berisi matriks X */

void addPanahGraph(Graph *G, ElmtGraph A, ElmtGraph B);
/* I.S. Graph A dan B mungkin sudah ada koneksi, ElmtGraph A dan B tidak mungkin kosong */
/* F.S. Terbentuk panah dari node A ke B */