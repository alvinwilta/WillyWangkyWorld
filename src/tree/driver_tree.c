#include <stdio.h>
#include "listrek.h"
#include "bintree.h"

int main() {
	printf("Driver ADT Tree\n");
	// listrek
	List L,L1;
	infotypeString X = "Pertama";
	printf("string : %s\n", X);
	L = AlokasiListrek(X);
	PrintList(L);
	
	int check, check1;
	L1 = Nil;
	check = IsListrekEmpty(L);
	check1 = IsListrekEmpty(L1);
	printf("check : %d %d\n", check, check1);

	// KonsB
	L = KonsB(L, "Kedua");
	L = Konso("Ke-0", L);
	PrintList(L);

	/*Driver bintree*/
	printf("\n\n---Driver ADT Biner tree---\n");
	X = "akar";
	BinTree T = AlokNode(X);
	if (IsTreeEmpty(T))
		printf("Tree T Empty\n");
	else
		printf("Tree T tidak Empty\n");
	
	printf("---\nPredikat penting Biner tree---\n");
	BinTree Left, R, root;
	X = "Anak kiri";	Left = AlokNode(X);
	X = "Anak kanan";	R = AlokNode(X);
	root = Tree("akar", Left, R);
	printf("Pengecekan apakah bintree L adalah pohon biner (Benar)\n");
	if (IsBiner(root))
		printf("Pohon root adalah biner\n");
	else
		printf("Pohon root tidak biner\n");
	PrintTree(root, 1);
	
	
	printf("---\nOperasi lain---\n");
	// Menambahkan daun
	printf("Penambahan daun kiri pada bintree (elemen baru = 3)\n");
	AddDaun(&root, "Anak kiri", "Anak kiri ke-2", true);
	PrintTree(root, 1);

	printf("---\nFungsi lain---\n");
	int nb = NbElmt(root);
	int tinggi = Tinggi(root);
	printf("NBelemen : %d\nTinggi pohon : %d\n", nb, tinggi);
	
	
	return 0;
}