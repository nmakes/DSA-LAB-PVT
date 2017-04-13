#include "hash.h"

int strcmp(char * a,char * b)
{
	int i=-1;

	do
	{
		i++;
		if(a[i]!=b[i])
			return a[i]-b[i];
		else
			continue;
	} while((a[i]==b[i]) && (a[i]!='\0' && b[i]!='\0'));
}

hashTable * INIT_hashTable(hashTable * ht)
{
	ht = (hashTable*) malloc(sizeof(hashTable));

	ht->elementCount = 0;
	ht->loadFactor = 0;
	ht->insertionTime = 0;
	ht->queryingTime = 0;
	ht->table = NULL;
	ht->tableLength = 0;

	return ht;
}

int h(record * r, int opt)		//hashing function
{
	int h=0, i=0;
	int hashMod;
	int tableLength;

	switch(opt)
	{
		case 1:
		hashMod = 89;
		tableLength = 20;
		break;

		case 2:
		hashMod = 105943;
		tableLength = 20;
		break;

		case 3:
		hashMod = 89;
		tableLength = 200;
		break;

		case 4:
		hashMod = 105943;
		tableLength = 200;
		break;

		case 5:
		hashMod = 89;
		tableLength = 20;
		break;

		case 6:
		hashMod = 105943;
		tableLength = 20;
		break;

		case 7:
		hashMod = 89;
		tableLength = 200;
		break;

		case 8:
		hashMod = 105943;
		tableLength = 200;
		break;
	}
	if(opt==5 || opt==6 || opt==7 || opt==8)
	{
		for(;i<8; i++)
		{
			h += (int)r->name[i];
		}
	}
	else
	{
		h=r->id;
	}

	return (h%hashMod)%tableLength;
}

hashTable * createTable(hashTable * ht, int opt)
{
	ht = INIT_hashTable(ht);

	if(opt==1 || opt==2 || opt==5 || opt==6)
	{
		ht->tableLength = 20;
		ht->table = (hashTableElement*) malloc(sizeof(hashTableElement)*20);
	}
	else if(opt==3 || opt==4 || opt==7 || opt==8)
	{
		ht->tableLength = 200;
		ht->table = (hashTableElement*) malloc(sizeof(hashTableElement)*200);
	}

	return ht;
}

void insertIntoList(hashTable *ht, record * r, int opt)
{
	int hash = h(r, opt);

	hashNode * inNode = (hashNode*) malloc(sizeof(hashNode));
	inNode -> current = r;
	inNode -> next = NULL;

	hashNode * mov = ht->table[hash].head;

	if(mov==NULL)
	{
		mov = inNode;
	}
	else
	{
		while(mov->next!=NULL)
		{
			mov = mov->next;
			ht->insertionTime++;
		}
		mov->next = inNode;
	}
}

void insertIntoTable(record * r, hashTable * ht, int opt)
{
	insertIntoList(ht, r, opt);
	ht-> elementCount++;
	ht-> loadFactor = (float) ht->elementCount / ht->tableLength;
}

void readRecords(int N, record * records, hashTable * ht[8])
{
	int i, j;
	records=(record *)malloc( sizeof(record)*N);

	for (i=0;i<N;i++)
	{
		scanf("%s %ld",records[i].name, &records[i].id);
	}

	// todo:

	for(i=0; i<=7; i++)
	{
		ht[i] = createTable(ht[i], i+1);

		for(j=0; j<N; j++)
		{
			insertIntoTable(&records[j], ht[i], i+1);
		}
	}
}

record * find(record* query, hashTable ** ht, int Nopt) // Nopt==8
{
	int opt = 1;
	int hash;
	hashNode * mov = NULL;

	for(opt = 1; opt <= Nopt; opt++)
	{
		hash = h(query, opt);
		mov = ht[opt-1]->table[hash].head;
		ht[opt-1]->queryingTime++;
		while(mov!=NULL)
		{
			ht[opt-1]->queryingTime += 2;
			if(mov->current->id != query->id || !strcmp(mov->current->name, query->name))
			{
				mov = mov->next;
			}
			else
			{
				return mov->current;
			}
		}
	}
}

void readQueries(int N, record * queries, hashTable ** ht)
{
	int i, j;
	queries=(record *)malloc( sizeof(record)*N);

	for (i=0;i<N;i++)
	{
		scanf("%s %ld",queries[i].name, &queries[i].id);
		find(&queries[i], ht, 8);
	}
}