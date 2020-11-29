#include "queue.h"
#include "../boolean.h"
#include <stdlib.h>
#include <stdio.h>

/* Prototype manajemen memori */
void AlokasiQ (addressQ *P, infotype X){
    *P =  (addressQ)malloc(sizeof(ElmtQueue));
    if (*P != Nil){
        Info(*P)=X;
        Next(*P)=Nil;
    }
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void DealokasiQ (addressQ  P){
    free(P);
}
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmptyQ (Queue Q){
    return ((Head(Q)==Nil) && (Tail(Q)==Nil));
}
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmtQ(Queue Q){
    addressQ cpointer=Head(Q);
    int cnt = 0;
    while(cpointer!=Nil){
        cpointer=Next(cpointer);
        cnt++;
    }
    return cnt;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmptyQ(Queue * Q){
    Head(*Q)=Nil;
    Tail(*Q)=Nil;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Enqueue/Dequeue ***/
void EnqueueQ (Queue * Q, infotype X){
    addressQ P;
    AlokasiQ (&P,X);
    if (P!=Nil){
        if (IsEmptyQ(*Q)){
            Head(*Q)=P;
            Tail(*Q)=P;
        }else{
            Next(Tail(*Q))=P;
            Tail(*Q)=P;
        }
    }
}
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
void DequeueQ(Queue * Q, infotype * X){
    addressQ P = Head(*Q);
    if (Next(Head(*Q))==Nil){
        CreateEmptyQ(Q);
    }else{
        Head(*Q)=Next(Head(*Q));
    }
    *X = Info(P);
    DealokasiQ(P);
}
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */