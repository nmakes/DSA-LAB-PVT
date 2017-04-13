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

void printList(int A[], int s, int e)
{
	int i = s;
	for(i=s; i<=e; i++)
	{
		printf("%d\t", A[i]);
	}
}

int pivot(int Ls[], int lo, int hi)
{
	return hi;
}

int stringLength(char a[])
{
	int i=0;
	int c=0;
	while(a[i]!='\0')
	{
		c++;
	}
	return c;
}

void stringCopy(char * a, char * b)
{
	int i=0;
	for(i=0; b[i]!='\0'; i++)
	{
		a[i] = b[i];
	}
	a[i] = '\0';
}

void swap(int * Ls, int f, int s)
{
	data temp;

	/*stringCopy(temp.name, Ls[f].name);
	temp.marks1 = Ls[f].marks1;
	temp.marks2 = Ls[f].marks2;

	stringCopy(Ls[f].name, Ls[s].name);
	Ls[f].marks1 = Ls[s].marks1;
	Ls[f].marks2 = Ls[s].marks2;

	stringCopy(Ls[s].name, Ls[s].name);
	Ls[s].marks1 = Ls[s].marks1;
	Ls[s].marks2 = Ls[s].marks2;*/

	int c = Ls[f];
	Ls[f] = Ls[s];
	Ls[s] = c;
}
/*
3 5 7 8 7 4 15 14 9*/

int part(int * Ls, int lo, int hi, int piv) // piv is last element
{
	int left = lo;
	int right = hi-1;
	int pPos;
	while ( left < right )
	{
		while( left < hi && Ls[left] <= Ls[piv])
		{
			left++;
		}

		while(Ls[right] > Ls[piv])
		{
			right--;
		}

		if(left<right)
		{
			swap(Ls, left, right);
			left++;
			right--;
		}
		/*else if(right <= left)
		{
			swap(Ls, right+1, piv);
			return right+1;
		}*/
	}
	
	if(Ls[right] > Ls[piv])
	{
		pPos = right;
	}
	else
	{
		pPos = right+1;
	}

	swap(Ls, piv, pPos);

	return pPos;
}

int quickSort(int Ls[], int lo, int hi)
{
	if (lo<hi)
	{
		int p = part(Ls,lo,hi,pivot(Ls,lo,hi));
		quickSort(Ls,lo,p-1);
		quickSort(Ls,p+1,hi);
	}
}

int partialQuickSort(int Ls[], int lo , int hi, int L, int size)
{
	if ( (lo<hi) && (hi-lo+1<L) )
	{
		int p = part(Ls,lo,hi,pivot(Ls,lo,hi));
		partialQuickSort(Ls,lo,p-1,L);
		partialQuickSort(Ls,p+1,hi,L);
	}
	else if(hi-lo+1<L)
	{
		printList(Ls, 0, size-1);
		return 0;
	}
}

int main(int argc, char* argv[])
{
	int a[10] = {1,0,2,6,3,7,4,7,5,6};
	quickSort(a, 0, 9);
	printList(a, 0, 9);

	return 0;
}