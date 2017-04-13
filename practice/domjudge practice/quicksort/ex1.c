/*

qs(ls,lo,hi) 
{ 
	if (lo<hi) 
	{ 
		p=part(Ls,lo,hi,pivot(Ls,lo,hi)); 
		qs(ls,lo,p-1); 
		qs(ls,p+1,hi); 
	} 
}

*/

#include "data.h"

int pivot(data Ls[], int lo, int hi)
{
	return hi;
}

int part(data Ls[], int lo, int hi, int piv)
{
	
}

int quickSort(data Ls[], int lo, int hi)
{
	if (lo<hi) 
	{ 
		int p=part(Ls,lo,hi,pivot(Ls,lo,hi)); 
		quickSort(Ls,lo,p-1); 
		quickSort(Ls,p+1,hi); 
	} 
}