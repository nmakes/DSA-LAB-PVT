#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RECORDS 10000000

#define ull unsigned long long int

void merge(FILE* _1, FILE* _2, FILE* _3);

ull fileLength(FILE* f) // returns number of records in the file
{
	ull n = 0; int s = 0;
	while(!feof(f))
	{
		fscanf(f, "%d", &s);
		if(!feof(f))
		n++;
	}

	return n;
}

void makeSubFiles() // splits the big input file into smaller files
{
	FILE* input = fopen("input.txt", "r");
	int i=0;
	char fname[10]; int t=0; int num=0;
	FILE * temp;
	while(!feof(input) && i<10000)
	{
		sprintf(fname, "%d", i);
		temp = fopen(fname, "w");
		for(t=0; t<1000 && !feof(input); t++)
		{
			fscanf(input, "%d", &num);
			fprintf(temp, "%d\n", num);
		}
		i++;
		fclose(temp);
		printf("made%d", i);
	}

	fclose(input);
}

void insertSortArray(int n[], int size) // insert sort an array
{
	int i=0;
	int j=0;

	int temp;

	for(i=0; i<size; i++)
	{
		temp = n[i+1];
		if(temp<=n[0])
		{
			for(j=i; j>=0; j--)
			{
				n[j+1] = n[j];
			}
			n[0] = temp;
		}
		else
		{
			for(j=i; temp <= n[j]; j--)
			{
				n[j+1] = n[j];
			}
			n[j+1] = temp;
		}
	}
}

void sortFile(int n) // sort a given file and replace it with sorted file
{
	char fname[10];

	if(n==0)
	{strcpy(fname, "0");}
	else
	{sprintf(fname, "%d", n);}

	FILE* fil = fopen(fname, "r");

	//get numbers in an array
	int numbers[1000];
	int i=0;
	for(i=0; i<1000 || !feof(fil); i++)
	{
		fscanf(fil, "%d", &numbers[i]);
	}
	fclose(fil);

	//insert sort the array
	insertSortArray(numbers,i);

	//write the array back to the same file
	fil = fopen(fname, "w");
	printf("sorting%s\n", fname);
	int j;
	for(j=0; j<i-1; j++)
	{
		fprintf(fil, "%d\n", numbers[j]);
	}
	fclose(fil);
}

FILE* mergeTwoSortedFiles(int num1, int num2) // merge two sorted files
{
	char fname1[6], fname2[6];
	sprintf(fname1, "%d", num1);
	sprintf(fname2, "%d", num2);
	FILE* fil1 = fopen(fname1, "r");
	FILE* fil2 = fopen(fname2, "r");
	FILE* tmp = fopen("tmp", "w");
	int _1, _2;
	fscanf(fil1, "%d", &_1);
	fscanf(fil2, "%d", &_2);

	while(!feof(fil1) && !feof(fil2))
	{
		if(_1 <= _2)
		{
			fprintf(tmp, "%d\n", _1);
			fscanf(fil1, "%d", &_1);
		}
		else
		{
			fprintf(tmp, "%d\n", _2);
			fscanf(fil2, "%d", &_2);
		}
	}

	if(!feof(fil1))
	{
		while(!feof(fil1))
		{
			fprintf(tmp, "%d\n", _1);
			fscanf(fil1, "%d", &_1);
		}
	}
	else if(!feof(fil2))
	{
		while(!feof(fil2))
		{
			fprintf(tmp, "%d\n", _2);
			fscanf(fil2, "%d", &_2);
		}
	}

	fclose(fil1);
	fclose(fil2);
	fclose(tmp);

	tmp = fopen("tmp", "r");
	fil1 = fopen(fname1, "w");

	fscanf(tmp, "%d", &_1);

	while(!feof(tmp))
	{
		fprintf(fil1, "%d\n", _1);
		fscanf(tmp, "%d", &_1);
	}

	fclose(fil1);
	fclose(tmp);
	remove(fname2);
}

void deleteAllFiles()
{
	char fname[6];
	int i;
	for(i=0; i<=9999; i++)
	{
		sprintf(fname, "%d", i);
		remove(fname);
	}
}

int main(int argc, char* argv[])
{
	
	// break the file into smaller files
	//makeSubFiles();

	// sort files
	/*int i;
	for(i=0; i<=9999; i++)
	{
		sortFile(i);
	}*/

	// merge the files into a single file
	//mergeTwoSortedFiles(0,1);
	

	deleteAllFiles();

	return 0;
}
