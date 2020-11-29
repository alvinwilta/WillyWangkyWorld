/*Nama: Leonard Matheus
NIM: 13519215
Topik: Praktikum 9
Deskripsi: linked list
*/

#include "listlinier.h"
#include "../boolean.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsListEmpty (LinkedList L){
    return(First(L) == NilLin);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (LinkedList *L){
    First(*L) = NilLin;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressList AlokasiList (infotypeList X){
    linElmtList *P = (linElmtList *) malloc(sizeof(linElmtList));
    if (P != NilLin){
        Info(P) = X;
        Next(P) = NilLin;
        return P;
    }
    else {
        return NilLin;
    }
}
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList tidak NilLin, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=NilLin */
/* Jika alokasi gagal, mengirimkan NilLin */
void DealokasiList (addressList *P){
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressList P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressList SearchList (LinkedList L, infotypeList X){
    boolean found = false;
    addressList cpointer = First(L); //current pointer
    addressList fpointer = NilLin; //alokasi pointer untuk adress
    if(!IsListEmpty(L)){
        while ((cpointer != NilLin) && (!found)){
            if (Info(cpointer) == X){
                fpointer = cpointer;
                found = true;
            }else{
                cpointer = Next(cpointer);
            }
        }
    }
    return fpointer;
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan addressList elemen tersebut. */
/* Jika tidak ada, mengirimkan NilLin */

/****************** PRIMITIF BERDASARKAN NilLinAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (LinkedList *L, infotypeList X){
    addressList P = AlokasiList(X);
    if (P != NilLin){
        InsertFirst(L, P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan NilLinai X jika alokasi berhasil */
void InsVLast (LinkedList *L, infotypeList X){
    addressList P = AlokasiList(X);
    if (P != NilLin){
        InsertLast(L, P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNilLinai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (LinkedList *L, infotypeList *X){
    addressList P;
    DelFirst(L, &P);
    *X = Info(P);
    DealokasiList(&P);
}
/* I.S. LinkedList L tidak kosong  */
/* F.S. Elemen pertama list dihapus: NilLinai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (LinkedList *L, infotypeList *X){
    addressList P;
    DelLast(L, &P);
    *X = Info(P);
    DealokasiList(&P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: NilLinai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (LinkedList *L, addressList P){
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressList P sebagai elemen pertama */
void InsertAfter (LinkedList *L, addressList P, addressList Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (LinkedList *L, addressList P){
    if (IsListEmpty(*L)){
        Next(P) = NilLin;
        First(*L) = P;
    }
    else{
        addressList last = First(*L);
        while(Next(last) != NilLin) {
            last = Next(last);
        }
        InsertAfter(L, P, last);
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (LinkedList *L, addressList *P){
    *P = First(*L);
    if (Next(First(*L)) == NilLin){
        CreateEmptyList(L);
    }
    else{
        First(*L) = Next(First(*L));
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (LinkedList *L, infotypeList X){
    addressList P = SearchList(*L, X);
    if (P != NilLin){
        addressList prec = First(*L);
        if (prec == P){
            DelFirst(L, &P);
        }else{
            while(Next(prec) != P){
                prec = Next(prec);
            }
            DelAfter(L, &P, prec);
        }
    }
    DealokasiList(&P);
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info berNilLinai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (LinkedList *L, addressList *P){
    if (Next(First(*L)) == NilLin){
        *P = First(*L);
        CreateEmptyList(L);
    }
    else {
        addressList prec = First(*L);
        while(Next(Next(prec)) != NilLin){
            prec = Next(prec);
        }
        DelAfter(L, P, prec);
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (LinkedList *L, addressList *Pdel, addressList Prec){
    *Pdel = Next(Prec);
    if (*Pdel != NilLin){
        Next(Prec) = Next(Next(Prec));
    }
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/

void PrintInfo (LinkedList L){
    printf("[");
    if (!IsListEmpty(L)){
        addressList cpointer = First(L);
        while (cpointer != NilLin){
            printf("%d",Info(cpointer));
            cpointer = Next(cpointer);
            if (cpointer != NilLin){
                printf(",");
            }
        }
    }
    printf("]");
}

/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNilLinai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmtLinkedList (LinkedList L){
    int Count = 0;
    addressList cpointer = First(L);
    while(cpointer != NilLin){
        cpointer = Next(cpointer);
        Count++;
    }
    return Count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Min: List tidak kosong ***/

infotypeList Min (LinkedList L){
    addressList Min = First(L);
    addressList cpointer = First(L);
    while(cpointer != NilLin){
        if (Info(cpointer) < Info(Min)){
            Min = cpointer;
        }
        cpointer = Next(cpointer);
    }
    return Info(Min);
}
/* Mengirimkan NilLinai Info(P) yang minimum */

/*** Prekondisi untuk Max: List tidak kosong ***/

infotypeList Max (LinkedList L){
    addressList Max = First(L);
    addressList cpointer = First(L);
    while(cpointer != NilLin){
        if (Info(cpointer) > Info(Max)){
            Max = cpointer;
        }
        cpointer = Next(cpointer);
    }
    return Info(Max);
}
/* Mengirimkan NilLinai Info(P) yang maksimum */

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (LinkedList *L1, LinkedList *L2, LinkedList *L3){
    CreateEmptyList(L3);
    if (!(IsListEmpty(*L1))){
        First(*L3) = First(*L1);
        addressList last1 = First(*L1);
        while(Next(last1) != NilLin) {
            last1 = Next(last1);
        }
        Next(last1) = First(*L2);
    }
    else{
        First(*L3) = First(*L2);
    }
    CreateEmptyList(L1);
    CreateEmptyList(L2);
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen LinkedList L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */