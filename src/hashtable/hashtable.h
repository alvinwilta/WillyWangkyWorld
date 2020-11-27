#include "../boolean.h"
#include <stdlib.h>

#define SIZE 20

struct DataItem {
   int data;   
   int key;
};

struct DataItem* hashArray[SIZE]; 
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key);
struct DataItem *search(int key);
void insert(int key,int data);
struct DataItem* delete(struct DataItem* item);
void display();