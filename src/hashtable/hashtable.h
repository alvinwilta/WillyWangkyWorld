#include "../boolean.h"
#include <stdlib.h>

#define SIZE 20

struct DataItem {
   char * data;   
   int key;
};

struct DataItem* hashArray[SIZE]; 
struct DataItem* dummyItem;
struct DataItem* item;

void MakeEmptyHashTable();
int hashCode(int key);
struct DataItem *search(int key);
void insert(int key,char * data);
struct DataItem* delete(struct DataItem* item);
void display();