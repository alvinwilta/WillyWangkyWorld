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
boolean IsEmpty (List L){
    return(First(L) == Nil);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressList Alokasi (infotypeList X){
    ElmtList *P = (ElmtList *) malloc(sizeof(ElmtList));
    if (P != Nil){
        Info(P) = X;
        Next(P) = Nil;
        return P;
    }
    else {
        return Nil;
    }
}
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (addressList *P){
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressList P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressList Search (List L, infotypeList X){
    boolean found = false;
    addressList cpointer = First(L); //current pointer
    addressList fpointer = Nil; //alokasi pointer untuk adress
    if(!IsEmpty(L)){
        while ((cpointer != Nil) && (!found)){
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
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotypeList X){
    addressList P = Alokasi(X);
    if (P != Nil){
        InsertFirst(L, P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotypeList X){
    addressList P = Alokasi(X);
    if (P != Nil){
        InsertLast(L, P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotypeList *X){
    addressList P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotypeList *X){
    addressList P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, addressList P){
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressList P sebagai elemen pertama */
void InsertAfter (List *L, addressList P, addressList Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, addressList P){
    if (IsEmpty(*L)){
        Next(P) = Nil;
        First(*L) = P;
    }
    else{
        addressList last = First(*L);
        while(Next(last) != Nil) {
            last = Next(last);
        }
        InsertAfter(L, P, last);
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, addressList *P){
    *P = First(*L);
    if (Next(First(*L)) == Nil){
        CreateEmpty(L);
    }
    else{
        First(*L) = Next(First(*L));
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, infotypeList X){
    addressList P = Search(*L, X);
    if (P != Nil){
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
    Dealokasi(&P);
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, addressList *P){
    if (Next(First(*L)) == Nil){
        *P = First(*L);
        CreateEmpty(L);
    }
    else {
        addressList prec = First(*L);
        while(Next(Next(prec)) != Nil){
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
void DelAfter (List *L, addressList *Pdel, addressList Prec){
    *Pdel = Next(Prec);
    if (*Pdel != Nil){
        Next(Prec) = Next(Next(Prec));
    }
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
    printf("[");
    if (!IsEmpty(L)){
        addressList cpointer = First(L);
        while (cpointer != Nil){
            printf("%d",Info(cpointer));
            cpointer = Next(cpointer);
            if (cpointer != Nil){
                printf(",");
            }
        }
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L){
    int Count = 0;
    addressList cpointer = First(L);
    while(cpointer != Nil){
        cpointer = Next(cpointer);
        Count++;
    }
    return Count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Min: List tidak kosong ***/
infotypeList Min (List L){
    addressList Min = First(L);
    addressList cpointer = First(L);
    while(cpointer != Nil){
        if (Info(cpointer) < Info(Min)){
            Min = cpointer;
        }
        cpointer = Next(cpointer);
    }
    return Info(Min);
}
/* Mengirimkan nilai Info(P) yang minimum */

/*** Prekondisi untuk Max: List tidak kosong ***/
infotypeList Max (List L){
    addressList Max = First(L);
    addressList cpointer = First(L);
    while(cpointer != Nil){
        if (Info(cpointer) > Info(Max)){
            Max = cpointer;
        }
        cpointer = Next(cpointer);
    }
    return Info(Max);
}
/* Mengirimkan nilai Info(P) yang maksimum */

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3){
    CreateEmpty(L3);
    if (!(IsEmpty(*L1))){
        First(*L3) = First(*L1);
        addressList last1 = First(*L1);
        while(Next(last1) != Nil) {
            last1 = Next(last1);
        }
        Next(last1) = First(*L2);
    }
    else{
        First(*L3) = First(*L2);
    }
    CreateEmpty(L1);
    CreateEmpty(L2);
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */