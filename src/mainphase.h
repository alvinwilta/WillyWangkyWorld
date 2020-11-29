/*gcc mesinkata/mesinkata.c mesinkata/mesinkar.c mesinkata/mesintoken.c matriks/matriks.c player/player.c queue/prioqueuechar.c queue/queue.c stack/stack.c linkedlist/listlinier.c preparation.c wahana/wahana.c jam/jam.c tree/bintree.c tree/listrek.c -o mainphase mainphase.c*/
#include "wahana/wahana.h"
#include "jam/jam.h"
#include "tree/bintree.h"
#include "matriks/matriks.h"
#include "tree/listrek.h"
#include "point/point.h"
#include "graph/graph.h"
#include "player/player.h"
#include "queue/queue.h"
#include "queue/prioqueuechar.h"
#include "preparation.h"

extern POINT PosOffice;

void Office(Player P, Wahana ListWahana[]);
void legendMain(Player P1);
void PrintDetail(Wahana ListWahana[], int i);
void Detail(Player P1, Wahana W[]);
void Serve(int *ID);
void Prepare();
void Repair(Wahana *W, PrioQ *PQ1);
void GameOver();
void Antrian(PrioQ PQ1);
void kePrepare();
