#include "hash.h"

SymbolList * INIT_symbolist(SymbolList * slist, long int M)
{
	if(slist->list!=NULL) free(slist);

	slist->max_size = M;
	slist->size = 0;
	slist->list = (symbol *) malloc(sizeof(symbol)*M);
	
	return slist;
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

void readSymbols(SymbolList * symbolist, int N) // reads N symbols into symbolArray
{
	int i=0;
	for (i=0; i<N; i++)
	{

	}
}

void readQueries(SymbolList * querylist, int N) {}
void createHashTable(hashTable * htable, long int size, long int minlaod, long int maxload, float resizeFactor) {} // uses INIT_hashTable
void lookupQueries(hashTable * htable, SymbolList * querylist) {}