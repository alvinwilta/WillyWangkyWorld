/* File : queuelist.h */
/* Representasi queue dengan list berkait dengan first (HEAD) dan last (TAIL) */
#ifndef _QUEUE_H
#define _QUEUE_H
#include "../boolean.h"
#include <stdlib.h>

/* Konstanta */
#define NilQ NULL

/* Deklarasi infotype */
typedef int infotype;

/* Queue dengan representasi berkait dengan pointer */
typedef struct tElmtQueue * addressQ;
typedef struct tElmtQueue { 
	infotype InfoQ;
	addressQ NextQ; 
} ElmtQueue; 

/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct { 
	addressQ HEADQ;  /* alamat penghapusan */
	addressQ TAILQ;  /* alamat penambahan */
} Queue;

/* Selektor */
#define HeadQ(Q) (Q).HEADQ
#define TailQ(Q) (Q).TAILQ
#define InfoHeadQ(Q) (Q).HEAD->InfoQ
#define InfoTailQ(Q) (Q).TAIL->InfoQ
#define NextQ(P) (P)->NextQ
#define InfoQ(P) (P)->InfoQ

/* Prototype manajemen memori */
void AlokasiQ (addressQ *P, infotype X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void DealokasiQ (addressQ  P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmptyQ (Queue Q);
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmtQ(Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmptyQ(Queue * Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Enqueue/Dequeue ***/
void EnqueueQ (Queue * Q, infotype X);
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
void DequeueQ(Queue * Q, infotype * X);
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */

#endif