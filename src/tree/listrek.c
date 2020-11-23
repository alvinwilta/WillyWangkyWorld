#include <stdio.h>
#include <stdlib.h>
#include "listrek.h"
#include "../boolean.h"

address Alokasi(infotypeString X) {
	/* Mengirimkan address hasil alokasi sebuah elemen */
	/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P,
	  maka Info(P) = X, Next(P) = Nil */
	  /* Jika alokasi gagal, mengirimkan Nil */
	// Kamus Lokal
	address P;
	//Algoritma
	P = (address)malloc(sizeof(address));
	if (P != Nil) {
		Info(P) = X;
		Next(P) = Nil;
	}
	return P;
}

void Dealokasi(address P) {
	/* I.S. P terdefinisi */
	/* F.S. P dikembalikan ke sistem */
	/* Melakukan dealokasi/pengembalian address P */
	// Algoritma
	free(P);
}

int IsEmpty(List L) {
	/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
	return (L == Nil);
}
int IsOneElmt(List L) {
	/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */
	// Kamus Lokal
	int check;
	// Algoritma
	check = 0;
	if (!(IsEmpty(L))) {
		if (Next(L) == Nil) {
			check = 1;
		}
	}
	return check;
}

infotypeString FirstElmt(List L) {
	/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
	// Algoritma
	return (Info(L));
}
List Tail(List L) {
	/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */
	// Algoritma
	return (Next(L));
}

List Konso(infotypeString e, List L) {
	/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya.
	e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
	// Kamus Lokal
	address P;
	// Algoritma
	P = Alokasi(e);
	if (P == Nil) {
		return L;
	}
	else {
		Next(P) = L;
		return P;
	}
}
List KonsB(List L, infotypeString e) {
	/* Mengirimkan list L dengan tambahan e sebagai elemen terakhirnya */
	/* e harus dialokasi terlebih dahulu */
	/* Jika alokasi e gagal, mengirimkan L */
	// Kamus Lokal

	//Algoritma
	if (IsEmpty(L)) {
		return (Alokasi(e));
	}
	else {
		Next(L) = KonsB(Tail(L), e);
		return L;
	}
}

List Copy(List L) {
	/* Mengirimkan salinan list L (menjadi list baru) */
	/* Jika ada alokasi gagal, mengirimkan L */
	// Kamus Lokal

	// Algoritma
	if (IsEmpty(L)) {
		return Nil;
	}
	else {
		return (Konso(FirstElmt(L), Copy(Tail(L))));
	}
}

void MCopy(List Lin, List* Lout) {
	/* I.S. Lin terdefinisi */
	/* F.S. Lout berisi salinan dari Lin */
	/* Proses : menyalin Lin ke Lout */
	// Kamus Lokal
	/*
	List LTemp;
	// algoritma
	if (IsEmpty(Lin)) {
		Lout = Nil;
	}
	else {
		MCopy(Tail(Lin), LTemp);
		Lout = Konso(FirstElmt(Lin), LTemp);
	} */
	*Lout = Copy(Lin);
}

List Concat(List L1, List L2) {
	/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
	/* Jika ada alokasi gagal, menghasilkan Nil */
	/* Kamus Lokal */

	/* Algoritma */
	if (IsEmpty(L1)) { /* Basis - 0 */
		return Copy(L2);	
	}
	else { /* Rekurens */
		return Konso(FirstElmt(L1), Concat(Tail(L1), L2));
	}
}
void MConcat(List L1, List L2, List* LHsl) {
	/* I.S. L1, L2 terdefinisi */
	/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
	/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
	// Kamus Lokal
	/*
	List LTemp;
	// Algoritma
	if (IsEmpty(L1)) {
		*LHsl = Copy(L2);
	}
	else {
		MConcat(Tail(L1), L2, LTemp);
		*LHsl = Konso(FirstElmt(L1), LTemp);
	} */
	* LHsl = Concat(L1, L2);
}

void PrintList(List L) {
	/* I.S. L terdefinisi. */
	/* F.S. Setiap elemen list dicetak. */
	if (!(IsEmpty(L))) {
		printf("%s\n", FirstElmt(L));
		PrintList(Tail(L));
	}
}


int NbElmtList(List L) {
	/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
	// Kamus Lokal
	int count;
	// Algoritma
	count = 0;
	if (IsEmpty(L)) {
		count = 0;
	}
	else {
		count = count + 1 + NbElmtList(Tail(L));
	}
	return count;

}
boolean Search(List L, infotypeString X) {
	/* Mengirim true jika X adalah anggota list, false jika tidak */
	// Kamus Lokal

	// Algoritma
	if (IsEmpty(L)) {
		return false;
	}
	else {
		if (FirstElmt(L) == X) {
			return true;
		}
		else {
			return (Search(Tail(L), X));
		}
	}
}

List InverseList(List L) {
	/* Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
	Semua elemen list baru harus dialokasi */
	/* Jika alokasi gagal, hasilnya list kosong */
	if (IsEmpty(L))
		return Nil;
	else
	{
		return KonsB(InverseList(Tail(L)), FirstElmt(L));
	}
}

boolean IsAllExist(List L1, List L2) {
	/* Menghasilkan true jika semua elemen dalam L1 terdapat dalam L2 (tanpa
	memperhatikan urutan ataupun banyaknya elemen).
	Kedua list mungkin kosong. Jika L1 kosong, maka hasilnya false. */
	// Kamus Lokal
	// Algortima
	if (IsEmpty(L1))
		return false;
	else if (IsOneElmt(L1))
		return Search(L2, FirstElmt(L1));
	else
		return (Search(L2, FirstElmt(L1)) && IsAllExist(Tail(L1), (L2)));
}
