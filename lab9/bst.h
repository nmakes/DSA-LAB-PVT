#include <stdio.h>
#include <stdlib.h>

#define lite return;

typedef struct _bst
{
	int val;
	struct _bst * parent;
	struct _bst * left;
	struct _bst * right;
} BST;

typedef struct _stack_node
{
	BST * root;
	struct _stack_node * next;
} stackNODE;

typedef struct _stack
{
	stackNODE * top;
	int count;
} STACK;


int * readData(int * array, int N);
BST * add(BST * root, int val);
BST * construct(BST * root, int * list, int size);
void inOrderTravRec(BST * root);
void inOrderTravIter(BST * root);
void findKthSmallest(BST * root, int k);
void findBetweenKeys(BST * root, int k1, int k2);

STACK * stackPush(STACK * st, BST * root);
BST * stackGetTop(STACK * st);
STACK * stackPop(STACK * st);
int isEmpty(STACK * st);