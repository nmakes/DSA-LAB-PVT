#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	// CREATING LIST

	list LL = (list) malloc(sizeof(linkedList));

	LL->count=0;
	LL->first=NULL;
	
	FILE * fin = stdin;

	int cycleflag = 0;

	int n, d;

	while(!feof(fin))
	{
		fscanf(fin, "%d%d",&n,&d);

	// HACK TO VIEW THE TEST CASES
	//		printf("%d\t%d\n", n,d);

		if(n<0)
		{
			break;
		}
		else if(n<LL->count)
		{
			// cycle counter code
			cycleflag=1;
			printf("%d", LL->count - n + 1);
			return 0;
		}
		else
		{
			cycleflag=0;
			silentInsertAtEnd(LL, d);
		}
	}
	
	// APPLYING HARE AND TORTOISE ALGO

	/*node * hare, * tortoise;
 
	hare = tortoise = LL -> first;

	while(hare->next!=tortoise)
	{
		if(hare==NULL || hare->next==NULL || hare->next->next==NULL)
		{
			//printf("\nNO CYCLE DETECTED\n");
			cycleflag=0;
		}
		else if(tortoise==NULL || tortoise->next==NULL)
		{
			//printf("\nNO CYCLE DETECTED\n");
			cycleflag=0;
		}
		else if(hare->next==tortoise)
		{
			cycleflag=1;
			//printf("\nCYCLE DETECTED\n");
		}

		hare = hare->next->next;
		tortoise = tortoise->next;

		if(hare->next==tortoise)
		{
			//printf("\nCYCLE DETECTED\n");
			cycleflag=1;
		}
	}*/

	if(cycleflag==0)
	{
		printf("0");
	}

	return 0;
}