#include <stdio.h>
#include <stdlib.h>

#define intSize sizeof(unsigned int)

typedef struct _BitVector
{
	unsigned long int field;

} BitVector;

unsigned int jBit(unsigned int j);

unsigned int * CreateNaiveBitVector( unsigned int * S);

void setNaive(unsigned int * S, int j);

unsigned int getNaive(unsigned int * S, int j);