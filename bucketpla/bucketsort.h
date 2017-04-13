#include <stdio.h>
#include <stdlib.h>

struct node{
int x;
int y;
struct node *next;
};
typedef struct node* point;

struct linkedList
{
int count ;
struct node *first;
};
typedef struct linkedList* Bucket;


void readdata(int points[][2],int M,int xlo,int xhi,int ylo, int yhi,FILE* fptr);
void SortSparseLists(int points[][2],int M);
void getpoint(Bucket b[],int pt[][2]);
void insert(Bucket b,int x,int y);



