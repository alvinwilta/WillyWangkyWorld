#include "../tree/bintree.h"
#include "../tree/listrek.h"
#include "../point/point.h"
#include <stdio.h>
#include <stdlib.h>
#include "wahana.h"

int main()
{
    POINT P;
    Absis(P) = 2;
    Ordinat(P) = 3;
    char s[30] = "Pokpok";
    Wahana W = NewWahana(s, 0001, P);
    printf("%s\n", JenisW(&W));
    printf("id: %d\n", IDW(&W));
    printf("<%d,%d>\n", Absis(PosW(&W)), Ordinat(PosW(&W)));
    // printf("%s: %s\n", NamaW(&W), DeskripsiW(&W));
    printf("Durasi: %d, Tarif: %d, Kapasitas: %d\n", DurasiW(&W), TarifW(&W), KapasitasW(&W));
    // upgrade(&W);
    // printf("Durasi: %d, Tarif: %d, Kapasitas: %d\n", DurasiW(&W), TarifW(&W), KapasitasW(&W));
    addPengunjung(&W);
    addPengunjung(&W);
    addPengunjung(&W);
    printf("Isi pengunjung: %d\n", IsiW(&W));
    printf("Is penuh? %d\n", isPenuh(W));
    addPengunjung(&W);
    printf("Isi pengunjung: %d\n", IsiW(&W));
    printf("Is penuh? %d\n", isPenuh(W));
    catatPermainan(&W);
    catatPermainan(&W);
    catatPermainan(&W);
    catatPermainan(&W);
    printf("Laporan\n");
    printf("Pendapatan total: %d, hari ini: %d\n", TotalPendapatan(&W), CurrentPendapatan(&W));
    printf("Penggunaan total: %d, hari ini: %d\n", TotalPenggunaan(&W), CurrentPenggunaan(&W));
    emptyLaporanHariIni(&W);
    printf("Laporan\n");
    printf("Pendapatan total: %d, hari ini: %d\n", TotalPendapatan(&W), CurrentPendapatan(&W));
    printf("Penggunaan total: %d, hari ini: %d\n", TotalPenggunaan(&W), CurrentPenggunaan(&W));
    return 0;
}