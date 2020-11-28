#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

MATRIKS M1,M2,M3,M4;
Graph G;
POINT LokAntrian,LokOffice,PosPlayer;

int main () {
    MakeMATRIKS(10,20,&M1);
    MakeMATRIKS(10,20,&M2);
    MakeMATRIKS(10,20,&M3);
    MakeMATRIKS(10,20,&M4);
    G = initGraphMap(M1,M2,M3,M4);
    LokAntrian = MakePOINT(5,2);
    LokOffice = MakePOINT(8,2);
    PosPlayer = MakePOINT(2,2);
    addressNode CurrNode = FirstGraph(G);

}