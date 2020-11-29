#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "src/boolean.h"

MATRIKS M1, M2, M3, M4;
Player P1;
Stack S1,S2,S3;
int menu1;
char name[20],input[20];
POINT PosPlayer;
PrioQ PQ1;
JAM CurrTime;
int Money;
int currGraph;
boolean prepFase;
int currDay;
int stacktotalAksi, stacktotalJam, stacktotalUang;

void quit(){
    printf("Thanks for playing!!\n");
    exit(0);
}

void main_menu(){
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
    scanf("%d",&menu1);
    if (menu1 == 1){
        return;
    }
    else if (menu1 == 2){
        printf("Memulai permainan baru...\n");
        printf("Masukkan nama:");
        scanf("%s",name);
        P1 = NewPlayer(PosPlayer, CurrTime, Money);
        init(P1);
    }
    else{
        quit();
    }
}

void init(Player P1){
    MakeMATRIKS(10,20,&M1);
    MakeMATRIKS(10,20,&M2);
    MakeMATRIKS(10,20,&M3);
    MakeMATRIKS(10,20,&M4);
    for (int i=0;i<NBrsEff(M1);i++){
        for (int j=0;j<NKolEff(M1);j++){
            if ((i == Ordinat(P1.pos)) && (j == Absis(P1.pos))){
                ElmtM(M1,i,j) = 9;
            }
            if ((i == GetFirstIdxBrs(M1))||(i == GetLastIdxBrs(M1))||(j == GetFirstIdxKol(M1))||(j == GetLastIdxKol(M1))){
                ElmtM(M1,i,j) = 0;
            }
            if ((i == 2)&&(j == 4)){
                ElmtM(M1,i,j) = 6;
            }
            if ((i == 2)&&(j == 7)){
                ElmtM(M1,i,j) = 7;
            }
            if ((i == 4)&&(j == GetLastIdxKol(M1))){
                ElmtM(M1,i,j) = 3;
            }
            if (i == (GetLastIdxBrs(M1))&&(j == 9)){
                ElmtM(M1,i,j) = 4;
            }
        }
    }
    for (int i=0;i<NBrsEff(M2);i++){
        for (int j=0;j<NKolEff(M2);j++){
            if ((i == Ordinat(P1.pos)) && (j == Absis(P1.pos))){
                ElmtM(M2,i,j) = 9;
            }
            if ((i == GetFirstIdxBrs(M2))||(i == GetLastIdxBrs(M2))||(j == GetFirstIdxKol(M2))||(j == GetLastIdxKol(M2))){
                ElmtM(M2,i,j) = 0;
            }
            if ((i == 2)&&(j == 4)){
                ElmtM(M2,i,j) = 6;
            }
            if ((i == 4)&&(j == GetFirstIdxKol(M2))){
                ElmtM(M2,i,j) = 5;
            }
            if (i == (GetFirstIdxBrs(M2))&&(j == 9)){
                ElmtM(M2,i,j) = 2;
            }
        }
    }
    for (int i=0;i<NBrsEff(M3);i++){
        for (int j=0;j<NKolEff(M3);j++){
            if ((i == Ordinat(P1.pos)) && (j == Absis(P1.pos))){
                ElmtM(M3,i,j) = 9;
            }
            if ((i == GetFirstIdxBrs(M3))||(i == GetLastIdxBrs(M3))||(j == GetFirstIdxKol(M3))||(j == GetLastIdxKol(M3))){
                ElmtM(M3,i,j) = 0;
            }
            if ((i == 2)&&(j == 4)){
                ElmtM(M3,i,j) = 6;
            }
            if ((i == 4)&&(j == GetFirstIdxKol(M3))){
                ElmtM(M3,i,j) = 5;
            }
            if (i == (GetFirstIdxBrs(M3))&&(j == 9)){
                ElmtM(M3,i,j) = 2;
            }
        }
    }
    for (int i=0;i<NBrsEff(M4);i++){
        for (int j=0;j<NKolEff(M4);j++){
            if ((i == Ordinat(P1.pos)) && (j == Absis(P1.pos))){
                ElmtM(M4,i,j) = 9;
            }
            if ((i == GetFirstIdxBrs(M4))||(i == GetLastIdxBrs(M4))||(j == GetFirstIdxKol(M4))||(j == GetLastIdxKol(M4))){
                ElmtM(M4,i,j) = 0;
            }
            if ((i == 2)&&(j == 4)){
                ElmtM(M4,i,j) = 6;
            }
            if ((i == 4)&&(j == GetLastIdxKol(M4))){
                ElmtM(M4,i,j) = 3;
            }
            if (i == (GetFirstIdxBrs(M2))&&(j == 9)){
                ElmtM(M4,i,j) = 2;
            }
        }
    }
    currDay = 1;
    prepFase = true;
    currGraph = 1;
    stacktotalAksi, stacktotalJam, stacktotalUang = 0;
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    CreateEmpty(&S3);
    MakeEmptyPrio(&PQ1,5);
    TulisMATRIKS(M1);
    legenda(P1);
}

