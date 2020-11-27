// #include "../include/mesin.h"
// #include "../include/mesinkar.h"

#include "mesinkata.h"
#include "mesinkar.h"
#include "mesintoken.h"
#include <stdio.h>
#include <string.h>
/*#include "../wahana/wahana.h"
#include "../matriks/matriks.h"
#include "../graph/graph.h"
#include "../queue/queue.h"
#include "../stack/stack.h"
#include "../array/array.h"
#include "../point/point.h"*/

int main()
{
    Kata K1,K2,K3;
    int N1,N2;
    readSCANF(&K1);
    printKata(K1);
    printf("%d\n",IsKataSama(K1,"sama"));
    readAngkaSCANF(&N1);
    readSCANF(&K3);
    printf("%d\n",N1);
    N2 = stringint(K3);
    printf("%d\n",N2);

    return 0;
}