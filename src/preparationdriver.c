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
#include "preparation.h"

int main()
{
    JAM J;
    Hour(J) = 8;
    Minute(J) = 30;
    Second(J) = 0;
    POINT A;
    Absis(A) = 1;
    Ordinat(A) = 3;
    Player P = NewPlayer(A, J, 400);
    char name[20];
    int currDay = 1;
    Stack S;
    CreateEmpty(&S);
    Preparation(P, name, currDay, S);
    return 0;
}