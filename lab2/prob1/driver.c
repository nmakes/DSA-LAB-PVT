// driver.c

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

	list LL = (list) malloc(sizeof(linkedList));
	
	FILE * fin = stdin;

	int input;

	while(!feof(fin))
	{
		fscanf(fin, "%d", &input);

		if(input==4)
		{
			traverse(LL);
		}
		else if(input==3)
		{
			deleteAtEnd(LL);
		}
		else if(input==2)
		{
			deleteFromFront(LL);
		}
		else if(input==1)
		{
			fscanf(fin, "%d", &input);
			insertAtEnd(LL, input);
		}
		else if(input==0)
		{
			fscanf(fin, "%d", &input);
			insertInFront(LL, input);
		}
		else if(input == -1)
		{
			break;
		}
	}

	fclose(fin);

	return(0);
}