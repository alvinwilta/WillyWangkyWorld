#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./wahana/wahana.h"
#include "./jam/jam.h"
#include "./tree/bintree.h"
#include "./matriks/matriks.h"
#include "./tree/listrek.h"
#include "./point/point.h"
#include "./player/player.h"
#include "./stack/stack.h"
#include "./mesinkata/mesinkata.h"
#include "./mesinkata/mesinkar.h"
#include "./graph/graph.h"
#include "preparation.h"

int TotalUangPreparation;
int TotalAksi;
long TotalDetikJam;
int TotalWahana;
char ListNamaWahana[20][30] = {"halilintar", "bianglala", "niagara", "korakora", "tornado", "kicirkicir", "skydiver", "balloon", "freefall", "madhouse"};

extern Wahana ListWahana[20];
extern Graph G;
extern int PosGraph;
extern BinTree WahanaUpgrade;

// token stack
// build = 10001, upgrade = 10002, buy = 10003
// build
// 10001, 1-10, x, y,       [10001,1,1,1]
// upgrade
// 10002, id, 1-2,
// buy
// 10003, 1-3, N            [10003,1,200]


Wahana Build(Player *P, POINT pos, Stack S)
{

    printf("Pilih wahana yang akan dibangun:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("    - %s\n", ListNamaWahana[i]);
    }
    char wahanaName[30];
    scanf("%s", wahanaName);
    int id = TotalWahana + 1;
    Wahana W = NewWahana(wahanaName, id, pos);
    Mundur(P);
    Money(P) -= 350;
    TotalWahana += 1;
    TotalUangPreparation += 350;
    TotalAksi += 1;
    TotalDetikJam += 7200;
    

    // push [build,namawahana,pos,delimiter]
    Push(&S, Ordinat(Pos(P)));
    Push(&S, Absis(Pos(P)));
    if (!strcmp(wahanaName, "halilintar"))
    {
        Push(&S, 1);
    }
    else if (!strcmp(wahanaName, "bianglala"))
    {
        Push(&S, 2);
    }
    else if (!strcmp(wahanaName, "niagara"))
    {
        Push(&S, 3);
    }
    else if (!strcmp(wahanaName, "korakora"))
    {
        Push(&S, 4);
    }
    else if (!strcmp(wahanaName, "tornado"))
    {
        Push(&S, 5);
    }
    else if (!strcmp(wahanaName, "kicirkicir"))
    {
        Push(&S, 6);
    }
    else if (!strcmp(wahanaName, "skydiver"))
    {
        Push(&S, 7);
    }
    else if (!strcmp(wahanaName, "balloon"))
    {
        Push(&S, 8);
    }
    else if (!strcmp(wahanaName, "freefall"))
    {
        Push(&S, 9);
    }
    else if (!strcmp(wahanaName, "madhouse"))
    {
        Push(&S, 10);
    }
    Push(&S, 10001);

    ListWahana[TotalWahana-1] = W;
    return W;
}

