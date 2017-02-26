// driver.c

#include "hash.h"

int main(int argc, char* argv[])
{
	long int input, size, minload, maxload, resizeFactor;
	
	SymbolList * symbolist = NULL;
	SymbolList * querylist = NULL;
	
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
				INIT_symbolist(symbolist, size);
				readSymbols(symbolist, size);
				break;

			case 1:
				scanf("%ld", &size);
				INIT_symbolist(querylist, size);
				readQueries(querylist, size);
				break;
			
			case 2:
				scanf("%ld %ld %ld %ld", &size, &minload, &maxload, &resizeFactor);
				createHashTable(htable, size, minload, maxload, resizeFactor);
				break;

			case 3:
				lookupQueries(htable, querylist);
				break;

			default:
				break;

		}
	} while(1);

	return 0;
}