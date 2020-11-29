#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "src/boolean.h"

MATRIKS M1, M2, M3, M4;
Player P1;
Stack S1, S2, S3;
int menu1;
char name[20], input[20];
POINT PosPlayer;
PrioQ PQ1;
JAM CurrTime;
int Money;
int PosGraph;
boolean prepFase;
int currDay;
int stacktotalAksi, stacktotalJam, stacktotalUang;
Graph G;
POINT PosOffice, PosAntrian;

void quit()
{
    printf("Thanks for playing!!\n");
    exit(0);
}

void main_menu()
{
    system("@cls||clear");
    printf(" __       __)              __       __)                       __       __)          \n");
    printf("(, )  |  /  , /) /)       (, )  |  /          /)     /       (, )  |  /      /)  /) \n");
    printf("   | /| /    // //           | /| / _ __  _  (/_      _         | /| / ____ // _(/  \n");
    printf("   |/ |/  _((/_(/_(_/_       |/ |/ (_(/ ((_/_/(_(_/_ /_)_       |/ |/ (_) ((/_(_(_  \n");
    printf("   /  |          .-/         /  |       .-/    .-/              /  |                \n");
    printf("                (_/                    (_/    (_/                                   \n");
    printf("Welcome to Willy wangky's fun factory!!\n");
    printf("------------------------------\n");

    printf("1. LOAD GAME\n");
    printf("2. NEW GAME\n");
    printf("3. EXIT\n");
    printf("Masukkan pilihan menu di bawah ini:\n");
    scanf("%d", &menu1);
    if (menu1 == 1)
    {
        return;
    }
    else if (menu1 == 2)
    {
        printf("Memulai permainan baru...\n");
        printf("Masukkan nama:");
        scanf("%s", name);
        P1 = NewPlayer(PosPlayer, CurrTime, Money);
        init(P1);
    }
    else
    {
        quit();
    }
}

void init(Player P1)
{
    MakeMATRIKS(10, 20, &M1);
    MakeMATRIKS(10, 20, &M2);
    MakeMATRIKS(10, 20, &M3);
    MakeMATRIKS(10, 20, &M4);
    currDay = 1;
    prepFase = true;
    PosGraph = 1;
    stacktotalAksi, stacktotalJam, stacktotalUang = 0;
    PosOffice = MakePOINT(7, 1);
    PosAntrian = MakePOINT(4, 1);
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    CreateEmpty(&S3);
    MakeEmptyPrio(&PQ1, 5);
    Preparation(P1, name, currDay, S1);
}

void legenda(Player P1)
{
    /*system("@cls||clear");*/
    if (prepFase = true)
    {
        printf("Preparation Phase Day ");
        printf("%d\n", currDay);
    }
    if (prepFase = false)
    {
        printf("Main Phase Day ");
        printf("%d\n", currDay);
    }
    printPeta(P1, G, PosGraph, PosAntrian, PosOffice);
    // PRINT PETA
    printf(" \n");
    printf("Legend:\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<, ^, >, V = Gerbang\n");
    printf("\n");
    printf("Nama: ");
    printf("%s\n", name);
    printf("Money: ");
    printf("%d\n", Money(&P1));
    printf("A : <%d,%d>\n", Absis(P1.pos), Ordinat(P1.pos));
    printf("%s\n", input);

    printf("Current Time: ");
    printf("%02d", Hour(Wkt(&P1)));
    printf(".%02d\n", Minute(Wkt(&P1)));
    printf("Opening Time: 09.00\n");
    printf("Time Remaining: ");
    printf("%d", (21 - Hour(Wkt(&P1))));
    printf(" hour(s)\n");
    if (prepFase == true)
    {
        printf("Total aksi yang akan dilakukan: ");
        printf("%d\n", stacktotalAksi);
        printf("Total waktu yang dibutuhkan: ");
        printf("%d\n", stacktotalJam);
        printf("Total uang yang dibutuhkan: "), printf("%d\n", stacktotalUang);
    }
    else
    {
        printf("Antrian [");
        printf("%d", NBElmtPrio(PQ1));
        printf("/5]\n");
        PrintPrioQueue(PQ1);
        printf("\n");
    }
    printf("Masukkan perintah : ");
    scanf("%s", input);
    game(P1);
}

