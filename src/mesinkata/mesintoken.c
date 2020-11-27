/*
Nama: Leonard Matheus
NIM: 13519215
Tanggal: 1 Oktober 2020
Deskripsi: Mesin Kata
*/

#include "../boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "mesintoken.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define NMax 50
#define BLANK ' '


/* State Mesin Kata */
boolean EndToken;
Token CToken;

/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
    
void STARTTOKEN(){
    EndToken = false;
    START();
    ADVTOKEN();
}
/* I.S. : CC sembarang
   F.S. : EndToken = true, dan CC = MARK;
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */
    
void ADVTOKEN(){
    IgnoreBlank();
    if (CC == MARK) {
        EndToken= true;
    }else{
        SalinToken();
    }
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true
   Proses : Akuisisi kata menggunakan procedure SalinKata */
   

void SalinToken(){
    int i = 1;
    CToken.val = 0;

    do{
        if ((CC != '+') && (CC != '-') && (CC != '*') && (CC != '/') && (CC != '^')){

            switch (CC){
                case '1' : CToken.val = CToken.val*10 + 1;break;
                case '2' : CToken.val = CToken.val*10 + 2;break;
                case '3' : CToken.val = CToken.val*10 + 3;break;
                case '4' : CToken.val = CToken.val*10 + 4;break;
                case '5' : CToken.val = CToken.val*10 + 5;break;
                case '6' : CToken.val = CToken.val*10 + 6;break;
                case '7' : CToken.val = CToken.val*10 + 7;break;
                case '8' : CToken.val = CToken.val*10 + 8;break;
                case '9' : CToken.val = CToken.val*10 + 9;break;
                default : CToken.val = CToken.val*10 + 0;break;
            }
            CToken.tkn = 'b';
        }

        else {
            CToken.tkn = CC;
            CToken.val = -1;
        }
        ADV();
        i++;


    }while ((CC != BLANK) && (CC != MARK) && (i <= NMax));
    IgnoreBlank();
}
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

Token readTokenSCANF(Kata K1)
{
    Token T1;
    char newString[10][10]; 
    int i,j,ctr;
    j=0; ctr=0;
    for(i=0;i<=K1.Length;i++)
    {
        // if space or NULL found, assign NULL into newString[ctr]
        if(K1.TabKata[i]==' ')
        {
            newString[ctr][j]='\0';
            ctr++;  //for next word
            j=0;    //for next word, init index to 0
        }
        else
        {
            newString[ctr][j]=K1.TabKata[i];
            j++;
        }
    }
    T1.val = atoi(newString[0]);
    T1.tkn = newString[1][0];
    return T1;
}
