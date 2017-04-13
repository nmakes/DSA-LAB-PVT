// driver.c
#include <stdio.h>

#define INIT_STACK int bot = 0;
#define STR_STACK int v = 0;
#define CALC_STACK

void print(int *a, int lo, int hi)
{
	int i;
	printf("\nLIST(%d,%d): ", lo, hi);
	for (i=lo; i<=hi; i++)
	{
		printf("%d\t", a[i]);
	}
}

void swap(int * a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int pivot(int * a, int lo, int hi)
{
	return hi;
}

int partition(int *a, int lo, int hi, int piv)
{
	int i, j;
	i=lo-1;
	for(j=lo; j<piv; j++)
	{
		if(a[j]<=a[piv])
		{
			i++;
			swap(a,j,i);
		}
	}
	swap(a,i+1,piv);
	return i+1;
}

int quicksort(int *a, int lo, int hi)
{

	if(lo < hi)
	{
		int piv = partition(a, lo, hi, hi);
		quicksort(a, lo, piv-1);
		quicksort(a, piv+1, hi);
	}
}

int main(int argc, char* argv[])
{
	int a[6] = {6,5,32, -9,2,1};
	// print(a, 0, 5);
	quicksort(a, 0, 5);
	print(a, 0, 5);
}