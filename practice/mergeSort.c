#include "mergeSort.h"
#include "execTime.h"

void merge(var * A, var sa, var ea, 
			var * B, var sb, var eb, 
			var * C, var sc, var ec)
{
	var lp = sa;
	var rp = sb;
	var dp = sc;
	
	if(sa <= ea && sb <= eb)
	{
		if(A[sa]<B[sb])
		{
			C[sc] = A[sa];
			merge(A, sa+1, ea, B, sb, eb, C, sc+1, ec);
		}
		else if(A[sa]>B[sb])
		{
			C[sc] = B[sb];
			merge(A, sa, ea, B, sb+1, eb, C, sc+1, ec);
		}
		else
		{
			C[sc] = A[sa];
			C[sc+1] = B[sb];
			merge(A, sa+1, ea, B, sb+1, eb, C, sc+2, ec);
		}
	}
	else if(sa>ea)
	{
		if(sb<=eb)
		{
			var c=sc;
			var b=sb;
			for(; c<=ec && b<=eb;)
			{
				C[c] = B[b];
				c++;
				b++;
			}

		}
	}
	else if(sb>eb)
	{
		if(sa<=ea)
		{
			var c=sc;
			var a=sa;
			for(; c<=ec && a<=ea;)
			{
				C[c] = A[a];
				c++;
				a++;
			}
		}
	}
	else if(sa > ea && sb > eb)
	{
		return;
	}
}

var c[10];

void naiveMergeSort(var * A, var sa, var ea)
{
	if(sa>=ea)
	{
		return;
	}
	else
	{
		var mid = (ea + sa)/2;
		naiveMergeSort(A, sa, mid);
		naiveMergeSort(A, mid+1, ea);
		// var * C = (var*) malloc(sizeof(var)*(ea-sa+1)); --> Version 1: Created dynamic array
		// Version 2: will use global array to improve speed
		merge(A, sa, mid, A, mid+1, ea, c, sa, ea);
		
		var i;
		for(i=0; i<=ea-sa; i++)
		{
			A[sa+i] = c[sa+i];
		}
	}
}

void inPlaceMergeSort(var *A, var sa, var ea)
{
	if(sa>=ea)
	{
		return;
	}
	else
	{
		var mid = (sa+ea)/2;
		inPlaceMergeSort(A, sa, mid);
		inPlaceMergeSort(A, mid+1, ea);
		var l = sa;
		var r = mid+1;
		var j;

		for(r = mid+1; r<=ea; r++)
		{
			var temp = A[r];
			j = r-1;
			while(j>=0 && temp<=A[j])
			{
				A[j+1] = A[j];
				j--;
			}
			A[j+1] = temp;
		}
	}
}

void printList(var A[], var s, var e)
{
	var i = s;
	for(i=s; i<=e; i++)
	{
		printf("%ld\t", A[i]);
	}
}

int main(int argc, char* argv[])
{
	var A[] = {1,2,73,41,91,5,19, 87, 7, 2};

	RECORD_TIME;

	inPlaceMergeSort(A, 0,9);

	STOP_TIME;
	CALC_TIME;

	printList(A, 0, 9);

	printf("\n\n%lf", time_taken);
}