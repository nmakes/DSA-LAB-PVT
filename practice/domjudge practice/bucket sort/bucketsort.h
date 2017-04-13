#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int x;
	int y;
	struct node *next;
} NODE;

typedef struct linkedList
{
	int count;
	NODE* first;
} LIST;


void readdata(int points[][2],int M,int xlo,int xhi,int ylo, int yhi,FILE* fptr);
void SortSparseLists(int points[][2],int M);
void getpoint(Bucket b[],int pt[][2]);
void insert(Bucket b,int x,int y);