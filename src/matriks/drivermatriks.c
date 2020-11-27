#include <stdio.h>
#include "../boolean.h"
#include "matriks.h"
#include "../player/player.h"

int main(){
    MATRIKS M1,M2,M3,M4;
    MakeMATRIKS(10,20,&M1);
    MakeMATRIKS(10,20,&M2);
    MakeMATRIKS(10,20,&M3);
    MakeMATRIKS(10,20,&M4);
    BacaMap(&M1,&M2,&M3,&M4);
    return 0;
}