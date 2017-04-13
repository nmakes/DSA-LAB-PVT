#include <stdio.h>
#include <stdlib.h>

typedef struct Record
{
	char name[32];
	long int id;
} record;

typedef struct HashNode
{
	record * current;
	struct HashNode * next;
} hashNode;

typedef struct HashTableElement
{
	hashNode * head;
	// int count; 
} hashTableElement;

typedef struct HashTable
{
	int elementCount;
	float loadFactor;
	unsigned long int insertionTime;
	unsigned long int queryingTime;
	hashTableElement * table;
	int tableLength;
} hashTable;

hashTable * INIT_hashTable(hashTable * ht);

void readRecords(int N, record * p, hashTable ** ht);
void readQueries(int N, record * queries, hashTable ** ht);