#include <stdio.h>
#include "mesinkar.h"
#include "mesinkata.h"
#include "../boolean.h"
#include <string.h>
#include "../array/array.h"
/*
#include "../wahana/wahana.h"
#include "../graph/graph.h"
*/
boolean EndKata;
Kata CKata;

static char configFilename[] = "config.conf";
static char savefileFilename[] = "savefile.dat";
static char saveMaterial[] = "../assets/material.txt";

static FILE * savefile;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC != EOF && (CC==BLANK  || CC == NEWLINE)){
        ADV();
    }
}

void IgnoreBlankSCANF()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC != EOF && (CC==BLANK)){
        ADVSCANF();
    }
}

/*Berguna untuk membaca angka dari File
    I.S. : Angka Sembarang
    F.S. : CC ≠ BLANK atau CC = NEWLINE*/
int readAngka(){
    int n = 0;
    IgnoreBlank();
    while (!EOP && CC != EOF && CC != BLANK && CC != NEWLINE) {
        n = n*10 + (CC-'0');
        ADV();
    }
    return n;
}

void readSCANF(Kata *input)
{
    STARTSCANF();
    IgnoreBlankSCANF();
    (*input).Length = 0;

    while((!EOP) && (CC!=NEWLINE))
    {
        (*input).TabKata[(*input).Length] = CC;
        ++(*input).Length;
        ADVSCANF();
    }
}

void readAngkaSCANF(int *X)
{
    int tmp;
    STARTSCANF();
    *X = 0;
    while(!EOP && CC!=NEWLINE)
    {
        tmp = CC - '0';
        *X = (*X)*10 + tmp; 
        ADVSCANF(); 
    }
}

void STARTKATA(){
    START();
    IgnoreBlank();
    if (CC==MARK){
        EndKata = true;
    }else{
        EndKata = false;
        SalinKata();
    }
}
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA(){
    IgnoreBlank();
    if(CC==MARK){
        EndKata = true;
    }else{
        SalinKata();
        IgnoreBlank();
    }
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata(){
    int i = 0;
    IgnoreBlank();
    while ((CC!=MARK)&&(CC!=BLANK)){
        if (i<NMax){
            CKata.TabKata[i] = CC;
        }
        i++;
        ADV();
    }
    if (i<=NMax){
        CKata.Length = i;
    }else{
        CKata.Length=NMax;
    }
}
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

boolean IsKataSama(Kata K1, char * S){
    boolean found = true;
    int pjg = K1.Length; 
    int i;
    if (pjg != strlen(S)){
        found = false;
    }else{
        i = 0;
        while ((i < pjg) && (found)){
            if (K1.TabKata[i] != S[i]){
                found = false;
            }else{
                i++;
            }
        }
    }
    return found;
}

/* Konversi dari integer ke string
    I.S. Integer dimasukkan sembarang
    F.S. Menghasilkan string*/
int stringint(Kata K){
    int result = 0;
    int temp;
    for(int i = 0; i < K.Length; i++){
        temp = (int) K.TabKata[i] - '0';
        result = result * 10 + temp;
    }
    return result;
}

void printKata(Kata K)
{
    for(int i=0;i<K.Length;i++) printf("%c",K.TabKata[i]);
    printf("\n");
}
