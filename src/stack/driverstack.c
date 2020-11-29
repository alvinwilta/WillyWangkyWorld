#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    Stack S1;
    CreateEmpty(&S1);
    Push(&S1, 3);
    Push(&S1, 3);
    printf("%d",IsEmptyStack(S1));
    printf("%d",InfoTop(S1));
}