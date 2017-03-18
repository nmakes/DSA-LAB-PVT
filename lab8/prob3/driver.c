#include "bloom.h"

int temp;

int main(int argc, char const *argv[])
{
	int input, x, n, v, k, l;
	BloomFilter * BF;

	do
	{
		temp = scanf("%d", &input);
		switch(input)
		{
			case 0:
			temp = scanf("%d %d", &x, &n);
			BF = CreateBloomFilter(BF, x, n);
			break;

			case 1:
			temp = scanf("%d", &v);
			insert(BF, v, n, 5);
			break;

			case 2:
			temp = scanf("%d", &v);
			find(BF, v, 5);
			break;

			case 3:
			clear(BF);
			break;

			case 4:
			temp = scanf("%d %d", &k, &l);
			experiment(BF, k, l, n);
			break;
		}
	} while(input!=-1);

	return 0;
}