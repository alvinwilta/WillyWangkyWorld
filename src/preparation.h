#ifndef preparation_H
#define preparation_H
#define Nil NULL

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./wahana/wahana.h"
#include "./jam/jam.h"
#include "./tree/bintree.h"
#include "./matriks/matriks.h"
#include "./tree/listrek.h"
#include "./point/point.h"
#include "./stack/stack.h"
#include "./player/player.h"
#include "boolean.h"

extern MATRIKS M;
extern Player P1;
extern int menu1;
extern Kata name;
extern POINT PosPlayer;
extern int Money;
extern int currDay;

Wahana Build(Player *P, POINT pos);

void Buy(Player *P);

void deBuy(Player *P, int jenis, int N);
void UpgradeWahana(Player *P, Wahana *W);

void legendPrep(Player P1, int TotalAksi, int TotalDetikJam, int TotalUangPreparation);
void Preparation(Player P);

void Undo(Wahana W);
#endif
