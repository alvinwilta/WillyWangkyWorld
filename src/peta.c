#include <stdio.h>
#include <stdlib.h>

void main_menu(){
    int menu1;
    char name[50];
    system("@cls||clear");
    printf("------------------------------\n");
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