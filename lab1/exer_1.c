#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int i;
	for(i=0; i<argc; i++)
	{
		if(argv[i]=='0')
			printf("0 ");
		else
		{
			int n = atoi(argv[i]);
			if(n!=0)
			{
				printf("%d ", n);
			}
			else
			{
				printf("%s ", argv[i]);
			}
		}
	}
	return 0;
}
