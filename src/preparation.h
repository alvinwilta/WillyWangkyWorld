#ifndef _PREPARATION_H
#define _PREPARATION_H
#define Nil NULL

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "wahana/wahana.h"
#include "jam/jam.h"
#include "tree/bintree.h"
#include "matriks/matriks.h"
#include "tree/listrek.h"
#include "point/point.h"
#include "player/player.h"
#include "stack/stack.h"
#include "mesinkata/mesinkata.h"
#include "mesinkata/mesinkar.h"
#include "graph/graph.h"


extern int TotalUangPreparation;
extern int TotalAksi;
extern long TotalDetikJam;
extern int TotalWahana;
extern char ListNamaWahana[20][30];

extern Wahana ListWahana[];
extern Graph G;
extern int PosGraph;
extern BinTree WahanaUpgrade;
extern POINT PosAntrian,PosOffice;

Wahana Build(Player *P, POINT pos, Stack S);
void UpgradeWahana(Player *P, Wahana *W, Stack S);
void Buy(Player *P, Stack S);
void deBuy(Player *P, int jenis, int N);
void legendPrep(Player P1, char name[]);

void Undo(Player *P, Stack S);
void Execute(Stack S);
void KeMain(Player *P, Stack S);
void printPetaPrep(Player P1, Graph G, int PosGraph, POINT PosAntrian, POINT PosOffice);
void Preparation(Player P, char name[], int currDay, Stack S);
void CekKanan(Player *P, Graph *G, int PosGraph, POINT PosAntrian, POINT PosOffice);
void CekKiri(Player *P, Graph *G, int PosGraph, POINT PosAntrian, POINT PosOffice);
void CekMaju(Player *P, Graph *G, int PosGraph, POINT PosAntrian, POINT PosOffice);
void CekMundur(Player *P, Graph *G, int PosGraph, POINT PosAntrian, POINT PosOffice);
#endif
