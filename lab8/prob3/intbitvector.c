// bitvector.c

#include "intbitvector.h"

unsigned int * CreateIntBitVector( unsigned int * S, int N)
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

void setInt(unsigned int * S, int j)
{
	S[j] = 1;
	// printf("%d", *S);
}

unsigned int getInt(unsigned int * S, int j)
{
	// printf("%d\n", S[j]);
	return S[j];
}