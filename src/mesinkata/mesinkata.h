/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean.h"
#include "mesinkar.h"
#include "../graph/graph.h"
#include "../queue/queue.h"
#include "../array/arraydin.h"
#include "../matriks/matriks.h"


#define NMax 50
#define BLANK ' '
#define NEWLINE '\n'

typedef struct {
	char TabKata[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void IgnoreBlankSCANF();
int readAngka();
void readSCANF(Kata *input);
void readAngkaSCANF(int *X);

void STARTKATA();
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

boolean IsKataSama(Kata K1, char * S);
int intstring(Kata K);
void printKata(Kata K);
void readConfigFile(MATRIKS *M, buildingsArray *arr, graph *G, int * buildingCounter);
void saveToFile(MATRIKS *M, buildingsArray *arr, graph *G, int turn, boolean ignore, boolean critical, boolean extraTurn, queue *Q1, queue *Q2, boolean criticalP1, boolean criticalP2, boolean isShieldActiveP1, boolean shieldActivatedP1, boolean isShieldActiveP2, boolean shieldActivatedP2, int counterShieldP1, int counterShieldP2, int lengthFlagAttack, int lengthFlagMove, int * arrFlagAttack, int * arrFlagMove);
void readtxtMaterial(TabInt Material, )
#endif
