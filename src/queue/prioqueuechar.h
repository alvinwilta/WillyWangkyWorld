/* File : prioqueue.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut tidak mengecil berdasarkan elemen prio */

#ifndef prioqueuechar_H
#define prioqueuechar_H

#include "../boolean.h"
#include "../linkedlist/listlinier.h"

#define Nill -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
typedef struct {
    int prio;  /* [1..100], prioritas/kesabaran dengan nilai 1..5 (1 adalah prioritas tertinggi) */
    LinkedList infoPrio;  /* list wahana */
} InfotypeQ;
typedef int address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype PrioQueueChar : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct {
    InfotypeQ * T;   /* tabel penyimpan elemen */
    address HEADPrio;  /* alamat penghapusan */
    address TAILPrio;  /* alamat penambahan */
    int MaxEl;     /* Max elemen queue */
} PrioQ;
/* Definisi PrioQ kosong: HEAD=Nil; TAIL=Nil. */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah InfotypeQ dan Q adalah PrioQ, maka akses elemen : */
#define PrioQ(e)     (e).prio
#define InfoPrio(e)     (e).infoPrio
#define HeadPrio(Q)     (Q).HEADPrio
#define TailPrio(Q)     (Q).TAILPrio
#define InfoHead(Q) (Q).T[(Q).HEADPrio]
#define InfoTail(Q) (Q).T[(Q).TAILPrio]
#define MaxEl(Q)    (Q).MaxEl
#define ElmtPrio(Q,i)   (Q).T[(i)]

/* 
Untuk mengakses list pada Q urutan i:
    InfoQ(Elmt(Q,i)) 
Untuk mengakses list pada head Q:
    InfoHead(Q)
Untuk mengakses elemen pertama list pada head Q 
    gunakan selektor pada list linier
*/

/* Untuk mengakses */
/* ********* Prototype ********* */
boolean IsEmptyPrio (PrioQ Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullPrio (PrioQ Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmtPrio (PrioQ Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmptyPrio (PrioQ * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasiPrio (PrioQ * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void EnqueuePrio (PrioQ * Q, InfotypeQ X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
        
void DequeuePrio (PrioQ * Q, InfotypeQ * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueue (PrioQ Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<PrintList(InfoQ(Elmt(Q,1)))>, kesabaran:<prio-1>
...
<PrintList(InfoQ(Elmt(Q,n)))>, kesabaran:<prio-n>
#
*/

#endif