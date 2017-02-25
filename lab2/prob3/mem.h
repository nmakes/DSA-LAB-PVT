#include <stdlib.h>

struct heapAllocs_records
{
    void* pointer = NULL;
    int size = 0;
};

struct heapAllocs_records heapAllocs;

void addRecord(struct heapAllocs_records * ha)
{
    ha->pointer = realloc(ha->pointer,++(ha->size));
}

int maxHeapSize = 0;
int curHeapSize = 0;

void* myAlloc(unsigned int s)
{
	void * ptr = malloc(s);
    heapAllocs

}
