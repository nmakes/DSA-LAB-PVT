//linkedlist.c

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void traverse(list head)
{
	node *ptr = head->first;

	//start from the beginning
	while(ptr != NULL)
	{
		printf("%d\t", ptr->element);
		ptr = ptr->next;
	}
	printf("\n");
}

void insertInFront(list head, int ele)
{
	if (head->first == NULL)
	{
		node * temp = (node*) malloc(sizeof(node));
		temp -> element = ele;
		temp -> next = NULL;
		head -> first = temp;
		head -> count++;
	}
	else
	{
		node * temp = (node*) malloc(sizeof(node));
		temp -> element = ele;
		temp -> next = head->first;
		head -> first = temp;
		head -> count++;
	}

	traverse(head);
}

void insertAtEnd(list head, int ele)
{
	/*if(head==NULL)
	{
		head = (list) malloc(sizeof(linkedList));
		head->first=NULL;
		head->count=0;

		node * temp = (node*) malloc(sizeof(node));
		temp->element = ele;
		temp -> next = NULL;
		head->first = temp;
	}
	else */ // redundant code
	if (head->first == NULL)
	{
		node * temp = (node*) malloc(sizeof(node));
		temp -> element = ele;
		temp -> next = NULL;
		head -> first = temp;
		head -> count++;
	}
	else
	{
		node * mov = head->first;
		while(mov->next != NULL)
		{
			mov = mov->next;
		}
		node * temp = (node*) malloc(sizeof(node));
		temp -> element = ele;
		temp -> next = NULL;
		mov -> next = temp;
		head -> count++;
	}

	traverse(head);
}

void deleteFromFront(list head)
{
	if(head -> first == NULL)
	{
		printf("-2\n");
	}
	else
	{
		node * temp = head -> first;
		head -> first = head -> first -> next;
		printf("%d\n", temp->element);
		free(temp);
		head->count--;
	}
}

void deleteAtEnd(list head)
{
	if(head -> first == NULL)
	{
		printf("-2\n");
	}
	else if(head -> first -> next == NULL)
	{
		node * temp = head -> first;
		printf("%d", temp -> element);
		head -> first = NULL;
		free(temp);
		head->count--;
	}
	else
	{
		node * mov = head -> first;
		
		while(mov->next->next!=NULL)
		{
			mov = mov->next;
		}

		node * temp = mov -> next;
		mov -> next = NULL;
		printf("%d\n", temp->element);
		free(temp);
		head->count--;
	}
}

void silentInsertAtEnd(list head, int ele)
{
	/*if(head==NULL)
	{
		head = (list) malloc(sizeof(linkedList));
		head->first=NULL;
		head->count=0;

		node * temp = (node*) malloc(sizeof(node));
		temp->element = ele;
		temp -> next = NULL;
		head->first = temp;
	}
	else */ // redundant code
	if (head->first == NULL)
	{
		node * temp = (node*) malloc(sizeof(node));
		temp -> element = ele;
		temp -> next = NULL;
		head -> first = temp;
		head -> count++;
	}
	else
	{
		node * mov = head->first;
		while(mov->next != NULL)
		{
			mov = mov->next;
		}
		node * temp = (node*) malloc(sizeof(node));
		temp -> element = ele;
		temp -> next = NULL;
		mov -> next = temp;
		head -> count++;
	}
}