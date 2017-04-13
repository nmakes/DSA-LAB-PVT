// bitvector.c

#include "bitvector.h"

unsigned int * CreateBitVector( unsigned int * S, int N)
{
	S = (unsigned int *) malloc( intSize * N );
	int i=0;
	for(i=0; i<N; i++)
	{
		S[i] = 0;
	}
	// printf("%d", *S);
	return S;
}

void set(unsigned int * S, int j)
{
	S[j] = 1;
	// printf("%d", *S);
}

unsigned int get(unsigned int * S, int j)
{
	printf("%d\n", S[j]);
	return S[j];
}