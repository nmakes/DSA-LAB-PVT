#include <stdio.h>

int main(int argc, char* argv[])
{
	// ./copyf src dst

	FILE *src, *dst;

	if(!(argc==2 || argc==3))
	{
		printf("Usage: ./copyf src (dst)\n");
	}

	if(argc==2)
	{
		src = fopen(argv[1], "r");
		dst = stdout;
	}
	else
	{
		src = fopen(argv[1], "r");
		dst = fopen(argv[2], "w+");
	}

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
			fputc(c, dst);
			c = fgetc(src);
		}
	}

	fclose(src);
	fclose(dst);
	return 0;
}
