#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../boolean.h"
#include "hashtable.h"

int main() {
    MakeEmptyHashTable();
    insert(1, "Wahana");
    insert(2, "Wahana 1");
    insert(42, "Wahana 2");
    insert(4, "Wahana 3");
    insert(12, "Wahana 4");
    insert(14, "Wahana 5");
    insert(17, "Wahana 6");
    insert(13, "Wahana 7");
    insert(37, "Wahana 8");

    display();
    item = search(37);

    if(item != NULL) {
        printf("Element found: %s\n", item->data);
    } else {
        printf("Element not found\n");
    }

    delete(item);
    item = search(37);

    if(item != NULL) {
        printf("Element found: %s\n", item->data);
    } else {
        printf("Element not found\n");
    }
    return 0;
}