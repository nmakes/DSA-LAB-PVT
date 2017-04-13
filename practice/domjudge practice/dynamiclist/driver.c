#include <stdio.h>
#include <stdlib.h>

int temp;

typedef struct Node
{
	int data;
	struct Node * next;
} node;

typedef struct List
{
	node * head;
	int count;
} list;

void traverse(list * l)
{
	node * mov = l->head;
	while(mov!=NULL)
	{
		printf("%d\t", mov->data);
		mov = mov->next;
	}
	printf("%d\n", -2);
}

void add(list * l, int n)
{
	node * addNode = (node*) malloc(sizeof(node));
	addNode->data = n;
	addNode->next = NULL;

	if(l->head==NULL)
	{
		l->head = addNode;
		l->count++;
	}
	else
	{
		node * mov = l->head;
		while(mov->next!=NULL)
		{
			mov = mov->next;
		}
		mov -> next = addNode;
		l->count++;
	}
}

void destroy(list * l)
{
	node * mov = l->head;

	if(mov==NULL)
	{
		printf("%d\n", -3);
		return;
	}
	else
	{
		do
		{
			node * next = mov->next;
			free(mov);
			mov = next;
		} while(mov!=NULL);
		l->head = NULL;
		traverse(l);
	}
}

list * create(list * l) // assume list is INIT
{
	int input;

	do
	{
		temp = scanf("%d", &input);
		if(input!=-1)
		{
			add(l, input);
		}
	} while(input!=-1);

	traverse(l);

	return l;
}

int main(int argc, char* argv[])
{
	int input;

	list * l = (list*)malloc(sizeof(list));
	l->head=NULL;
	l->count=0;

	do
	{
		temp = scanf("%d", &input);

		switch(input)
		{
			case 0:
			l = create(l);
			break;

			case 1:
			traverse(l);
			break;

			case 2:
			destroy(l);
			break;

			default:
			break;
		}

	} while(input!=-1);

	return 0;
}