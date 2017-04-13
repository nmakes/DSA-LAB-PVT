#include "head.h"

int tempFF;

int charToInt(char c)
{
	return c - 'a';
}

char intToChar(int i)
{
	return i + 'a';
}

void readStrings(char **A, int N, int W)
{

	/*A = (char**) malloc(sizeof(char*) * N);*/
	int i;
	for(i=0; i<N; i++)
	{
		/*A[i] = (char*) malloc(sizeof(char) * (W+1));*/
		tempFF = scanf("%s", A[i]);
	}
}

void printStrings(char ** A, int N)
{
	int i=0;
	for(i=0; i<N; i++)
	{
		printf("%s\n", A[i]);
	}
}

void printStringByChar(char * A, int N)
{
	int i=0;
	for(i=0; i<N; i++)
	{
		printf("%c\n", A[i]);
	}
}

void printarr(int * a, int n)
{
	int i=0; 
	for(i=0; i<n; i++)
	{
		printf("!%d ", a[i]);
	}
	printf("\n");
}

char * keyIndexedCounting(char * a, int size)
{
	int letters[26];
	int cumulative[26];
	int i = 0;
	int count = 0;

	// init letters array
	for(i=0; i<26; i++)
	{
		letters[i] = 0;
		cumulative[i] = 0;
	}

	// printarr(letters, 26);

	// get letter count
	for(i = 0; i<size; i++)
	{
		letters[charToInt(a[i])]++;
	}

	// printarr(letters, 26);

	// cumulative
	for(i=0; i<26; i++)
	{
		cumulative[i] = letters[i];
	}

	for(i=0; i<25; i++)
	{
		cumulative[i+1] += cumulative[i];
	}

	// printarr(letters, 26);
	// printarr(cumulative, 26);

	//making array
	char * final = (char*) malloc(sizeof(char)*(size+1));
	int pos = 0;

	for(i=0; i<26; i++)
	{
		pos = cumulative[i]-1;
		while(letters[i]!=0)
		{
			final[pos] = intToChar(i);
			pos--;
			letters[i]--;
		}
	}
	final[size] = '\0';
	return final;
}

char * getArrayAtD(char ** A, int d, int N)
{
	int i=0;
	char * ret = (char*) malloc(sizeof(char)*(N+1));

	for(i=0; i<N; i++)
	{
		ret[i] = A[i][d];
	}

	ret[N] = '\0';

	return ret;
}

void writeArrayAtD(char **A, char *a, int d, int N)
{
	int i = 0;
	for(i=0; i<N; i++)
	{
		A[i][d] = a[i];
	}
}

void swapStrings(char ** a, char ** b)
{
	char * temp = *(a);
	*(a) = *(b);
	*(b) = temp;
}

int stringCmp(char * a, char * b)
{
	int i=0;
	while(a[i]==b[i] && a[i]!='\0' && b[i]!='\0')
	{
		i++;
	}
	
	return a[i]-b[i];
}

void keyindex(char ** A, int lo, int hi, int d, int mode, int W) // d is the dth char
{
	// mode == 1 for question 1 part 2
	// mode == 2 for lsdRadixSort ( question 1 part 3 )
	if(mode==1)
	{
		int N = hi-lo + 1;
		char * temp = getArrayAtD(A, d, N);
		// printf("---%s\n", temp);
		temp = keyIndexedCounting(temp, N);
		// printf("---%s\n", temp);
		printStringByChar(temp, N);
		// printf("---%s\n", temp);	
	}
	else	// this will receive d = -1 and mode = 2 from lsdRadixSort
	{
		int N = hi-lo+1;
		for(d = W-1; d>=0; d++)
		{
			int i = 0;
			stringStruct strings[26];
			stringStruct cumulative[26];
		
			// init strings array
			for(i=0; i<26; i++)
			{
				strings[i].str = NULL;
				strings[i].count = 0;
				cumulative[i].str = NULL;
				cumulative[i].count = 0;
			}

			// get string count based on the character selected
			for(i = 0; i<N; i++)
			{
				strings[charToInt(A[i][d])].count++;
				pushStrStack(strings[charToInt(A[i][d])].str, A[i]);
			}

			// get cumulative count
			for(i=0; i<26; i++)
			{
				cumulative[i].str = strings[i].str;
				cumulative[i].count = strings[i].count;
			}

			for(i=0; i<25; i++)
			{
				cumulative[i+1].count = cumulative[i].count;
			}

			// write to the array
			for(i=0; i<26; i++)
			{
				int pos = cumulative[i].count - 1;
				while(strings[i].count!=0)
				{
					A[pos] = popStrStack(strings[i].str);
					pos--;
					strings[i].count--;
				}
			}
		}
	}
}

void pushStrStack(strStack * s, char * str)
{
	strStackNode * node = (strStackNode*) malloc(sizeof(strStackNode));
	node -> string = str;
	node -> next = s->top;

	if(s->top == NULL)
	{
		s->top = node;
		s->count++;
	}
	else
	{
		s -> top = node;
		s -> count++;
	}
}

char * popStrStack(strStack * s)
{
	if(s->count!=0)
	{
		char * temp = s->top->string;
		strStackNode * node = s->top;
		s->top = node -> next;
		free(node);
		return temp;
	}
	else
	{
		printf("ERROR! NO ELEMENT IN STRSTACK\n");
		return NULL;
	}
}

void lsdRadixSort(char ** A, int lo, int hi, int W)
{
	keyindex(A, lo, hi, -1, 2, W);
}