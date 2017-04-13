#include <stdio.h>

int main(int argc, char * v[])
{
	FILE * fp;

	fp = fopen("abc.t", "w");

	fprintf(fp, "aoioigah oas giwa g0g 20wg \niw hgihag09wg0g");

	fclose(fp);

	char str[1000];

	fp = fopen("abc.t", "r");

	fscanf(fp, "%s", str);

	printf("%s", str);

	fclose(fp);

	return 0;
}