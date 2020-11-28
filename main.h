/*gcc src/mesinkata/mesinkata.c src/mesinkata/mesinkar.c src/mesinkata/mesintoken.c src/matriks/matriks.c src/player/player.c -o main main.c*/
#include "src/mesinkata/mesinkata.h"
#include "src/mesinkata/mesinkar.h"
#include "src/mesinkata/mesintoken.h"
#include "src/wahana/wahana.h"
#include "src/jam/jam.h"
#include "src/matriks/matriks.h"
#include "src/player/player.h"
#include "src/queue/queue.h"
#include "src/stack/stack.h"
#include "src/array/array.h"
#include "src/point/point.h"
#include "src/boolean.h"

void quit();
void main_menu();
void init(Player P1);
void awal(Player P1);
void game(Player P1);
