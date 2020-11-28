#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "src/boolean.h"

MATRIKS M1, M2, M3, M4;
Player P1;
int menu1;
char name[20],input[20];
POINT PosPlayer;
JAM CurrTime;
int Money;
int currGraph;
boolean prepFase;
int currDay;

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
    printf("Welcome to Willy wangky's fum factory!!\n");
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
            if ((i == Absis(P1.pos)) && (j == Ordinat(P1.pos))){
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
    printf("\n");
    TulisMATRIKS(M1);
    printf("\n");
    awal(P1);
}
void awal(Player P1){
    /*system("@cls||clear");*/
    if (prepFase = true){
        printf("Preparation Phase Day ");printf("%d\n",currDay);
    }
    if (prepFase = false){
        printf("Main Phase Day ");printf("%d\n",currDay);
    }
    for(int i = 0;i < 10; i++){
        for(int j = 0; j < 20; j++){
            if (ElmtM(M1,i,j)==9){
                printf("P");
            }
            else if (ElmtM(M1,i,j)==0){
                printf("#");
            }
            else if (ElmtM(M1,i,j)==6){
                printf("A");
            }
            else if (ElmtM(M1,i,j)==7){
                printf("O");
            }
            else if (ElmtM(M1,i,j)==3){
                printf(">");
            }
            else if (ElmtM(M1,i,j)==4){
                printf("V");
            }
            else{
                printf("-");
            }
        }
        printf("\n");
    }
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
    /*Total aksi yang akan dilakukan: 0
    Total waktu yang dibutuhkan: 0
    Total uang yang dibutuhkan: 0*/
    scanf("%s",input);
    game(P1);
}

void game(Player P1){
    if (strcmp(input,"s")){
        Maju(&P1);
    }
    if (strcmp(input,"a")){
        Kiri(&P1);
    }
    if (strcmp(input,"d")){
        Kanan(&P1);
    }
    if (strcmp(input,"w")){
        Mundur(&P1);
    }
    init(P1);
}

int main(){
    main_menu();
    return 0;
}