void updateMap(Player P1){
    MakeMATRIKS(10,20,&M1);
    MakeMATRIKS(10,20,&M2);
    MakeMATRIKS(10,20,&M3);
    MakeMATRIKS(10,20,&M4);
    for (int i=0;i<NBrsEff(M1);i++){
        for (int j=0;j<NKolEff(M1);j++){
            if ((i == Ordinat(P1.pos)) && (j == Absis(P1.pos))){
                ElmtM(M1,i,j) = 9;
            }
            if ((i == GetFirstIdxBrs(M1))||(i == GetLastIdxBrs(M1))||(j == GetFirstIdxKol(M1))||(j == GetLastIdxKol(M1))){
                ElmtM(M1,i,j) = 0;
            }
            if ((i == 2)&&(j == 4)){
                ElmtM(M1,i,j) = 6;
            }
            if ((i == 2)&&(j == 7)){
                ElmtM(M1,i,j) = 7;
            }
            if ((i == 4)&&(j == GetLastIdxKol(M1))){
                ElmtM(M1,i,j) = 3;
            }
            if (i == (GetLastIdxBrs(M1))&&(j == 9)){
                ElmtM(M1,i,j) = 4;
            }
        }
    }
    for (int i=0;i<NBrsEff(M2);i++){
        for (int j=0;j<NKolEff(M2);j++){
            if ((i == Ordinat(P1.pos)) && (j == Absis(P1.pos))){
                ElmtM(M2,i,j) = 9;
            }
            if ((i == GetFirstIdxBrs(M2))||(i == GetLastIdxBrs(M2))||(j == GetFirstIdxKol(M2))||(j == GetLastIdxKol(M2))){
                ElmtM(M2,i,j) = 0;
            }
            if ((i == 2)&&(j == 4)){
                ElmtM(M2,i,j) = 6;
            }
            if ((i == 4)&&(j == GetFirstIdxKol(M2))){
                ElmtM(M2,i,j) = 5;
            }
            if (i == (GetFirstIdxBrs(M2))&&(j == 9)){
                ElmtM(M2,i,j) = 2;
            }
        }
    }
    for (int i=0;i<NBrsEff(M3);i++){
        for (int j=0;j<NKolEff(M3);j++){
            if ((i == Ordinat(P1.pos)) && (j == Absis(P1.pos))){
                ElmtM(M3,i,j) = 9;
            }
            if ((i == GetFirstIdxBrs(M3))||(i == GetLastIdxBrs(M3))||(j == GetFirstIdxKol(M3))||(j == GetLastIdxKol(M3))){
                ElmtM(M3,i,j) = 0;
            }
            if ((i == 2)&&(j == 4)){
                ElmtM(M3,i,j) = 6;
            }
            if ((i == 4)&&(j == GetFirstIdxKol(M3))){
                ElmtM(M3,i,j) = 5;
            }
            if (i == (GetFirstIdxBrs(M3))&&(j == 9)){
                ElmtM(M3,i,j) = 2;
            }
        }
    }
    for (int i=0;i<NBrsEff(M4);i++){
        for (int j=0;j<NKolEff(M4);j++){
            if ((i == Ordinat(P1.pos)) && (j == Absis(P1.pos))){
                ElmtM(M4,i,j) = 9;
            }
            if ((i == GetFirstIdxBrs(M4))||(i == GetLastIdxBrs(M4))||(j == GetFirstIdxKol(M4))||(j == GetLastIdxKol(M4))){
                ElmtM(M4,i,j) = 0;
            }
            if ((i == 2)&&(j == 4)){
                ElmtM(M4,i,j) = 6;
            }
            if ((i == 4)&&(j == GetLastIdxKol(M4))){
                ElmtM(M4,i,j) = 3;
            }
            if (i == (GetFirstIdxBrs(M2))&&(j == 9)){
                ElmtM(M4,i,j) = 2;
            }
        }
    }
    legenda(P1);
}

