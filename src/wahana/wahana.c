#include "../tree/bintree.h"
#include "../tree/listrek.h"
#include "../point/point.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wahana.h"

/* *** Konstruktor Wahana **** */
Wahana NewWahana(char jenis[30], int id, POINT pos)
{
    /* I.S jenis, id, dan pos terdefinisi. ID bersifat unik yang diatur dalam fungsi Build. jenis sudah harus terdaftar di dalam wahana.txt */
    /* F.S Wahana baru terbentuk dengan pos di tempat player membuat wahana. pendapatan dan penggunaan diset default 0 */
    /* deskripsi diset sesuai dengan deskripsi di wahana.txt */
    Wahana W;
    strcpy(JenisW(&W), jenis);
    if (!strcmp(jenis, "halilintar"))
    {
        strcpy(DeskripsiW(&W), "roller coaster terseru");
        KapasitasW(&W) = 10;
        TarifW(&W) = 200;
        DurasiW(&W) = 5;
    }
    else if (!strcmp(jenis, "bianglala"))
    {
        strcpy(DeskripsiW(&W), "gondola terbesar dan paling menegangkan di dunia");
        KapasitasW(&W) = 15;
        TarifW(&W) = 100;
        DurasiW(&W) = 5;
    }
    else if (!strcmp(jenis, "niagara"))
    {
        strcpy(DeskripsiW(&W), "wahana arum jeram yang mendebarkan");
        KapasitasW(&W) = 15;
        TarifW(&W) = 100;
        DurasiW(&W) = 10;
    }
    else if (!strcmp(jenis, "korakora"))
    {
        strcpy(DeskripsiW(&W), "wahana yang menantang dan dapat menguji nyali anda");
        KapasitasW(&W) = 20;
        TarifW(&W) = 200;
        DurasiW(&W) = 10;
    }
    else if (!strcmp(jenis, "tornado"))
    {
        strcpy(DeskripsiW(&W), "wahana yang dijamin membuat kamu pusing 7 keliling");
        KapasitasW(&W) = 10;
        TarifW(&W) = 250;
        DurasiW(&W) = 5;
    }
    else if (!strcmp(jenis, "kicirkicir"))
    {
        strcpy(DeskripsiW(&W), "membuat kamu berputar seperti sebuah kipas");
        KapasitasW(&W) = 15;
        TarifW(&W) = 100;
        DurasiW(&W) = 10;
    }
    else if (!strcmp(jenis, "skydiver"))
    {
        strcpy(DeskripsiW(&W), "wahana ini menyajikan sensasi diayun sampai ke luar angkasa");
        KapasitasW(&W) = 20;
        TarifW(&W) = 150;
        DurasiW(&W) = 10;
    }
    else if (!strcmp(jenis, "balloon"))
    {
        strcpy(DeskripsiW(&W), "wahana balon udara");
        KapasitasW(&W) = 15;
        TarifW(&W) = 200;
        DurasiW(&W) = 15;
    }
    else if (!strcmp(jenis, "freefall"))
    {
        strcpy(DeskripsiW(&W), "wahana yang menyajikan sensasi dijatuhkan dari ketinggian 10.000 kaki");
        KapasitasW(&W) = 10;
        TarifW(&W) = 250;
        DurasiW(&W) = 5;
    }
    else if (!strcmp(jenis, "madhouse"))
    {
        strcpy(DeskripsiW(&W), "wahana rumah hantu yang menyajikan pengalaman seram yang berlum pernah anda rasakan");
        KapasitasW(&W) = 20;
        TarifW(&W) = 200;
        DurasiW(&W) = 10;
    }
    IDW(&W) = id;
    PosW(&W) = pos;
    addressrek P = AlokasiListrek(jenis);
    HistoryW(&W) = P;
    IsiW(&W) = 0;
    TotalPendapatan(&W) = 0;
    TotalPenggunaan(&W) = 0;
    CurrentPendapatan(&W) = 0;
    CurrentPenggunaan(&W) = 0;
    Rusak(&W) = 0;
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
    addrNode N = treeWahana;
    while (!strcmp(Akar(N), JenisW(W)))
    {
        if (SearchTree(Left(N), JenisW(W)))
        {
            N = Left(N);
        }
        else
        {
            N = Right(N);
        }
    }
    if (pilihan == 0) // pilihan == 0, pilih tree kiri
    {
        strcpy(JenisW(W), Akar(Left(N)));
        N = Left(N);
    }
    else // pilihan == 1, pilih tree kanan
    {
        strcpy(JenisW(W), Akar(Right(N)));
        N = Right(N);
    }
    addressrek A = HistoryW(W);
    while (Next(A) != Nil)
    {
        A = Next(A);
    }
    Next(A) = AlokasiListrek(Akar(N));
    strcpy(JenisW(W), Akar(N));
    // strcpy(DeskripsiW(W), deskripsi);
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

void subPengunjung(Wahana *W)
{
    /* I.S wahana terdefinisi, wahana telah selesai menjalankan permainan sekali */
    /* F.S atribut isi_pengunjung wahana W berkurang 1 */
    IsiW(W) -= 1;
}

// boolean isBroken(Wahana W)
// {
//     /* I.S wahana terdefinisi */
//     /* F.S mengembalikan true jika status rusak */
//     // return !StatusW(&W);
// }

// void ubahStatusW(Wahana *W)
// {
//     /* I.S wahana terdefinisi */
//     /* F.S status wahana W berubah. Jika pada kondisi awal bernilai true maka akan menjadi false, begitu pula kebalikannya */
//     if (StatusW(W))
//     {
//         StatusW(W) = false;
//     }
//     else
//     {
//         StatusW(W) = true;
//     }
// }

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