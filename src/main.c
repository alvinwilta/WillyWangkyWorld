#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"
#include "mesinkar.h"
#include "wahana/wahana.h"
#include "matriks/matriks.h"
#include "graph/graph.h"
#include "player/player.h"
#include "queue/queue.h"
#include "stack/stack.h"
#include "array/array.h"
#include "point/point.h"

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
        load();
    }
    else if (menu1 == 2){
        printf("Memulai permainan baru...");
        printf("Masukkan nama:");
        scanf("%s", name);
        NewPlayer()
        game();
    }
    else{
        quit();
    }
    return 0;
}

void quit(){
    printf("Thanks for playing!!");
    exit(0);
}

void awal(){
    printMap(M);
    printf("Legend:\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<, ^, >, V = Gerbang\n");
    printf("\n");
    printf("Nama: ");
    printf("%s", name);
    printf("Money: ");
    printf("%d", Money(name));
}

int main(){

}