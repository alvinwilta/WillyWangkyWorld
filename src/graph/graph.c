#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "graph.h"


/* PERLU REVISI ULANG, DISESUAIKAN DENGAN ADT BARU */


void CreateEmptyGraph(Graph *G){
    /* KAMUS LOKAL */
    addressGraph P;

    /* ALGORITMA */
    FirstGraph(*G) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk graph kosong */

boolean IsGraphEmpty(Graph G){
    return (FirstGraph(G) == NULL);
}
/* Mengirimkan true jika graph kosong */

addressGraph AlokasiGraph(MATRIKS X){
    addressGraph P;

    P = (ElmtGraph *) malloc (sizeof(ElmtList));
    if (P != NULL) {
        InfoGraph(P) = X;
        NextGraph(P) = NULL;
        CreateEmptyList(&Link(P));
    }
    return P;
}
/* Mengirimkan addressGraph hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressGraph tidak nil, dan misalnya */
/* menghasilkan P, maka InfoGraph(P)=X, NextGraph(P)=NULL, dan Link(P) berisi list kosong */
/* Jika alokasi gagal, mengirimkan NULL */

void initGraph(Graph *G, int n){
    /* KAMUS LOKAL */
    addressGraph P;
    int i;

    /* ALGORITMA */
    CreateEmptyGraph(G);
    FirstGraph(*G) = AlokasiGraph(1);
    P = FirstGraph(*G);
    for (i = 2; i <= n; i++) {
        NextGraph(P) = AlokasiGraph(i);
        P = NextGraph(P);
    }
}
/* I. S. Graph G sembarang, n adalah jumlah building/ jumlah elemen parent list
   F. S. Terbentuk Graph n elemen dan link tiap elemen berupa empty list */

void PrintGraph(Graph G){
    /* KAMUS LOKAL */
    addressGraph P;

    /* ALGORITMA */
    P = FirstGraph(G);
    printf("[");
    while (NextGraph(P) != NULL) {
        printf("%d, ", InfoGraph(P));
        P = NextGraph(P);
    }
    printf("%d", InfoGraph(P));
    printf("]\n");
}
/* I.S. Graph mungkin kosong */
/* F.S. Jika Graph tidak kosong, isi info Graph dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Graph kosong : menulis [] */


boolean IsLinked(Graph G, List n, List p){
    /* KAMUS LOKAL */
    addressGraph addrGn;

    /* ALGORITMA */
    /* Proses menambahkan link elemen n dengan p */
    addrGn = FirstGraph(G);
    while (InfoGraph(addrGn) != n) {
        addrGn = NextGraph(addrGn);
    }

    if (Search(Link(addrGn), p) != NULL) {
        return true;
    } else {
        return false;
    }
}
/* Mengembalikan true jika pada link n ada p */

addressGraph SearchGraph(Graph G, MATRIKS X){
    /* KAMUS LOKAL */
    addressGraph addrG;

    /* ALGORITMA */
    addrG = FirstGraph(G);
    while ((InfoGraph(addrG) != X) && (addrG != NULL)) {
        addrG = NextGraph(addrG);
    }

    return addrG;
}