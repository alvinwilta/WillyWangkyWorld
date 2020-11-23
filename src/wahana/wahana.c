#include "../tree/bintree.h"
#include "../tree/listrek.h"
#include "../point/point.h"
#include "../matriks/matriks.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wahana.h"

/* *** Konstruktor Wahana **** */
Wahana NewWahana(char jenis[], int id, POINT pos)
{
    /* I.S jenis, id, dan pos terdefinisi. ID bersifat unik yang diatur dalam fungsi Build. jenis sudah harus terdaftar di dalam wahana.txt */
    /* F.S Wahana baru terbentuk dengan pos di tempat player membuat wahana. pendapatan dan penggunaan diset default 0 */
    /* deskripsi diset sesuai dengan deskripsi di wahana.txt */
    Wahana W;
    if (!strcmp(jenis, "Big Wheel"))
    {
        strcpy(JenisW(&W), jenis);
        strcpy(DeskripsiW(&W), "This classic Ferris Wheel is a firm family favorite");
    }
    else if (!strcmp(jenis, "Teacups"))
    {
        strcpy(JenisW(&W), jenis);
        strcpy(DeskripsiW(&W), "A teacup party. Fits in a small area.");
    }
    else if (!strcmp(jenis, "Venetian Carousel"))
    {
        strcpy(JenisW(&W), jenis);
        strcpy(DeskripsiW(&W), "A traditional Victorian carousel brought back to life.");
    }
    else if (!strcmp(jenis, "Smoll Coaster"))
    {
        strcpy(JenisW(&W), jenis);
        strcpy(DeskripsiW(&W), "Standard coaster for everybody-almost everybody.");
    }
    IDW(&W) = id;
    PosW(&W) = pos;
    KapasitasW(&W) = DefKapasitas;
    TarifW(&W) = DefTarif;
    DurasiW(&W) = DefDurasi;
    address P = Alokasi(0);
    HistoryW(&W) = P;
    IsiW(&W) = 0;
    TotalPendapatan(&W) = 0;
    TotalPenggunaan(&W) = 0;
    CurrentPendapatan(&W) = 0;
    CurrentPenggunaan(&W) = 0;
    return W;
}

/* Load Data */

/* ** Detail Wahana ** */
void upgrade(Wahana *W, int pilihan, BinTree treeWahana)
{
    /* I.S wahana, treeWahana, dan pilihan terdefinisi, pilihan merupakan integer upgrade yang dipilih dari tree wahana, jika dipilih left = 0, right = 1 */
    /* F.S wahana memiliki atribut tarif dan kapasitas baru. nama wahana berubah sesuai pilihan. history_upgrade diupdate */
    /* Proses: Akan dicari node pada Bintree treeWahana yang sesuai dengan nama wahana sebelum diupgrade. Nama wahana akan diubah sesuai dengan pilihan. History upgrade wahana ditambahkan di akhir list */
    TarifW(W) += 50;
    KapasitasW(W) += 2;
    // belum selesai
}

boolean isPenuh(Wahana W)
{
    /* I.S wahana terdefinisi */
    /* F.S mengirimkan true jika panuh dan false jika tidak. */
    /* Proses: jika atribut isi_pengunjung == kapasitas, berarti wahana W sudah penuh */
    return IsiW(&W) == KapasitasW(&W);
}

void addPengunjung(Wahana *W)
{
    /* I.S wahana W terdefinisi, wahana pasti belum penuh */
    /* F.S isi_pengunjung wahana W bertambah 1. Bisa menjadi penuh */
    IsiW(W) += 1;
}

void kosongkanIsi(Wahana *W)
{
    /* I.S wahana terdefinisi, wahana telah selesai menjalankan permainan sekali */
    /* F.S atribut isi_pengunjung wahana W dikosongkan menjadi 0 kembali */
    IsiW(W) = 0;
}

/* ** Laporan Wahana ** */
void addPendapatan(Wahana *W)
{
    /* I.S wahana terdefinisi dan telah selesai menjalankan permainan sekali */
    /* F.S pendapata_total dan pendapatan hari ini bertambah sebanyak tarif */
    TotalPendapatan(W) += TarifW(W);
    CurrentPendapatan(W) += TarifW(W);
}

void addPenggunaan(Wahana *W)
{
    /* I.S wahana terdefinisi dan telah selesai menjalankan permainan sekali */
    /* F.S record_total_penggunaan dan record_penggunaan bertambah satu */
    TotalPenggunaan(W) += 1;
    CurrentPenggunaan(W) += 1;
}

void catatPermainan(Wahana *W)
{
    /* I.S wahana terdefinisi dan telah selesai menjalankan permainan sekali */
    /* F.S laporan permainan Wahana W diupdate */
    /* Proses: Pemangilan procedure addPenggunaan dan addPenghasilan */
    addPendapatan(W);
    addPenggunaan(W);
}

void emptyLaporanHariIni(Wahana *W)
{
    /* I.S wahana terdefinisi */
    /* F.S laporan hari ini diset 0 kembali */
    CurrentPendapatan(W) = 0;
    CurrentPenggunaan(W) = 0;
}