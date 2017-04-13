// bitvector.c

#include "naivebitvector.h"


unsigned int jBit(unsigned int j)
{
	unsigned int t = 1;
	/*
	// multiply by 2
		int i=0;
		for(i=0; i<j; i++)
		{
			t = t*2;
		}
	*/


		// left shift by j

		t = t << j;

	return t;
}

unsigned int * CreateNaiveBitVector( unsigned int * S)
{
	S = (unsigned int *) malloc(intSize);
	* S = 0;
	// printf("%d", *S);
	return S;
}

void setNaive(unsigned int * S, int j)
{
	*S = (*S) | jBit(j);
	// printf("%d", *S);
}

unsigned int getNaive(unsigned int * S, int j)
{
	unsigned int t = ( (*S) & jBit(j) );
	if(t==0)
	{
		// printf("0\n");
		return 0;
	}
	else
	{
		// printf("1\n");
		return 1;
	}
}