MATRIKS currMatriks (int currGraph){
    MATRIKS M;
    if(currGraph == 1){
        M = M1;
    }
    if(currGraph == 2){
        M = M2;
    }
    if(currGraph == 3){
        M = M3;
    }
    if(currGraph == 4){
        M = M4;
    }
    return M;
}
void legenda(Player P1){
    /*system("@cls||clear");*/
    if (prepFase = true){
        printf("Preparation Phase Day ");printf("%d\n",currDay);
    }
    if (prepFase = false){
        printf("Main Phase Day ");printf("%d\n",currDay);
    }
    /*Ini TEMPAT MAP
    for(int i = 0;i < 10; i++){
        for(int j = 0; j < 20; j++){
            if (ElmtM(currMatriks(currGraph),i,j)==9){
                printf("P");
            }
            else if (ElmtM(currMatriks(currGraph),i,j)==0){
                printf("*");
            }
            else if (ElmtM(currMatriks(currGraph),i,j)==6){
                printf("A");
            }
            else if (ElmtM(currMatriks(currGraph),i,j)==7){
                printf("O");
            }
            else if (ElmtM(currMatriks(currGraph),i,j)==3){
                printf(">");
            }
            else if (ElmtM(currMatriks(currGraph),i,j)==4){
                printf("V");
            }
            else{
                printf("-");
            }
        }
        printf("\n");
    }
    */
    printf("Legend:\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<, ^, >, V = Gerbang\n");
    printf("\n");
    printf("Nama: ");
    printf("%s\n",name);
    printf("Money: ");
    printf("%d\n", Money(&P1));
    printf("A : <%d,%d>\n", Absis(P1.pos), Ordinat(P1.pos));
    printf("%s\n",input);

    printf("Current Time: "); printf("%02d",Hour(Wkt(&P1)));printf(".%02d\n",Minute(Wkt(&P1)));
    printf("Opening Time: 09.00\n");
    printf("Time Remaining: "); printf("%d",(21 - Hour(Wkt(&P1)))); printf(" hour(s)\n");
    if (prepFase==true){
        printf("Total aksi yang akan dilakukan: ");printf("%d\n",stacktotalAksi);
        printf("Total waktu yang dibutuhkan: " );printf("%d\n",stacktotalJam);
        printf("Total uang yang dibutuhkan: "),printf("%d\n",stacktotalUang);
    }else{
        printf("Antrian [");printf("%d",NBElmtPrio(PQ1));printf("/5]\n");
        PrintPrioQueue(PQ1);
        printf("\n");
    }
    printf("Masukkan perintah : ");
    scanf("%s",input);
    game(P1);
}

void game(Player P1){
    if(currGraph==1){
        if (strcmp(input,"s")){
            Mundur(&P1);
            AddWaktu(&P1, 1);
        }
        if (strcmp(input,"a")){
            Kanan(&P1);
            AddWaktu(&P1, 1);
        }
        if (strcmp(input,"d")){
            Kiri(&P1);
            AddWaktu(&P1, 1);
        }
        if (strcmp(input,"w")){
            Maju(&P1);
            AddWaktu(&P1, 1);
        }
        if(Ordinat(P1.pos)==GetLastIdxBrs(M1)){
            currGraph==4;
            Ordinat(P1.pos) = (Ordinat(P1.pos)-8);
        }else if(Absis(P1.pos)==GetLastIdxKol(M1)){
            currGraph==2;
            Absis(P1.pos) = Absis(P1.pos)-18;
        }else{
            printf("Ada Tembok!");
            if(Ordinat(P1.pos)==GetFirstIdxBrs(M1)){
                Ordinat(P1.pos) = Ordinat(P1.pos) + 1;
            }else if(Absis(P1.pos)==GetFirstIdxKol(M1)){
                Absis(P1.pos) = Absis(P1.pos) + 1;
            }
        }
    }
    updateMap(P1);
}

int main(){
    main_menu();
    return 0;