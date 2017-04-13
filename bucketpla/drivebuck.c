#include "bucketsort.h"
#include<stdlib.h>

int main(int argc, int* argv[])
{int points[100][2];
int c,lox,loy,hix,hiy,m;
FILE* fptr=stdin;
fscanf(fptr,"%d",&c);
while(!feof(fptr))
{
switch(c)
	{
	case 0:
	fscanf(fptr,"%d",&m);
	fscanf(fptr,"%d",&lox);
	fscanf(fptr,"%d",&hix);
	fscanf(fptr,"%d",&loy);
	fscanf(fptr,"%d",&hiy);
	readdata(points,m,lox,hix,loy,hiy,fptr);
	break;
	
	case 1:
	SortSparseLists(points,m);
	break;
	}
	fscanf(fptr,"%d",&c);
	}
	
	}
	

