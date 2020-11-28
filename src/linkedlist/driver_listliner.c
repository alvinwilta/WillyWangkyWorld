#include <stdio.h>
#include "listlinier.h"
#include "../boolean.h"

int main() {
	printf("---Driver List Linier---\n");
	List L;

	printf("Pembuatan List kosong\n");
	CreateEmptyList(&L);
	printf("Test list kosong\n");
	printf("F.S L adalah list Kosong\n");
	if (IsListEmpty(L))
		printf("L Empty");
	else
		printf("L not Empty");

	printf("\n---manajemen memory---\n");
	// Alokasi adress P dengan nilai 1 dan menjadikan P sebagai elemen pertama List L
	int x = 1;
	addressList P = AlokasiList(x);
	printf("\n---Primitif berdasarkan alamat---\n");
	printf("Menambahkan elemen ber address P sebagai elemen pertama L (1)\n");
	InsertFirst(&L, P);
	printf("L = ");  PrintInfo(L); printf("\n");
	

	printf("\n---Primitif berdasarkan nilai---\n");
	printf("Menambahkan 0 sebagai elemen pertama dan 2 sebagai elemen terkahir List\n");
	InsVFirst(&L, 0);
	InsVLast(&L, 2);
	printf("L = ");  PrintInfo(L); printf("\n");
	printf("Menghapus elemen pertama dan elemen terkahir sebuah List\n");
	int x1, x2;
	DelVFirst(&L, &x1);
	DelVLast(&L, &x2);
	printf("Elemen pertama : %d\nElemen terakhir : %d\n", x1, x2);

	printf("Membuat sebuah List baru L1=[10,11,12]\n");
	List L1; CreateEmptyList(&L1);
	InsVFirst(&L1, 10);
	InsVLast(&L1, 11);
	InsVLast(&L1, 12);
	printf("L1 = ");  PrintInfo(L1); printf("\n");

	printf("\n---Proses terhadap List---\n");
	printf("Konkat antara list L dengan L1\n");
	printf("L = "); PrintInfo(L); printf("\n");
	printf("L1 = "); PrintInfo(L1); printf("\n");
	List L2;
	Konkat1(&L, &L1, &L2);
	printf("hasil konkat [1,10,11,12] = "); PrintInfo(L2); printf("\n");
	printf("\n---Proses terhadap elemen dalam list---\n");
	printf("Menampilkan jumlah elemen (4), nilai max (12), nilai min (1) dalam List L2\n");
	printf("Banyak elemen L2 = %d\nNilai max = %d\nNilai Min = %d\n", NbElmt(L2), Max(L2), Min(L2));

	return 0;
}