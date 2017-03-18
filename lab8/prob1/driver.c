#include "bitvector.h"

int temp;

int main(int argc, char const *argv[])
{
	int input, j;
	unsigned int * S;

	do
	{
		temp = scanf("%d", &input);
		switch(input)
		{
			case 0:
			S = CreateBitVector(S);
			break;

			case 1:
			temp = scanf("%d", &j);
			set(S, j);
			break;
			
			case 2:
			temp = scanf("%d", &j);
			get(S, j);
			break;
		}
	} while(input!=-1);

	return 0;
}