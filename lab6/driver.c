// driver.c

#include "hash.h"

int main(int argc, char* argv[])
{
	long int input, size, minload, maxload, resizeFactor;

	char inputstr[100];

	SymbolList symbolist;
	SymbolList querylist;
	
	hashTable htable;

	INIT_hashTable(&htable, 0);

	
	/*

	// extracts test cases -- I'M SAVING THEM FOR PRACTICE AT HOME

	do
	{
		scanf("%s", inputstr);
		printf(inputstr);
	} while(input[0]!='-' && input[1]!='1');

	*/


	do
	{
		scanf("%ld", &input);

		switch(input)
		{
			case -1:
				return 0;
				break;

			case 0:
				scanf("%ld", &size);
				readSymbols(&symbolist, size);
				break;

			case 1:
				scanf("%ld", &size);
				readQueries(&querylist, size);
				break;
			
			case 2:
				scanf("%ld %ld %ld %ld", &size, &minload, &maxload, &resizeFactor);
				createHashTable(&htable, &symbolist, size, minload, maxload, resizeFactor);
				break;

			case 3:
				lookupQueries(&htable, &querylist);
				break;

			default:
				break;
		}
	} while(input != -1);

	return 0;
}