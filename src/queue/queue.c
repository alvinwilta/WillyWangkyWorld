#include "queue.h"
#include "../boolean.h"
#include <stdlib.h>
#include <stdio.h>

/* Prototype manajemen memori */
void AlokasiQ (addressQ *P, infotype X){
    *P =  (addressQ)malloc(sizeof(ElmtQueue));
    if (*P != NilQ){
        InfoQ(*P)=X;
        NextQ(*P)=NilQ;
    }
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        NextQ(P)=NilQ */
/*      P=NilQ jika alokasi gagal */
void DealokasiQ (addressQ  P){
    free(P);
}
/* I.S. P adalah hasil alokasi, P != NilQ */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmptyQ (Queue Q){
    return ((HeadQ(Q)==NilQ) && (TailQ(Q)==NilQ));
}
/* Mengirim true jika Q kosong: HEAD(Q)=NilQ and TAIL(Q)=NilQ */
int NbElmtQ(Queue Q){
    addressQ cpointer=HeadQ(Q);
    int cnt = 0;
    while(cpointer!=NilQ){
        cpointer=NextQ(cpointer);
        cnt++;
    }
    return cnt;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmptyQ(Queue * Q){
    HeadQ(*Q)=NilQ;
    TailQ(*Q)=NilQ;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Enqueue/Dequeue ***/
void EnqueueQ (Queue * Q, infotype X){
    addressQ P;
    AlokasiQ (&P,X);
    if (P!=NilQ){
        if (IsEmptyQ(*Q)){
            HeadQ(*Q)=P;
            TailQ(*Q)=P;
        }else{
            NextQ(TailQ(*Q))=P;
            TailQ(*Q)=P;
        }
    }
}
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
void DequeueQ(Queue * Q, infotype * X){
    addressQ P = HeadQ(*Q);
    if (NextQ(HeadQ(*Q))==NilQ){
        CreateEmptyQ(Q);
    }else{
        HeadQ(*Q)=NextQ(HeadQ(*Q));
    }
    *X = InfoQ(P);
    DealokasiQ(P);
}
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = NilQai elemen HEAD pd I.S., HEAD "mundur" */