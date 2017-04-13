#include <stdio.h>
#include <stdlib.h>

#define MAXELEM 100

struct node 
{
	int element;
	struct node * next;
};

struct linkedList 
{
	int count;
	struct node * first;
};

void insert(struct linkedList* head, int ele, int pos)
{
	struct node* mov = head->first;

	int i=0;
	for(i=0; i<pos; i++)
	{
		mov = mov->next;
	}

}

void insertFirst(struct linkedList* head, int ele)
{
	//create a node
	struct node *link = (struct node*) malloc(sizeof(struct node));
	/* by this you are creating a node whose address is being stored in the link pointer. */
	link->element = ele;
	//point it to old first node
	link->next = head->first;
	//point first to new first node
	head -> first = link;
	head -> count++;
}

//delete first item
struct node* deleteFirst(struct linkedList * head)
{
	struct node* temp = head->first;
	head->first = head->first->next;
	head->count--;
	return temp;
	// free(temp);
	// ~NAV: alternatively free the memory
}

//display the list
void printList(struct linkedList * head)
{
	struct node *ptr = head->first;
	printf("\n[ ");
	
	//start from the beginning
	while(ptr != NULL)
	{
		printf("%d, ", ptr->element);
		ptr = ptr->next;
	}
	
	printf(" ]");
}

//search
int search (struct linkedList * head, int ele) // 0 if not found
{
	int i=0;
	struct node* mov = head->first;

	while(mov!=NULL)
	{
		if(mov->element==ele)
		{
			printf("FOUND at location %d", i);
			return 1;
		}
		mov = mov->next;
	}

	printf("NOT FOUND!");
	return 0;
}

 /*deletes the first node in the list that contains the element = ele and retuns it. If the element is not found it returns an error message saying element not found. */

struct node * delete (struct linkedList * head, int ele)
{
	node* mov = head->first;

	if(mov->element==ele)
	{
		node* temp = head->first;
		head->first = temp->next;
		head->count--;
		return temp;
	}
	else
	{
		while(mov->next!=NULL)
		{
			if(mov->next->element==ele)
			{
				node* temp = mov->next;
				mov->next = mov->next->next;
				head->count--;
				return temp;
			}
			mov = mov->next;
		}
	}
	
	return NULL;
}


// ---------------
// MERGE SORT ALGO
// ---------------

int a[MAXELEM];
int temp[MAXELEM];

void merge(int *a, int alo, int ahi, int *b, int blo, int bhi, int *dst, int dlo, int dhi)
{
	int i=0, j=0;

	while()
}

void mergeSortIntoTemp(int lo, int hi)
{
	if(lo>hi)
	{
		int mid = (lo+hi)/2;
		mergeSortIntoA(lo, mid);
		mergeSortIntoA(mid+1, hi);
		merge(a, lo, mid, a, mid+1, hi, temp, lo, hi);
	}
}

void mergeSortIntoA(int lo, int hi)
{
	if(lo>hi)
	{
		int mid = (lo+hi)/2;
		mergeSortIntoTemp(lo, mid);
		mergeSortIntoTemp(mid+1, hi);
		merge(Temp, lo, mid, Temp, mid+1, hi, a, lo, hi);
	}
}