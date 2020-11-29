/*gcc src/mesinkata/mesinkata.c src/mesinkata/mesinkar.c src/mesinkata/mesintoken.c src/graph/graph.c src/matriks/matriks.c src/player/player.c src/queue/prioqueuechar.c src/stack/stack.c src/linkedlist/listlinier.c src/preparation.c -o main main.c*/
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
#include "src/graph/graph.h"

void quit();
void main_menu();
void init(Player P1);
MATRIKS currMatriks (int currGraph);
void legenda(Player P1);
void printPeta(Player P1, Graph G, int PosGraph);
