#include "hash.h"

int main()
{
	int input;
	int N;

	record * records;
	record * queries;

	hashTable * ht[8];

	do
	{
		scanf("%d", &input);

		switch(input)
		{
			case 1:
				scanf("%d", &N);
				readRecords(N, records, ht);
			break;

			case 2:
				scanf("%d", &N);
				readQueries(N, queries, ht);
			break;

			case 3:
			break;

			case 4:
			break;

			case -1:
				return 0;
		}

	}while(input!=-1);

	return 0;
}