#include <stdio.h>
#include <stdlib.h>
#include "graph.h"



int main () {
    MATRIKS M1,M2,M3,M4;
    Graph G;
    POINT LokAntrian,LokOffice,PosPlayer;
    MakeMATRIKS(10,20,&M1);
    MakeMATRIKS(10,20,&M2);
    MakeMATRIKS(10,20,&M3);
    MakeMATRIKS(10,20,&M4);
    ElmtM(M2,2,2) = 2;
    ElmtM(M3,2,2) = 3;
    ElmtM(M4,2,2) = 4;
    CreateEmptyGraph(&G);
    initGraphMap(&G,M1,M2,M3,M4);
    TulisMATRIKS(MatriksGraph(searchNodeId(&G,2)));
    // LokAntrian = MakePOINT(5,2);
    // LokOffice = MakePOINT(8,2);
    // PosPlayer = MakePOINT(2,2);
    int A;
    scanf("%d", &A);
    return 0;
}