void UpgradeWahana(Player *P, Wahana *W, Stack S)
{
    char pilihan[30];

    if (Money(P) <= 350)
    {
        printf("Uang anda tidak cukup untuk melakukan upgrade apapun!\n");
    }
    else if (!(JenisW(W), "halilintar"))
    {
        printf("List upgrade:\n");
        printf("    - listrikhalilintar\n");
        printf("    - attahalilintar\n");
        scanf("%s", pilihan);
        if (!strcmp(pilihan, "listrikhalilintar"))
        {
            upgrade(W, 0, WahanaUpgrade);
            Push(&S, 0);
        }
        else
        {
            upgrade(W, 1, WahanaUpgrade);
            Push(&S, 1);
        }
    }
    else if (!(JenisW(W), "bianglala"))
    {
        printf("List upgrade:\n");
        printf("    - listrikbianglala\n");
        printf("    - attabianglala\n");
        scanf("%s", pilihan);
        if (!strcmp(pilihan, "listrikbianglala"))
        {
            upgrade(W, 0, WahanaUpgrade);
            Push(&S, 0);
        }
        else
        {
            upgrade(W, 1, WahanaUpgrade);
            Push(&S, 1);
        }
    }
    else if (!(JenisW(W), "niagara"))
    {
        printf("List upgrade:\n");
        printf("    - listrikniagara\n");
        printf("    - attaniagara\n");
        scanf("%s", pilihan);
        if (!strcmp(pilihan, "listrikniagara"))
        {
            upgrade(W, 0, WahanaUpgrade);
            Push(&S, 0);
        }
        else
        {
            upgrade(W, 1, WahanaUpgrade);
            Push(&S, 1);
        }
    }
    else if (!(JenisW(W), "korakora"))
    {
        printf("List upgrade:\n");
        printf("    - listrikkorakora\n");
        printf("    - attakorakora\n");
        scanf("%s", pilihan);
        if (!strcmp(pilihan, "listrikkorakora"))
        {
            upgrade(W, 0, WahanaUpgrade);
            Push(&S, 0);
        }
        else
        {
            upgrade(W, 1, WahanaUpgrade);
            Push(&S, 1);
        }
    }
    else if (!(JenisW(W), "tornado"))
    {
        printf("List upgrade:\n");
        printf("    - listriktornado\n");
        printf("    - attatornado\n");
        scanf("%s", pilihan);
        if (!strcmp(pilihan, "listriktornado"))
        {
            upgrade(W, 0, WahanaUpgrade);
            Push(&S, 0);
        }
        else
        {
            upgrade(W, 1, WahanaUpgrade);
            Push(&S, 1);
        }
    }
    else if (!(JenisW(W), "kicirkicir"))
    {
        printf("List upgrade:\n");
        printf("    - listrikkicirkicir\n");
        printf("    - attakicirkicir\n");
        scanf("%s", pilihan);
        if (!strcmp(pilihan, "listrikkicirkicir"))
        {
            upgrade(W, 0, WahanaUpgrade);
            Push(&S, 0);
        }
        else
        {
            upgrade(W, 1, WahanaUpgrade);
            Push(&S, 1);
        }
    }
    else if (!(JenisW(W), "skydiver"))
    {
        printf("List upgrade:\n");
        printf("    - listrikskydiver\n");
        printf("    - attaskydiver\n");
        scanf("%s", pilihan);
        if (!strcmp(pilihan, "listrikskydiver"))
        {
            upgrade(W, 0, WahanaUpgrade);
            Push(&S, 0);
        }
        else
        {
            upgrade(W, 1, WahanaUpgrade);
            Push(&S, 1);
        }
    }
    else if (!(JenisW(W), "balloon"))
    {
        printf("List upgrade:\n");
        printf("    - listrikballoon\n");
        printf("    - attaballoon\n");
        scanf("%s", pilihan);
        if (!strcmp(pilihan, "listrikballoon"))
        {
            upgrade(W, 0, WahanaUpgrade);
            Push(&S, 0);
        }
        else
        {
            upgrade(W, 1, WahanaUpgrade);
            Push(&S, 1);
        }
    }
    else if (!(JenisW(W), "freefall"))
    {
        printf("List upgrade:\n");
        printf("    - listrikfreefall\n");
        printf("    - attafreefall\n");
        scanf("%s", pilihan);
        if (!strcmp(pilihan, "listrikfreefall"))
        {
            upgrade(W, 0, WahanaUpgrade);
            Push(&S, 0);
        }
        else
        {
            upgrade(W, 1, WahanaUpgrade);
            Push(&S, 1);
        }
    }
    else if (!(JenisW(W), "madhouse"))
    {
        printf("List upgrade:\n");
        printf("    - listrikmadhouse\n");
        printf("    - attamadhouse\n");
        scanf("%s", pilihan);
        if (!strcmp(pilihan, "listrikmadhouse"))
        {
            upgrade(W, 0, WahanaUpgrade);
            Push(&S, 0);
        }
        else
        {
            upgrade(W, 1, WahanaUpgrade);
            Push(&S, 1);
        }
    }

    Push(&S, IDW(W));
    Push(&S, 10002);
}

void Buy(Player *P, Stack S)
{
    char BuyItem[5];
    int TotalItem;
    printf("Ingin membeli apa?\n");
    printf("    - kayu\n");
    printf("    - batu\n");
    printf("    - paku\n");
    scanf("%d", &TotalItem);
    scanf("%s", BuyItem);
    printf("Total item: %d\n", TotalItem);
    printf("Nama item: %s\n", BuyItem);

    boolean UangCukup;
    int totalUang = 0;
    if (!strcmp(BuyItem, "kayu"))
    {
        UangCukup = IsUangCukup(*P, TotalItem, 0);
        if (UangCukup)
        {
            totalUang = 10 * TotalItem;
            AddKayu(P, TotalItem);
        }
        else
        {
            printf("Uang anda tidak cukup!\n");
        }
    }
    else if (!strcmp(BuyItem, "batu"))
    {
        UangCukup = IsUangCukup(*P, TotalItem, 1);
        if (UangCukup)
        {
            totalUang = 20 * TotalItem;
            AddBatu(P, TotalItem);
        }
        else
        {
            printf("Uang anda tidak cukup!\n");
        }
    }
    else // BuyItem == "paku"
    {
        UangCukup = IsUangCukup(*P, TotalItem, 2);
        if (UangCukup)
        {
            totalUang = 30 * TotalItem;
            AddPaku(P, TotalItem);
        }
        else
        {
            printf("Uang anda tidak cukup!\n");
        }
    }
    TotalUangPreparation += totalUang;
    TotalAksi += 1;
    TotalDetikJam += 3600;

    // pushstack [buy,material,jumlah]
    Push(&S, TotalItem);
    if (!strcmp(BuyItem, "kayu"))
    {
        Push(&S, 1);
    }
    else if (!strcmp(BuyItem, "batu"))
    {
        Push(&S, 2);
    }
    else if (!strcmp(BuyItem, "paku"))
    {
        Push(&S, 3);
    }
    Push(&S, 10003);
}