void game(Player P1)
{
    if (strcmp(input, "s"))
    {
        CekMundur(&P1, &G, PosGraph);
        AddWaktu(&P1, 1);
    }
    if (strcmp(input, "a"))
    {
        CekKanan(&P1, &G, PosGraph);
        AddWaktu(&P1, 1);
    }
    if (strcmp(input, "d"))
    {
        CekKiri(&P1, &G, PosGraph);
        AddWaktu(&P1, 1);
    }
    if (strcmp(input, "w"))
    {
        CekMaju(&P1, &G, PosGraph);
        AddWaktu(&P1, 1);
    }
    if (strcmp(input, "prepare")){
        Prepare();
    }
}

int main()
{
    main_menu();
    return 0;
}

void printPeta(Player P1, Graph G, int PosGraph, POINT PosAntrian, POINT PosOffice)
{
    MATRIKS iniPeta = MatriksGraph(searchNodeId(&G, PosGraph));
    ElmtM(iniPeta, Ordinat(PosAntrian), Absis(PosAntrian)) = 6;
    ElmtM(iniPeta, Ordinat(Pos(&P1)), Absis(Pos(&P1))) = 9;
    ElmtM(iniPeta, Ordinat(PosOffice), Absis(PosOffice)) = 7;
    TulisMATRIKS(iniPeta); //ini diubah
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

void legendMain(Player P1)
{
    // printMap(M); // harusnya prosedure print map yang dipakai di main, akan ditambahkan di extern
    printf("\nLegend:\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<, ^, >, V = Gerbang\n");
    printf("\n");
    printf("Nama: ");
    printf("%s",name);
    printf("Money: ");
    printf("%d\n", Money(&P1));
    printf("Current Time: ");
    printf("%02d", Hour(Wkt(&P1)));
    printf(".%02d\n", Minute(Wkt(&P1)));
    printf("\nOpening Time: 09.00\n");
    printf("Time Remaining: 12 hour(s)\n");
    printf("Antrian [");
    printf("%d", NBElmtPrio(PQ1));
    printf("/5]\n");
    PrintPrioQueue(PQ1);
    printf("\n");
}

void PrintDetail(Wahana ListWahana, int i)
{
    printf("Nama : %s\n", JenisW(ListWahana[i]));
    printf("Lokasi : (%d,%d)\n", Absis(PosW(ListWahana[i])), Ordinat(PosW(ListWahana[i])));
    printf("Deskripsi : %s\n", DeskripsiW(ListWahana[i]));
    printf("Harga : %d\n", TarifW(ListWahana[i]));
    printf("Kapasitas : %d \n", KapasitasW(ListWahana[i]));
    printf("Upgrade(s) : "); PrintList(HistoryW(ListWahana[i])); printf("\n");
    printf("Durasi : %d\n", DurasiW(ListWahana[i]));
    if (Rusak(ListWahana[i]))
        printf("Status : Rusak\n");
    else
        printf("Status : Berfungsi\n");
}

void PrintOffice(Wahana ListWahana, int i)
{
    printf("Nama : %s\n", JenisW(ListWahana[i]));
    printf("Lokasi : (%d,%d)\n", Absis(PosW(ListWahana[i])), Ordinat(PosW(ListWahana[i])));
    printf("Deskripsi : %s\n", DeskripsiW(ListWahana[i]));
    printf("Harga : %d\n", TarifW(ListWahana[i]));
    printf("Kapasitas : %d \n", KapasitasW(ListWahana[i]));
    printf("Upgrade(s) : "); PrintList(HistoryW(ListWahana[i])); printf("\n");
    printf("Durasi : %d\n", DurasiW(ListWahana[i]));
    if (Rusak(ListWahana[i]))
        printf("Status : Rusak\n");
    else
        printf("Status : Berfungsi\n");
    
    printf("Berapa kali wahana dinaiki : %d\n", TotalPenggunaan(ListWahana[i]));
    printf("Total penghasilan wahana : %d\n", TotalPendapatan(ListWahana[i]));
    printf("Berapa kali wahana dinaiki hari ini : %d\n", TotalPendapatan(ListWahana[i]));
    printf("Total penghasilan wahana : %d\n", TotalPendapatan(ListWahana[i]));
}

void Detail(Player P1, Wahana ListWahana)
{
    int i=0;
    while (i<strlen(ListWahana)){
        if (Absis(Pos(&P1)) == Absis(PosW(ListWahana[i])) && Ordinat(Pos(&P1)) == Ordinat(PosW(ListWahana[i])) + 1)
        {
            // Wahana berada di atas player
            PrintDetail(Wahana ListWahana, int i);
        }
        else if (Absis(Pos(&P1)) == Absis(PosW(ListWahana[i])) && Ordinat(Pos(&P1)) == Ordinat(PosW(ListWahana[i])) - 1)
        {
            // Wahana berada di bawah player
            PrintDetail(Wahana ListWahana, int i);
        }
        else if (Absis(Pos(&P1)) == Absis(PosW(ListWahana[i])) - 1 && Ordinat(Pos(&P1)) == Ordinat(PosW(ListWahana[i])))
        {
            // Wahana berada di kanan player
            PrintDetail(Wahana ListWahana, int i);
        }
        else if (Absis(Pos(&P1)) == Absis(PosW(ListWahana[i])) + 1 && Ordinat(Pos(&P1)) == Ordinat(PosW(ListWahana[i])))
        {
            // Wahana berada di kiri player
            PrintDetail(Wahana ListWahana, int i);
        }
        i++;
    }
    
}

void Serve(int *ID)
{
    /*Serve sehingga dequeue*/
    Wahana W;
    IDW(&W) = ID;
    DequeueQ(&Q1, X);
    if (IsEmptyQ(Q1))
    {
        DequeuePrio(&PQ1, X);
    }
    AddWaktu(&P1, 10);
}

void Prepare()
{
    Hour(P1.wkt) = 21;
    Minute(P1.wkt) = 0;
    MakeEmptyPrio(&PQ1, 5);
    Preparation(P1, name, currDay, S1);
}

void Repair(Wahana *W, PrioQ *PQ1)
{
    Rusak(W) = false;
    PrioQ(HeadPrio(*PQ1)) -= 1;
}

void GameOver(){
    if(PrioQ(HeadPrio(*PQ1))==0){ 
        quit();
    }
}

void Office(Player P1, Wahana ListWahana)
{
    if (Pos(&P1) == PosOffice){
        int i=0;
        while (i<strlen(ListWahana)){
            PrintOffice(ListWahana, i);
            i++;
        }
        //PosW(ListWahana[i])
        //JenisW(ListWahana[i])
    }
    
}

void Antrian(PrioQ PQ1)
{
    Queue QAntrian;
    int panjang_antrian = (rand() % 5);
    CreateEmptyQ(&QAntrian);
    for (int i = 0; i < panjang_antrian; i++)
    {
        /*Inisialisasi ID Wahana kita*/
        EnqueueQ(&QAntrian, (rand() % 10));
    }
    EnqueuePrio(&PQ1, QAntrian);
}

void kePrepare(){
    if (Hour(P1.wkt)>21){
        Preparation(P1, name, currDay, S1);
    }
}

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
            printf("");
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
    TulisMATRIKS(iniPeta); //ini diubah
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

void Preparation(Player P, char name[20], int currDay, Stack S)
{
    char perintah[40];
    printf("Preparation phase day %d", currDay);
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
        else if (!strcmp(perintah, "w")) 
        {
            Maju(&P);
        } 
        else if (!strcmp(perintah, "a")) 
        {
            Kiri(&P);
        } 
        else if (!strcmp(perintah, "s")) 
        {
            Mundur(&P);
        } 
        else // perintah == "d"
        {
            Kanan(&P);
        }
    } while (TotalDetikJam <= 75600 && strcmp(perintah, "main"));

    TotalUangPreparation = 0;
    TotalAksi = 0;
    TotalDetikJam = 0;
}