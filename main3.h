/*gcc src/mainphase.c src/mesinkata/mesinkata.c src/mesinkata/mesinkar.c src/mesinkata/mesintoken.c src/graph/graph.c src/matriks/matriks.c src/player/player.c src/queue/prioqueuechar.c src/stack/stack.c src/linkedlist/listlinier.c src/preparation.c src/graph/graph.c -o main main.c*/
#include "src/mesinkata/mesinkata.h"
#include "src/mesinkata/mesinkar.h"
#include "src/mesinkata/mesintoken.h"
#include "src/wahana/wahana.h"
#include "src/jam/jam.h"
#include "src/matriks/matriks.h"
#include "src/player/player.h"
#include "src/queue/queue.h"
#include "src/queue/prioqueuechar.h"
#include "src/stack/stack.h"
#include "src/array/array.h"
#include "src/point/point.h"
#include "src/tree/bintree.h"
#include "src/tree/listrek.h"
#include "src/boolean.h"
#include "src/preparation.h"
#include "src/mainphase.h"
#include "src/graph/graph.h"

void quit();
void main_menu();
void init(Player P1);
MATRIKS currMatriks (int currGraph);
void legenda(Player P1);
void game(Player P1);
void printPeta(Player P1, Graph G, int PosGraph, POINT PosAntrian, POINT PosOffice);
Wahana Build(Player *P, POINT pos, Stack S);
void UpgradeWahana(Player *P, Wahana *W, Stack S);
void Buy(Player *P, Stack S);
void deBuy(Player *P, int jenis, int N);
void legendPrep(Player P1, char name[20]);

void Undo(Player *P, Stack S);
void Execute(Stack S);
void KeMain(Player *P, Stack S);
void printPetaPrep(Player P1, Graph G, int PosGraph, POINT PosAntrian, POINT PosOffice);
void Preparation(Player P, char name[20], int currDay, Stack S);

void Office(Player P1, Wahana W1);
void legendMain(Player P1);
void PrintDetail(Wahana W1);
void Detail(Player P1, Wahana W1);
void Serve(int *ID);
void Prepare();
void Repair(Wahana *W, PrioQ *PQ1);
void GameOver();
void Antrian(PrioQ PQ1);
void kePrepare();