#include "bloom.h"

unsigned int hash(unsigned int key, unsigned int N, int opt)
{
	int A, B;

	switch(opt)
	{
		case 1:
		A = 7;
		B = 11;
		break;

		case 2:
		A = 11;
		B = 13;
		break;

		case 3:
		A = 13;
		B = 17;
		break;

		case 4:
		A = 17;
		B = 19;
		break;

		case 5:
		A = 19;
		B = 23;
		break;
	}

	return (A * key + B)%N ;
}

BloomFilter * CreateBloomFilter(BloomFilter * BF, int x, int n)
{
	BF = (BloomFilter*) malloc(sizeof(BloomFilter));
	BF->filter = NULL;
	BF->m = 0;

	if(x==1)
	{
		BF->type = naive;
		BF->filter = CreateNaiveBitVector(BF->filter);
		BF->sizeInBytes = sizeof(unsigned int);
	}
	else if(x==2)
	{
		BF->type = integer;
		BF->filter = CreateIntBitVector(BF->filter, n);
		BF->sizeInBytes = sizeof(unsigned int) * n;
		BF->m++;
	}
}

void insert(BloomFilter* BF, int V, unsigned int N, int L)
{
	int i=1, insflag=1;

	if(BF->type == integer)
	{
		for(i=1; i<=L; i++)
		{
			if(getInt(BF->filter), hash(V,N,i) != 1)
			{
				setInt(BF->filter, hash(V, N, i));
			}
			else
			{
				insflag = 0;
			}
		}
		if(insflag==1)
		{
			BF->m++;
		}
	}
	else if(BF->type == naive)
	{
		for(i=1; i<=L; i++)
		{
			setNaive(BF->filter, hash(V, N, i));
		}
	}
}

int find(BloomFilter * BF, int V, int L)
{
	int flag = 1;

	int i=1;

	if(BF->type == integer)
	{
		for(i=1; i<=L; i++)
		{
			if( getInt(BF->filter, hash(V, BF->sizeInBytes/4, i)) == 0)
			{
				flag = 0;
				break;
			}
		}
	}
	else if(BF->type == naive)
	{
		for(i=1; i<=L; i++)
		{
			if( getNaive(BF->filter, hash(V, 32, i)) == 0)
			{
				flag = 0;
				break;
			}
		}
	}


	if(flag ==0) 
	{
		printf("0\n");
	}
	else 
	{
		printf("1\n");
	}

	return flag;
}

void clear(BloomFilter * BF)
{
	if(BF->type == naive)
	{
		* (BF->filter) = 0;
	}
	else
	{
		unsigned int * temp = BF->filter;
		free(temp);
		BF = CreateBloomFilter(BF, BF->type + 1, BF->sizeInBytes / sizeof(unsigned int));
	}
}

void experiment(BloomFilter * BF, int K, int L, int N)
{
	int i = 1;

	int opt, temp, v;

	for(i=1; i<=K; i++)
	{
		temp = scanf("%d %d", &opt, &v);
		switch(opt)
		{
			case 1:
			insert(BF, v, N, L);
			break;

			case 2:
			find(BF, v, L);
			break;
		}
	}
}