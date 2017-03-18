#include <stdio.h>
#include <stdlib.h>

#define intSize sizeof(unsigned int)

typedef struct _BitVector
{
	unsigned long int field;

} BitVector;

unsigned int jBit(unsigned int j);

unsigned int * CreateBitVector( unsigned int * S);

void set(unsigned int * S, int j);

unsigned int get(unsigned int * S, int j);