#include "wahana/wahana.h"
#include "jam/jam.h"
#include "tree/bintree.h"
#include "matriks/matriks.h"
#include "tree/listrek.h"
#include "point/point.h"
#include "player/player.h"

Wahana Build(Player *P, POINT pos);
void Buy(Player *P);
void deBuy(Player *P, int jenis, int N);
void legendPrep(Player P1, int TotalAksi, int TotalDetikJam, int TotalUangPreparation);
void Preparation(Player P);
