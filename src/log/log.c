#include <stdio.h>
#include "boolean.h"
#include "log.h"

int main(){
    Log log1;
    scanf("%c",&state(log1));
    scanf("%f %f",&posisi(log1));
    scanf("%c",&nama(log1));

    printf("%c",state(log1));
    printf("%f %f",posisi(log1));
    printf("%c",nama(log1));

    return 0;
}