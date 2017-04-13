#include <stdio.h>
#include <stdlib.h>

#define intSize sizeof(unsigned int)

unsigned int * CreateBitVector( unsigned int * S, int N);

void set(unsigned int * S, int j);

unsigned int get(unsigned int * S, int j);