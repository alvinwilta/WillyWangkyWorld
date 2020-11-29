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
#include "./player/player.h"
#include "./stack/stack.h"
#include "./mesinkata/mesinkata.h"
#include "./mesinkata/mesinkar.h"

extern MATRIKS M;
extern Player P1;
extern int menu1;
/*extern Kata name;*/
extern POINT PosPlayer;
extern int Money;
extern int currDay;

Wahana Build(Player *P, POINT pos, Stack S);
void UpgradeWahana(Player *P, Wahana *W, Stack S);
void Buy(Player *P, Stack S);
void deBuy(Player *P, int jenis, int N);
void legendPrep(Player P1, Kata name);
void Preparation(Player P, Kata name, int currDay, Stack S);

void Undo(Player P, Kata name, int currDay, Stack S);
#endif
