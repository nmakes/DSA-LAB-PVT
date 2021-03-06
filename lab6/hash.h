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

typedef struct 
{
	symbol * list;
	long int size;
} SymbolList;

// Symbolist - the dynamic array of symbols
SymbolList * INIT_symbolist(SymbolList *, long int M);

// Linked list of hash records
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

hashTable * INIT_hashTable(hashTable * PTR, int M);

// ==========
// DRIVER FUNCTIONS
// ==========

SymbolList * readSymbols(SymbolList * symbolist, int N); // reads N symbols into symbolArray
SymbolList * readQueries(SymbolList * querylist, int N);
hashTable * createHashTable(hashTable * htable, 
							SymbolList * symbolist, 
							long int size, 
							long int minlaod, 
							long int maxload, 
							float resizeFactor); // uses INIT_hashTable
void lookupQueries(hashTable * htable, SymbolList * querylist);