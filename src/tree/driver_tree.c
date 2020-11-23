#include <stdio.h>
#include "listrek.h"
#include "bintree.h"

int main() {
	printf("Driver ADT Tree\n");
	// listrek
	List L,L1;
	infotypeString X = "Pertama";
	printf("string : %s\n", X);
	L = Alokasi(X);
	PrintList(L);
	
	int check, check1;
	L1 = Nil;
	check = IsEmpty(L);
	check1 = IsEmpty(L1);
	printf("check : %d %d\n", check, check1);

	// KonsB
	L = KonsB(L, "Kedua");
	L = Konso("Ke-0", L);
	PrintList(L);

	return 0;
}