void deBuy(Player *P, int jenis, int N)
{
    int totalRefund = 0;
    if (jenis = 0)
    {
        totalRefund = 10 * N;
        AddUang(P, totalRefund);
        SubKayu(P, N);
    }
    else if (jenis = 1)
    {
        totalRefund = 20 * N;
        AddUang(P, totalRefund);
        SubBatu(P, N);
    }
    else
    { // jenis = 2 (paku)
        totalRefund = 30 * N;
        AddUang(P, totalRefund);
        SubKayu(P, N);
    }
    TotalUangPreparation -= totalRefund;
    TotalDetikJam -= 3600;
}

void legendPrep(Player P1, char name[20])
{
    JAM PrepTime;
    PrepTime = DetikToJAM(75600);
    int hour = TotalDetikJam / 3600;
    int menit = (TotalDetikJam % 3600) / 60;
    // printMap(M); // harusnya prosedure print map yang dipakai di main, akan ditambahkan di extern
    printf("\nLegend:\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<, ^, >, V = Gerbang\n");
    printf("\n");
    printf("Nama: ");
    printf("%s\n", name);
    printf("Money: ");
    printf("%d\n", Money(&P1));
    printf("Current Time: ");
    TulisJAM(PrepTime);
    printf("\nOpening Time: 09.00\n");
    printf("Time Remaining: 12 hour(s)\n");
    printf("Total aksi yang akan dilakukan: ");
    printf("%d", TotalAksi);
    printf("\n");
    printf("Total waktu yang dibutuhkan: ");
    printf("%d", hour);
    printf(" hour(s) ");
    printf("%d", menit);
    printf(" minute(s)\n");
    printf("Total uang yang dibutuhkan: ");
    printf("%d", TotalUangPreparation);
    printf("\n");
}



void Undo(Player *P, Stack S)
{
    if (!IsEmptyStack(S)) {
        int cekNumber;
        Pop(&S,&cekNumber);
        if (cekNumber == 10001){
        } else if (cekNumber == 10002) {
            
        } else {    // cekNumber == 10003
            int N;
            Pop(&S, &cekNumber);
            Pop(&S, &N);
            deBuy(P, cekNumber, N);
        }
        TotalAksi -= 1;
    }
}

void Execute(Stack S){
    int stackDel;
    while(!IsEmptyStack(S)) {
        Pop(&S, &stackDel);
    }
}
void KeMain(Player *P, Stack S){
    int stackDel;
    while(!IsEmptyStack(S)) {
        Pop(&S, &stackDel);
    }
}

void printPetaPrep(Player P1, Graph G, int PosGraph, POINT PosAntrian, POINT PosOffice)
{
    MATRIKS iniPeta = MatriksGraph(searchNodeId(&G, PosGraph));
    ElmtM(iniPeta, Ordinat(PosAntrian), Absis(PosAntrian)) = 6;
    ElmtM(iniPeta, Ordinat(Pos(&P1)), Absis(Pos(&P1))) = 9;
    ElmtM(iniPeta, Ordinat(PosOffice), Absis(PosOffice)) = 7;
    //TulisMATRIKS(iniPeta); //ini diubah
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (ElmtM(iniPeta, i, j) == 9)
            {
                printf("P");
            }
            else if (ElmtM(iniPeta, i, j) == 0)
            {
                printf("*");
            }
            else if (ElmtM(iniPeta, i, j) == 6)
            {
                printf("A");
            }
            else if (ElmtM(iniPeta, i, j) == 7)
            {
                printf("O");
            }
            else if (ElmtM(iniPeta, i, j) == 3)
            {
                printf(">");
            }
            else if (ElmtM(iniPeta, i, j) == 4)
            {
                printf("V");
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");
    }
}

