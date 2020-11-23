#include <stdio.h>
#include "../boolean.h"
#include "matriks.c"
#include "../player/player.h"

int main(){
    MATRIKS M1;
    Player P;
    MakeMATRIKS(BrsMax+1, KolMax+1, &M1);
    printMap(M1, P);
}