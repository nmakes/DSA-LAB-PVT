#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int temp, curHeapSize = 0, maxHeapSize = 0;

void * myMalloc(unsigned int size)
{
	curHeapSize++;
	if(curHeapSize>maxHeapSize)
	{
		maxHeapSize = curHeapSize;
	}
	return malloc(size);
}

void myFree(void * ptr)
{
	curHeapSize--;
	free(ptr);
}

typedef struct Node
{
	int data;
	struct Node * next;
} node;

typedef struct List
{
	node * first; // insert at first
	node * last; // delete at last
	int count;
} list;

void traverse(list * l)
{
	node * mov = l->first;
	while(mov!=NULL)
	{
		printf("%d\t", mov->data);
		mov = mov->next;
	}
	printf("%d\n", -2);
}

void add(list * l, int n)
{
	node * addNode = (node*) myMalloc(sizeof(node));
	addNode->data = n;
	addNode->next = NULL;

	if(l->first==NULL)
	{
		l->first = addNode;
		l->last = addNode;
		l->count++;
	}
	else
	{
		addNode -> next = l->first;
		l->first = addNode;
		l->count++;
	}
}

void create(list * l)
{
	int inp;

	temp = scanf("%d", &inp);

	int i;

	for (i=0; i<)
}

int main(int argc, char* argv[])
{
	int input; int nextinp;

	list * l = (list*)myMalloc(sizeof(list));
	l->first=NULL;
	l->last=NULL;
	l->count=0;

	do
	{
		temp = scanf("%d", &input);

		switch(input)
		{
			case 0:
			temp = scanf("%d", &nextinp);
			create(l);
		}

	} while(input!=-1);

	return 0;
}