void CekKanan(Player *P, Graph *G, int PosGraph, POINT PosAntrian, POINT PosOffice) {
    MATRIKS Peta = MatriksGraph(searchNodeId(G,PosGraph));
    int PosPeta = ElmtM(Peta,Absis(Pos(P))+1,Ordinat(Pos(P)));
    if (((Absis(Pos(P))+1)==Absis(PosOffice)) && (Ordinat(Pos(P))==Ordinat(PosOffice))) {
        // Masuk Office
        Office(*P,ListWahana);
        Kanan(P);
    } else if (ElmtM(Peta,(Absis(Pos(P))+1),(Ordinat(Pos(P))))==0) {
        printf("Ada dinding!\n");
        printf("%d\n", Absis(Pos(P)));
        printf("%d\n", Ordinat(Pos(P)));
        TulisMATRIKS(Peta);
    } else if (((Absis(Pos(P))+1)==(Absis(PosAntrian))) && (Ordinat(Pos(P))==Ordinat(PosAntrian))) {
        printf("Ada gedung antrian!\n");
    } else if (ElmtM(Peta,(Absis(Pos(P))+1),(Ordinat(Pos(P))))==8) {
        printf("Ada wahana!\n");
    } else if ((ElmtM(Peta,(Absis(Pos(P))+1),(Ordinat(Pos(P))))==3)) {
        addressNode Q = moveGraph(G,PosGraph,3);
        Pos(P) = lokasiPlayer(G,PosGraph,ID(Q));
        PosGraph = ID(Q);
    } else {
        Kanan(P);
    }
}

void CekKiri(Player *P, Graph *G, int PosGraph, POINT PosAntrian, POINT PosOffice) {
    MATRIKS Peta = MatriksGraph(searchNodeId(G,PosGraph));
    int PosPeta = ElmtM(Peta,Absis(Pos(P))+1,Ordinat(Pos(P)));
    if (((Absis(Pos(P))+1)==Absis(PosOffice)) && (Ordinat(Pos(P))==Ordinat(PosOffice))) {
        // Masuk Office
        Office(*P,ListWahana);
        Kiri(P);
    } else if (ElmtM(Peta,(Absis(Pos(P))+1),(Ordinat(Pos(P))))==0) {
        printf("Ada dinding!\n");
    } else if (((Absis(Pos(P))+1)==(Absis(PosAntrian))) && (Ordinat(Pos(P))==Ordinat(PosAntrian))) {
        printf("Ada gedung antrian!\n");
    } else if (ElmtM(Peta,(Absis(Pos(P))+1),(Ordinat(Pos(P))))==8) {
        printf("Ada wahana!\n");
    } else if (ElmtM(Peta,(Absis(Pos(P))+1),(Ordinat(Pos(P))))==5) {
        addressNode Q = moveGraph(G,PosGraph,3);
        Pos(P) = lokasiPlayer(G,PosGraph,ID(Q));
        PosGraph = ID(Q);
    } else {
        Kiri(P);
    }
}

void CekMaju(Player *P, Graph *G, int PosGraph, POINT PosAntrian, POINT PosOffice) {
    MATRIKS Peta = MatriksGraph(searchNodeId(G,PosGraph));
    int PosPeta = ElmtM(Peta,Absis(Pos(P))+1,Ordinat(Pos(P)));
    if (((Absis(Pos(P))+1)==Absis(PosOffice)) && (Ordinat(Pos(P))==Ordinat(PosOffice))) {
        // Masuk Office
        Office(*P,ListWahana);
        Maju(P);
    } else if (ElmtM(Peta,(Absis(Pos(P))+1),(Ordinat(Pos(P))))==0) {
        printf("Ada dinding!\n");
    } else if (((Absis(Pos(P))+1)==(Absis(PosAntrian))) && (Ordinat(Pos(P))==Ordinat(PosAntrian))) {
        printf("Ada gedung antrian!\n");
    } else if (ElmtM(Peta,(Absis(Pos(P))+1),(Ordinat(Pos(P))))==8) {
        printf("Ada wahana!\n");
    } else if (ElmtM(Peta,(Absis(Pos(P))+1),(Ordinat(Pos(P))))==2) {
        addressNode Q = moveGraph(G,PosGraph,3);
        Pos(P) = lokasiPlayer(G,PosGraph,ID(Q));
        PosGraph = ID(Q);
    } else {
        Maju(P);
    }
}

