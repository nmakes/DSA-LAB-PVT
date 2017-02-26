#include "hash.h"

SymbolList * INIT_symbolist(SymbolList * slist, long int M)
{
	slist->size = 0;
	slist->list = (symbol *) malloc(sizeof(symbol)*M);
	
	return slist;
}

hashTable * INIT_hashTable(hashTable * PTR, int M)
{
	PTR->tableArray = (symbolList*) malloc(sizeof(symbolList) * M);
	PTR->size = M;
	PTR->freeSlots = PTR->size;
	PTR->entries = PTR->loadFactor = PTR->insertionTime = PTR->queryingTime = 0;

	return PTR;
}

SymbolList * readSymbols(SymbolList * symbolist, int N) // reads N symbols into symbolArray
{
	int i=0;
	INIT_symbolist(symbolist, N);

	for (i=0; i<N; i++)
	{
		scanf("%s %s", (symbolist->list[i].key), (symbolist->list[i].value) );
		symbolist->size++;
	}

	return symbolist;
}

SymbolList * readQueries(SymbolList * querylist, int N)
{
	int i=0;
	INIT_symbolist(querylist, N);

	for (i=0; i<N; i++)
	{
		scanf("%s %s", (querylist->list[i].key), (querylist->list[i].value) );
		querylist->size++;
	}

	return querylist;
}

hashTable * createHashTable(hashTable * htable,  SymbolList * symbolist, long int size, long int minlaod, long int maxload, float resizeFactor) // uses INIT_hashTable
{
	htable = INIT_hashTable(htable, size);

	

	/*
	PSEUDO CODES

	ALGORITHM - CREATEHASHTABLE
	--
	H = createEmptyHashTable(size)
	for (sym in symbolist)
		H = insert(H, sym)
		if (H.loadFactor > maxLoad)
			newSize = H.size * resizeFactor
			Hnew = createEmptyHashTable(newSize)
			Hnew.insertionTime = H.insetionTime
			Hnew = reinsert all symbols in H into Hnew
			delete(H)
			H = Hnew i.e. do remaining insertions in Hnew
		if (H.loadFactor < maxLoad)
			newSize = H.size / resizeFactor
			Hnew = createEmptyHashTable(newSize)
			Hnew.insertionTime = H.insetionTime
			Hnew = reinsert all symbols in H into Hnew
			delete(H)
			H = Hnew
		PrintTabSeparated(H.entries,H.size,H.loadFactor,H.freeSlots, H.insertionTime)

	
	ALGORITHM - INSERT
	--
	H.entries = H.entries + 1
	index = hashingFunction (s)
	if (isSlotEmpty (index))
		H.freeSlots = H.freeSlots – 1
	t = insertSymbol(index, s)
	H.insertionTime = H.insertionTime + t
	H.loadFactor = H.entries / H.size	
	*/

	return htable;
}

void lookupQueries(hashTable * htable, SymbolList * querylist) {}