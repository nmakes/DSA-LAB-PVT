// stack.h

#include "linkedlist.h"

struct STACK
{
	int count;
	node* top;
};

void push(struct STACK * stack, int ele);
struct node* pop(struct STACK * stack);
