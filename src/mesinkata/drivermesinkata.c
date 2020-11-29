// #include "../include/mesin.h"
// #include "../include/mesinkar.h"

#include "mesinkata.h"
#include "mesinkar.h"
#include "mesintoken.h"
#include "../array/array.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*#include "../wahana/wahana.h"
#include "../matriks/matriks.h"
#include "../graph/graph.h"
#include "../queue/queue.h"
#include "../stack/stack.h"
#include "../array/array.h"
#include "../point/point.h"*/

int main()
{
    Kata K4;
    Token T;
    char Material[20];
    /*Test Mesin Kata*/
    
    Kata K1,K2,K3;
    int N1,N2;
    readSCANF(&K1);
    printKata(K1);
    printf("%d\n",IsKataSama(K1,"sama"));
    readAngkaSCANF(&N1);
    readSCANF(&K3);
    printf("%d\n",N1);
    N2 = stringint(K3);
    printf("%d\n",N2);
    
    /*Test Mesin Token*/
    
    readSCANF(&K4);
    T = readTokenSCANF(K4);
    printf("Jumlah : %d\n",T.val);
    printf("Token item: %c\n",T.tkn);
    
    /*Test Baca File I/O*/
    int i = 0;
    int j = 1;
    START("../../assets/material.txt");
    while((CC!=BLANK)&&(CC!=MARK)){
        Material[i] = CC;
        if ((CC==NEWLINE)&&(j%2==0)){
            printf("%s",Material);
            i = 0;
            j++;
        }else if ((CC==NEWLINE)&&(j%2==1)){
            printf("%s",Material);
            i = 0;
            j++;
        }else{
            i++;
        }
        ADV();
    }
    // membuka file
    /*
    if ((fptr = fopen("assets/map.txt","r")) == NULL){
        printf("Error: File tidak ada!\n");
        // Tutup program karena file gak ada.
        exit(1);
    }
    */
   /*

    // baca isi file dengan gets lalu simpan ke buff
    fgets(buff, 255, fptr);
    // tampilkan isi file
    printf("%s", buff);

    // tutup file
    fclose(fptr);
    */
}