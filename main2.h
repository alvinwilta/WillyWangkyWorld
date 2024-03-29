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
#include "src/boolean.h"

void quit();
void main_menu();
void init(Player P1);
void updateMap(Player P1);
MATRIKS currMatriks (int currGraph);
void legenda(Player P1);
void game(Player P1);