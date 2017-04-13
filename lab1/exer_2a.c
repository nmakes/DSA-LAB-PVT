#include <stdio.h>

int main(int argc, char* argv[])
{
	// ./copyf src dst
	
	if(argc!=3)
	{
		printf("Usage: ./copyf src dst\n");
	}

	FILE * src = fopen(argv[1], "r");
	FILE * dst = fopen(argv[2], "w+");

	if(src==NULL)
	{
		printf("Error: Could not open source file %s", argv[1]);
	}
	else if(dst==NULL)
	{
		printf("Error: Could not create destination file %s", argv[2]);
	}
	else
	{
		char c;
		while(!feof(src))
		{
			c = fgetc(src);
			fputc(c, dst);
		}
	}

	fclose(src);
	fclose(dst);
	return 0;
}
