#include <stdio.h>
#include <stdlib.h>
#include "naivebitvector.h"
#include "intbitvector.h"

enum BFtype {naive, integer};

typedef struct _BloomFilter
{
	enum BFtype type; // 1 for 
	unsigned int * filter;
	int m;
	unsigned int sizeInBytes;

} BloomFilter;

unsigned int hash(unsigned int key, unsigned int N, int opt);

BloomFilter * CreateBloomFilter(BloomFilter * BF, int x, int n);

void insert(BloomFilter* BF, int V, unsigned int N, int L);

int find(BloomFilter * BF, int V, int L);

void clear(BloomFilter * BF);

void experiment(BloomFilter * BF, int K, int L, int N);

float FP (BloomFilter * BF)
{
	float val = pow()
}