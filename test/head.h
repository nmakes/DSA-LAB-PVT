#include <stdio.h>
#include <stdlib.h>

typedef struct StrStackNode
{
	char * string;
	struct StrStackNode * next;
} strStackNode;

typedef struct StrStack
{
	strStackNode * top;
	int count;
} strStack;

typedef struct StringStruct
{	
	strStack * str;
	int count;
} stringStruct;

void pushStrStack(strStack * s, char * str);
char* popStrStack(strStack * s);

int charToInt(char c);
char intToChar(int i);

void printStrings(char ** A, int N);
void printStringByChar(char * A, int N);
int stringCmp(char * a, char * b);

void readStrings(char ** A, int N, int W);

char * keyIndexedCounting(char * a, int size);

char * getArrayAtD(char ** A, int d, int N);
void writeArrayAtD(char **A, char *a, int d, int N);

void keyindex(char ** A, int lo, int hi, int d, int mode, int W);

void lsdRadixSort(char ** A, int lo, int hi, int W);