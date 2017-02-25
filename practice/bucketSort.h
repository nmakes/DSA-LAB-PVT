#include <stdio.h>
#include <stdlib.h>

typedef struct DATA
{
	int x;
	int y;
	struct DATA * next;
} data;

typedef struct {
	data* head;
	int count;
} dataList;

dataList inp;

void add(dataList d1, int xval, int yval);
void del(dataList d1, int xval);
void search(dataList d1, int xval, int yval);
void printList(dataList d1);