void CekMundur(Player *P, Graph *G, int PosGraph, POINT PosAntrian, POINT PosOffice) {
    MATRIKS Peta = MatriksGraph(searchNodeId(G,PosGraph));
    int PosPeta = ElmtM(Peta,Absis(Pos(P))+1,Ordinat(Pos(P)));
    if (((Absis(Pos(P))+1)==Absis(PosOffice)) && (Ordinat(Pos(P))==Ordinat(PosOffice))) {
        // Masuk Office
        Office(*P,ListWahana);
        Mundur(P);
    } else if (ElmtM(Peta,(Absis(Pos(P))+1),(Ordinat(Pos(P))))==0) {
        printf("Ada dinding!\n");
    } else if (((Absis(Pos(P))+1)==(Absis(PosAntrian))) && (Ordinat(Pos(P))==Ordinat(PosAntrian))) {
        printf("Ada gedung antrian!\n");
    } else if (ElmtM(Peta,(Absis(Pos(P))+1),(Ordinat(Pos(P))))==8) {
        printf("Ada wahana!\n");
    } else if (ElmtM(Peta,(Absis(Pos(P))+1),(Ordinat(Pos(P))))==4) {
        addressNode Q = moveGraph(G,PosGraph,3);
        Pos(P) = lokasiPlayer(G,PosGraph,ID(Q));
        PosGraph = ID(Q);
    } else {
        Mundur(P);
    }
}

void Preparation(Player P, char name[20], int currDay, Stack S)
{
    char perintah[40];
    printf("Preparation phase day %d\n", currDay);
    int cekTotalDetikJam = TotalDetikJam;
    POINT PosOffice = MakePOINT(7, 1);
    POINT PosAntrian = MakePOINT(4, 1);
    do
    {
        printPetaPrep(P, G, PosGraph, PosAntrian, PosOffice);
        legendPrep(P, name);
        printf("\nMasukkan Perintah:\n");
        scanf("%s", perintah);
        if (!strcmp(perintah, "build"))
        {
            if (cekTotalDetikJam + 7200 <= 75600)
                if (Money(&P) >= 350)
                {
                    Wahana W = Build(&P, Pos(&P), S);
                    //variabel yg dibutuhkan PosGraph (posisi graph), Graph
                    // Graph G
                    // int PosGraph
                    ElmtM(MatriksGraph(searchNodeId(&G,PosGraph)), Ordinat(PosW(&W)),Absis(PosW(&W))) = 8;
                    
                }
                else
                {
                    printf("Uang anda tidak cukup untuk membangun wahana apapun!\n");
                }
            else
            {
                printf("Waktu preparation tidak mencukupi untuk melakukan aksi!\n");
            }
        }
        else if (!strcmp(perintah, "upgrade"))
        {
            if (cekTotalDetikJam + 7200 <= 75600)

                if (Money(&P) >= 350)
                {
                    Wahana W;
                    UpgradeWahana(&P, &W, S);
                }
                else
                {
                    printf("Uang anda tidak cukup untuk melakukan upgrade wahana apapun!\n");
                }
            else
            {
                printf("Waktu preparation tidak mencukupi untuk melakukan aksi!\n");
            }
        }
        else if (!strcmp(perintah, "buy"))
        {
            if (cekTotalDetikJam + 3600 <= 75600)
                if (Money(&P) >= 350)
                {
                    Buy(&P, S);
                }
                else
                {
                    printf("Uang anda tidak cukup untuk membangun wahana apapun!\n");
                }
            else
            {
                printf("Waktu preparation tidak mencukupi untuk melakukan aksi!\n");
            }
        } 
        else if (!strcmp(perintah, "s"))
        {
            CekMundur(&P, &G, PosGraph, PosAntrian, PosOffice);
            AddWaktu(&P, 1);
        }
        else if (!strcmp(perintah, "d"))
        {
            printf("WOIIII\n");
            CekKanan(&P, &G, PosGraph, PosAntrian, PosOffice);
            AddWaktu(&P, 1);
        }
        else if (!strcmp(perintah, "a"))
        {
            CekKiri(&P, &G, PosGraph, PosAntrian, PosOffice);
            AddWaktu(&P, 1);
        }
        else if (!strcmp(perintah, "w"))
        {
            CekMaju(&P, &G, PosGraph, PosAntrian, PosOffice);
            AddWaktu(&P, 1);
        }
        
    } while (TotalDetikJam <= 75600 && strcmp(perintah, "main"));

    TotalUangPreparation = 0;
    TotalAksi = 0;
    TotalDetikJam = 0;
}