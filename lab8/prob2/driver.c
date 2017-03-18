#include "bitvector.h"

int temp;

int main(int argc, char const *argv[])
{
	int input, j;
	unsigned int * Arr;

	do
	{
		temp = scanf("%d", &input);
		switch(input)
		{
			case 0:
			temp = scanf("%d", &j);
			Arr = CreateBitVector(Arr, j);
			break;

			case 1:
			temp = scanf("%d", &j);
			set(Arr, j);
			break;
			
			case 2:
			temp = scanf("%d", &j);
			get(Arr, j);
			break;
		}
	} while(input!=-1);

	return 0;
}