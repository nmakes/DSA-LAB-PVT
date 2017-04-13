#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	unsigned long long int size = 1;
	
	int * mem = (int*) malloc(size);
	while(mem!=NULL)
	{
		free(mem);
		size*=2;
		mem = malloc(size);
	}
	
	printf("%d", size/2);

	return 0;
}
