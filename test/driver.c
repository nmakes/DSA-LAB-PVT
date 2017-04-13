#include "head.h"

int tempF;
const int maxW = 32;

int main(int argc, char const *argv[])
{
	/*
	char * a = "asopgjaijg";
	printf("%s", keyIndexedCounting(a, sizeof(char)*10));
	*/

	int input;

	int N, W, d;

	char ** A;
	int i=0;
	char * temp;
	do
	{
		tempF = scanf("%d", &input);

		switch(input)
		{
			case 1:	// works
				tempF = scanf("%d %d", &N, &W);
				A = (char**) malloc(sizeof(char*) * N);
				for(i=0; i<N; i++)
				{
					A[i] = (char*) malloc(sizeof(char) * (W+1));
				}
				readStrings(A, N, W);
				// printStrings(A,N);
				break;

			case 2:	// works
				tempF = scanf("%d", &d);
				keyindex(A, 0, N-1, d, 1, -1);
				break;

			case 3:	// unfinished
				lsdRadixSort(A, 0, N-1, W);
				for(i=0; i<N; i++)
				{
					printf("%s", A[i]);
				}
				
				break;

			case -1:
			return 0;

		}
	} while(input!=-1);

	return 0;
}