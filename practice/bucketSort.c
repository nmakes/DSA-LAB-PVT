#include "bucketSort.h"

void readdata(int  a[100][2], int M)
{
	int i=0, j=0;
	for(i=0;i<M;i++)
	{
		scanf("%d %d",&a[i][0],&a[i][1]);
		printf("%d %d\n",a[i][0],a[i][1]);
	}
}

void SortSparseLists(dataList * a, int lo, int hi)
{
	;
}

int main(int argc, char* ar[])
{
	int pt[100][2];
	int m;

	readdata(pt,10);
	
	SortSparseLists(pt, 0, );
}