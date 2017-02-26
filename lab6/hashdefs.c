#include "hash.h"

symbol* INIT_symbolist(symbol * list, long int * size, long int * max_size, long int M)
{
	if(list!=NULL) free(list);

	*max_size = M;
	list = (symbol *) malloc(sizeof(symbol)*M);
	*size = 0;

	return list;
}

hashTable * INIT_hashTable(hashTable * PTR, int M)
{
	if(PTR!=NULL) free(PTR);

	PTR->tableArray = (symbolList*) malloc(sizeof(symbolList) * M);
	PTR->size = M;
	PTR->freeSlots = PTR->size;
	PTR->entries = PTR->loadFactor = PTR->insertionTime = PTR->queryingTime = 0;

	return PTR;
}

void readSymbols(symbol * symbolist, int N){} // reads N symbols into symbolArray
void readQueries(symbol * querylist, int N){}
void createHashTable(hashTable * htable, long int size, long int minlaod, long int maxload, float resizeFactor){} // uses INIT_hashTable
void lookupQueries(hashTable * htable, symbol * querylist, long int querylist_size){}