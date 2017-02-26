// driver.c

#include "hash.h"

int main(int argc, char* argv[])
{
	long int input, size, minload, maxload, resizeFactor;
	
	symbol * symbolist = NULL;
	long int symbolist_size = 0;
	long int symbolist_maxSize = 0;

	symbol * querylist = NULL;
	long int querylist_size = 0;
	long int querylist_maxSize = 0;

	hashTable * htable = NULL;

	INIT_hashTable(htable, 0);

	do
	{
		scanf("%ld", &input);

		switch(input)
		{
			case -1:
				break;

			case 0:
				scanf("%ld", &size);
				INIT_symbolist(symbolist, &symbolist_size, &symbolist_maxSize, size);
				readSymbols(symbolist, size);
				break;

			case 1:
				scanf("%ld", &size);
				INIT_symbolist(querylist, &querylist_size, &querylist_maxSize, size);
				readQueries(querylist, size);
				break;
			
			case 2:
				scanf("%ld %ld %ld %ld", &size, &minload, &maxload, &resizeFactor);
				createHashTable(htable, size, minload, maxload, resizeFactor);
				break;

			case 3:
				lookupQueries(htable, querylist, querylist_size);
				break;

			default:
				break;

		}
	} while(1);

	return 0;
}