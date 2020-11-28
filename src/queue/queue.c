
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* ********* Prototype ********* */
boolean IsEmptyQueue (Queue Q){
    return ((Head(Q) == Nil) && (End(Q) == Nil)); 
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullQueue (Queue Q){
    return (NBElmtQueue(Q)==MaxEl(Q));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmtQueue (Queue Q){
    if (IsEmptyQueue(Q)) {
        return 0;
    } else if ((End(Q) >= Head(Q))) {
        return (End(Q) - Head(Q) + 1);
    } else {
        return (MaxEl(Q) - Head(Q) + 1 + End(Q));
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmptyQueue (Queue * Q, int Max){
    (*Q).T = (infotype *) malloc (Max * sizeof(infotype));
    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        End(*Q) = Nil;
    }else{
        MaxEl(*Q) = 0;
    }
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasiQueue(Queue * Q){
    MaxEl(*Q) = 0;
    End(*Q)=Nil;
    Head(*Q)=Nil;
    free((*Q).T); 
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void EnqueueQ (Queue * Q, infotype X){
    if (IsEmptyQueue(*Q)) {
        Head(*Q) = 0;
        End(*Q) = 0;
    } else if (End(*Q) == MaxEl(*Q)-1) {
        End(*Q) = 0;
    } else {
        End(*Q) += 1;
    }
    InfoEnd(*Q) = X;
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi End yang baru, End "maju" dengan mekanisme circular buffer */
void DequeueQ (Queue * Q, infotype * X){
   *X= InfoHead(*Q);
    if (NBElmtQueue(*Q) == 1) {
        Head(*Q) = Nil;
        End(*Q) = Nil;
    }else if (Head(*Q) == MaxEl(*Q)) {
        Head(*Q) = 1;
    }else{
        Head(*Q) ++;
    }
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */