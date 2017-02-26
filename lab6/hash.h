#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR_BUFFER 30
#define MAX_SYMBOLARRAY_SIZE 100

// SYMBOL - THE BASIC DATATYPE

typedef struct _symbol
{
	char key[MAX_CHAR_BUFFER];
	char value[MAX_CHAR_BUFFER];
} symbol;

// ==========
// Symbolist - the dynamic array of symbols
// ==========

symbol symbolist[100];
int symbolist_size = 0;

void pushSymbolArray(symbol s)
{
	symbolist[symbolist_size] = s;
	symbolist_size++;
}

// ==========
// Linked list of hash records
// ==========

typedef struct _symbol_node
{
	symbol * value;
	struct _symbol_node * next;

} symbolNode;

typedef struct _symbol_linked_list
{
	symbolNode * head;
	long count;
} symbolList;

// ==========
// Hash table
// ==========

typedef struct _hash_table
{
	long int entries; // total number of symbols in the table
	long int size; // number of buckets
	float loadFactor; // entries/size
	long freeSlots; // number of empty buckets (should be equal to size in the beginning)
	long int insertionTime; // total number of jumps done in any of the lists (chains) to insert 
							// the element at the end. Increment only in case of collision.
	long int queryingTime;  // total number of comparisons done in any of the chains 
							// during all lookups.
	symbolList * tableArray;
} hashTable;

void INIT_hashTable(hashTable * PTR, int M)
{
	PTR->tableArray = (symbolList*) malloc(sizeof(symbolList) * M);
	PTR->size = M;
	PTR->freeSlots = PTR->size;
	PTR->entries = PTR->loadFactor = PTR->insertionTime = PTR->queryingTime = 0;
}

// ==========
// DRIVER FUNCTIONS
// ==========

void readSymbols(int N); // reads N symbols into symbolArray
void readQueries();
void createHashTable();
void lookupQueries();