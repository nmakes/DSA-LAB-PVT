#include "bst.h"

int main(int argc, char* argv[])
{
	BST * root = NULL;
	int * array;
	int input, N, k, k1, k2, temp;

	do
	{
		temp = scanf("%d", &input);

		switch(input)
		{
			case 0:
			temp = scanf("%d", &N);
			array = readData(array, N);
			break;

			case 1:
			temp = scanf("%d", &k);
			root = add(root, k);
			break;

			case 2:
			root = construct(root, array, N);
			break;

			case 3:
			inOrderTravRec(root);
			printf("\n");
			break;

			case 4:
			inOrderTravIter(root);
			printf("\n");
			break;

			case 5:
			temp = scanf("%d", &k);
			findKthSmallest(root, k);
			break;

			case 6:
			temp = scanf("%d %d", &k1, &k2);
			findBetweenKeys(root, k1, k2);
			break;
		}
	} while(input!=-1);

	return 0;
}