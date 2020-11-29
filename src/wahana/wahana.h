/* File: wahana.h */
/* ADT Wahana dengan representasi pointer */

#ifndef _CUSTOM_H_
#define _CUSTOM_H_

#include "../tree/bintree.h"
#include "../tree/listrek.h"
#include "../point/point.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Definisi Type */
typedef struct twahana
{
    // Detail Wahana
    int id;
    char jenis[100];      // jenis wahana
    char deskripsi[100];  // deskripsi wahana
    POINT pos;            // posisi wahana pada map
    int kapasitas;        // kapasitas wahana per permainan
    int tarif;            // tarif per permainan
    int durasi;           // durasi dalam menit
    BinTree history_upgrade; // history upgrade berdasarkan tree wahana dan upgrade yang dipilih, implementasi list berkait
    int isi_pengunjung;   // kapasitas wahana yang sudah terisi
    // Laporan Wahana
    int pendapatan_total;        // total pendapatan wahana selama game berjalan
    int record_total_penggunaan; // total penggunaan wahana selama game berjalan
    int pendapatan;              // banyak penghasilan hari ini
    int record_penggunaan;       // banyak penggunaan hari ini
    boolean rusak;               //status rusak
} Wahana;

/* Default value dari data Wahana */
#define DefKapasitas 4
#define DefDurasi 30
#define DefTarif 100

/* Selektor */
#define IDW(W) (W)->id
#define JenisW(W) (W)->jenis
#define DeskripsiW(W) (W)->deskripsi
#define PosW(W) (W)->pos
#define KapasitasW(W) (W)->kapasitas
#define TarifW(W) (W)->tarif
#define DurasiW(W) (W)->durasi
#define HistoryW(W) (W)->history_upgrade
#define IsiW(W) (W)->isi_pengunjung
#define TotalPendapatan(W) (W)->pendapatan_total
#define TotalPenggunaan(W) (W)->record_total_penggunaan
#define CurrentPendapatan(W) (W)->pendapatan
#define CurrentPenggunaan(W) (W)->record_penggunaan
#define Rusak(W) (W)->rusak

/* *** Konstruktor Wahana **** */
Wahana NewWahana(char jenis[], int id, POINT pos);
/* I.S jenis, id, dan pos terdefinisi. ID bersifat unik yang diatur dalam fungsi Build. jenis sudah harus terdaftar di dalam wahana.txt */
/* F.S Wahana baru terbentuk dengan pos di tempat player membuat wahana. pendapatan dan penggunaan diset default 0 */
/* deskripsi diset sesuai dengan deskripsi di wahana.txt */

/* Load Data */

/* ** Detail Wahana ** */
void upgrade(Wahana *W, int pilihan, BinTree treeWahana);
/* I.S wahana, treeWahana, dan pilihan terdefinisi, pilihan merupakan integer upgrade yang dipilih dari tree wahana, jika dipilih left = 0, right = 1 */
/* F.S wahana memiliki atribut tarif dan kapasitas baru. nama wahana berubah sesuai pilihan. history_upgrade diupdate */
/* Proses: Akan dicari node pada Bintree treeWahana yang sesuai dengan nama wahana sebelum diupgrade. Nama wahana akan diubah sesuai dengan pilihan. History upgrade wahana ditambahkan di akhir list */

boolean isPenuh(Wahana W);
/* I.S wahana terdefinisi */
/* F.S mengirimkan true jika panuh dan false jika tidak. */
/* Proses: jika atribut isi_pengunjung == kapasitas, berarti wahana W sudah penuh */

void addPengunjung(Wahana *W);
/* I.S wahana W terdefinisi, wahana pasti belum penuh */
/* F.S isi_pengunjung wahana W bertambah 1. Bisa menjadi penuh */

void subPengunjung(Wahana *W);
/* I.S wahana terdefinisi, wahana telah selesai menjalankan permainan sekali */
/* F.S atribut isi_pengunjung wahana W berkurang 1 */

boolean isBroken(Wahana W);
/* I.S wahana terdefinisi */
/* F.S mengembalikan true jika status rusak */

/* ** Laporan Wahana ** */
void addPendapatan(Wahana *W);
/* I.S wahana terdefinisi dan telah selesai menjalankan permainan sekali */
/* F.S pendapata_total dan pendapatan hari ini bertambah sebanyak tarif */

void addPenggunaan(Wahana *W);
/* I.S wahana terdefinisi dan telah selesai menjalankan permainan sekali */
/* F.S record_total_penggunaan dan record_penggunaan bertambah satu */

void catatPermainan(Wahana *W);
/* I.S wahana terdefinisi dan telah selesai menjalankan permainan sekali */
/* F.S laporan permainan Wahana W diupdate */
/* Proses: Pemangilan procedure addPenggunaan dan addPenghasilan */

void emptyLaporanHariIni(Wahana *W);
/* I.S wahana terdefinisi */
/* F.S laporan */

#endif