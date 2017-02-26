// driver.c

#include "hash.h"

int main(int argc, char* argv[])
{
	int input; int temp;

	do
	{
		scanf("%d", &input);

		switch(input)
		{
			case -1:
				break;

			case 0:
				scanf("%d", &temp);
				readSymbols(temp);
		}
	}
	return 0;
}