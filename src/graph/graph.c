#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "graph.h"
#include "../matriks/matriks.h"
#include "../point/point.h"


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
    if (FirstGraph(*G) ==  Nil) {
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

addressNode searchNodeId(Graph *G, int Id) {
    addressNode P = FirstGraph(*G);
    while ((ID(P)!=Id) && (P!=Nil)) {
        P = NextNode(P);
    }
    return P;
}
/* I.S. Graf dan Id terdefinisi, Id pasti terdapat pada graf */
/* F.S. Mengeluarkan addressNode yang mengandung Id terkait */

void addPanahGraph(Graph *G, int A, int B) {
    addressNode Pa = searchNodeId(G,A);
    addressNode Pb = searchNodeId(G,B);
    if (Trail(Pa) != Nil) {
        addressSuccNode Ps = Trail(Pa);
        boolean dupl = false;
        while ((NextSucc(Ps)!=Nil) && (dupl==false)) {
            if (Succ(Ps)==Pb) {
                dupl = true;
            }
            Ps = NextSucc(Ps);
        }
        if (dupl==false) {
            addressSuccNode Px = AlokasiSuccNode(Pb);
            NextSucc(Ps) = Px;
        }
    } else {
        addressSuccNode Px = AlokasiSuccNode(Pb);
        Trail(Pa) = Px;
    }
}
/* I.S. Graph A dan B mungkin sudah ada koneksi, ElmtGraph A dan B tidak mungkin kosong */
/* F.S. Terbentuk panah dari node A ke B */

Graph initGraphMap(Graph *G, MATRIKS A, MATRIKS B, MATRIKS C, MATRIKS D) {
    addElmtGraph(G,A,1);
    addElmtGraph(G,B,2);
    addElmtGraph(G,C,3);
    addElmtGraph(G,D,4);
    addPanahGraph(G,1,2);
    addPanahGraph(G,2,1);
    addPanahGraph(G,1,4);
    addPanahGraph(G,4,1);
    addPanahGraph(G,2,3);
    addPanahGraph(G,3,2);
    addPanahGraph(G,3,4);
    addPanahGraph(G,4,3);
}
/* I.S. semua matriks terdefinisi, matriks tidak mungkin kosong, digunakan untuk init graph */
/* F.S. Terbentuk graf fungsional yang dapat dipakai dalam peta */

POINT lokasiPlayer(Graph *G, int A, int B) {
    if (A==1) {
        if (B==2) {
            return MakePOINT(1,2);
        } else if (B==4) {
            return MakePOINT(9,1);
        }
    } else if (A==2) {
        if (B==1) {
            return MakePOINT(18,2);
        } else if (B==3) {
            return MakePOINT(12,1);
        }
    } else if (A==3) {
        if (B==2) {
            return MakePOINT(12,8);
        } else if (B==4) {
            return MakePOINT(18,5);
        }
    } else if (A==4) {
        if (B==1) {
            return MakePOINT(9,8);
        } else if (B==3) {
            return MakePOINT(1,5);
        }
    }
}
/* menunjukkan lokasi player setelah berpindah dari area ID A ke area ID B*/

addressNode moveGraph(Graph *G, int IdGraph, int Gerbang) {
    if (Gerbang==2) {
        if (IdGraph==3) {
            return searchNodeId(G,2);
        } else if (IdGraph==4) {
            return searchNodeId(G,1);
        }
    } else if (Gerbang==3) {
        if (IdGraph==1) {
            return searchNodeId(G,2);
        } else if (IdGraph==4) {
            return searchNodeId(G,3);
        }
    } else if (Gerbang==4) {
        if (IdGraph==1) {
            return searchNodeId(G,4);
        } else if (IdGraph==2) {
            return searchNodeId(G,3);
        }
    } else if (Gerbang==5) {
        if (IdGraph==2) {
            return searchNodeId(G,1);
        } else if (IdGraph==3) {
            return searchNodeId(G,4);
        }
    }
}
/* Mengeluarkan address graph berikutnya setelah memasuki gerbang dengan nomor gerbang (di matriks) */
/* CurrNode dibutuhkan agar mengetahui kemana player akan pergi setelah memasuki gerbang */
/* kalau ID(CurrNode)=1 dan Gerbang=3, maka akan mengeluarkan address graph dengan ID=2 */
/* kalau ID(CurrNode)=4 dan Gerbang=3, maka akan mengeluarkan address graph dengan ID=3 */
