#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "graph.h"


void CreateEmptyGraph(Graph *G) {
    FirstGraph(*G) = Nil;
}
/* I.S. sembarang */
/* F.S. Terbentuk graph kosong */

boolean IsGraphEmpty(Graph G) {
    return (FirstGraph(G)==Nil);
}
/* Mengirimkan true jika graph kosong */

addressNode AlokasiNode(MATRIKS X, int Id) {
    ElmtGraph *P = (ElmtGraph *) malloc(sizeof(ElmtGraph));
    if (P != Nil){
        ID(P) = Id;
        MatriksGraph(P) = X;
        NextNode(P) = Nil;
        Trail(P) = Nil;
        return P;
    }
    else {
        return Nil;
    }
}
/* Mengirimkan addressNode hasil alokasi sebuah matriks */
/* Jika alokasi berhasil, maka addressNode tidak NULL, dan misalnya */
/* menghasilkan P, maka MatriksGraph(P)=X, NextNode(P)=NULL, dan Trail(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */

void DealokasiGraph(addressNode *P) {
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

addressSuccNode AlokasiSuccNode(addressNode P) {
    ElmtSucc *Ps = (ElmtSucc *) malloc(sizeof(ElmtSucc));
    if (Ps != Nil) {
        NextSucc(Ps) = Nil;
        Succ(Ps) = P;
        return Ps;
    }
    else {
        return Nil;
    }
}
/* Mengirimkan addressNode hasil alokasi sebuah matriks */
/* Jika alokasi berhasil, maka addressSuccNode tidak NULL, dan misalnya */
/* menghasilkan Ps, maka Succ(Ps)=P, NextSucc(Ps)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */

void addElmtGraph(Graph *G, MATRIKS X, int Id) {
    addressNode Pn = AlokasiNode(X, Id);
    if (FirstGraph(*G) = Nil) {
        FirstGraph(*G) = Pn;
    } else {
        addressNode P = FirstGraph(*G);
        while (NextNode(P) != Nil) {
            P = NextNode(P);
        }
        NextNode(P) = Pn;
    }
}
/* I.S. Graph terdefinisi, ElmtGraph tidak mungkin kosong */
/* F.S. Menambahkan elemen graph berisi matriks X */

addressNode SearchNodeId(Graph *G, int Id) {
    addressNode P = First(*G);
    while ((ID(P)!=Id) && (P!=Nil)) {
        P = NextNode(P);
    }
    return P;
}
/* I.S. Graf dan Id terdefinisi, Id pasti terdapat pada graf */
/* F.S. Mengeluarkan addressNode yang mengandung Id terkait */

void addPanahGraph(Graph *G, int A, int B) {
    addressNode Pa = SearchNodeId(G,A);
    addressNode Pb = SearchNodeId(G,B);
    addressSuccNode Ps = Trail(Pa);
    boolean dupl = false;
    while ((NextSucc(Ps)!=Nil) && (dupl==false)) {
        if (Succ(Ps)==Pb) {
            dupl = true;
        }
        Ps = NextSucc(Ps);
    }
    if (dupl==false) {
        Succ(Ps) = Pb;
    }
}
/* I.S. Graph A dan B mungkin sudah ada koneksi, ElmtGraph A dan B tidak mungkin kosong */
/* F.S. Terbentuk panah dari node A ke B */

Graph initGraphMap(MATRIKS A, MATRIKS B, MATRIKS C, MATRIKS D) {
    Graph G;
    CreateEmptyGraph(&G);
    

}
/* I.S. semua matriks terdefinisi, matriks tidak mungkin kosong, digunakan untuk init graph */
/* F.S. Terbentuk graf fungsional yang dapat dipakai dalam peta */

POINT lokasiPlayer(Graph *G, int A, int B);
/* menunjukkan lokasi player setelah berpindah dari area ID A ke area ID B*/

MATRIKS lokasiMatriks(Graph *G, addressNode P);
/* mengeluarkan matriks terkait dari sebuah node graph */

addressNode moveGraph(Graph *G, addressNode CurrNode, int Gerbang);
/* Mengeluarkan address graph berikutnya setelah memasuki gerbang dengan nomor gerbang (di matriks) */
/* CurrNode dibutuhkan agar mengetahui kemana player akan pergi setelah memasuki gerbang */
/* kalau ID(CurrNode)=1 dan Gerbang=3, maka akan mengeluarkan address graph dengan ID=2 */
/* kalau ID(CurrNode)=4 dan Gerbang=3, maka akan mengeluarkan address graph dengan ID=3 */
